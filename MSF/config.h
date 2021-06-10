#ifndef __MSF_CONFIG_H__
#define __MSF_CONFIG_H__

#include <memory>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "log.h"
#include <yaml-cpp/yaml.h>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>

namespace MSF {

class ConfigVarBase {
public:
	typedef std::shared_ptr<ConfigVarBase> ptr;
	ConfigVarBase(const std::string& name, const std::string& description = "")
		:m_name(name)
		,m_description(description) {
		std::transform(m_name.begin(), m_name.end(), m_name.begin(), ::tolower);
	}
	virtual ~ConfigVarBase() {}

	const std::string& getName() const { return m_name;}
	const std::string& getDescription() const { return m_description;}

	virtual std::string toString() = 0;
	virtual bool fromString(const std::string& val) = 0;
	virtual std::string getTypeName() const = 0;
protected:
	std::string m_name;
	std::string m_description;
};

//F from_type;T to_type
template<class F, class T>
class LexicalCast {
public:
	T operator()(const F& v){
		return boost::lexical_cast<T>(v);
	}
private:

};

//上述转化只能作用于基本类型，但是容器这种就没法使用
//所以针对容器做特型化
//vector -> string
template<class T>
class LexicalCast<std::string, std::vector<T> > {
public:
	std::vector<T> operator()(const std::string& v) {
		YAML::Node node = YAML::Load(v);
		typename std::vector<T> vec;//模板在实例化之前并不知道std::vector<T>是个什么东西，使用typename可以确定定义;
		std::stringstream ss;
		for(size_t i = 0; i < node.size(); ++i) {
			ss.str("");
			ss << node[i];
			vec.push_back(LexicalCast<std::string, T>()(ss.str()));
		}
		return vec;
	}
};

//string -> vector
template<class T>
class LexicalCast<std::vector<T>, std::string> {
public:
	std::string operator()(const std::vector<T>& v) {
		YAML::Node node(YAML::NodeType::Sequence);
		for(auto& i : v) {
			node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
		}
		std::stringstream ss;
		ss << node;
		return ss.str();
	}
};

//类型转换模板类片特化(YAML String 转换成 std::list<T>)
template<class T>
class LexicalCast<std::string, std::list<T> > {
public:
    std::list<T> operator()(const std::string& v) {
        YAML::Node node = YAML::Load(v);
        typename std::list<T> vec;
        std::stringstream ss;
        for(size_t i = 0; i < node.size(); ++i) {
            ss.str("");
            ss << node[i];
            vec.push_back(LexicalCast<std::string, T>()(ss.str()));
        }
        return vec;
    }
};

//类型转换模板类片特化(std::list<T> 转换成 YAML String)
template<class T>
class LexicalCast<std::list<T>, std::string> {
public:
    std::string operator()(const std::list<T>& v) {
        YAML::Node node(YAML::NodeType::Sequence);
        for(auto& i : v) {
            node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
        }
        std::stringstream ss;
        ss << node;
        return ss.str();
    }
};

//类型转换模板类片特化(YAML String 转换成 std::set<T>)
template<class T>
class LexicalCast<std::string, std::set<T> > {
public:
    std::set<T> operator()(const std::string& v) {
        YAML::Node node = YAML::Load(v);
        typename std::set<T> vec;
        std::stringstream ss;
        for(size_t i = 0; i < node.size(); ++i) {
            ss.str("");
            ss << node[i];
            vec.insert(LexicalCast<std::string, T>()(ss.str()));
        }
        return vec;
    }
};

//类型转换模板类片特化(std::set<T> 转换成 YAML String)
template<class T>
class LexicalCast<std::set<T>, std::string> {
public:
    std::string operator()(const std::set<T>& v) {
        YAML::Node node(YAML::NodeType::Sequence);
        for(auto& i : v) {
            node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
        }
        std::stringstream ss;
        ss << node;
        return ss.str();
    }
};

//类型转换模板类片特化(YAML String 转换成 std::unordered_set<T>)
template<class T>
class LexicalCast<std::string, std::unordered_set<T> > {
public:
    std::unordered_set<T> operator()(const std::string& v) {
        YAML::Node node = YAML::Load(v);
        typename std::unordered_set<T> vec;
        std::stringstream ss;
        for(size_t i = 0; i < node.size(); ++i) {
            ss.str("");
            ss << node[i];
            vec.insert(LexicalCast<std::string, T>()(ss.str()));
        }
        return vec;
    }
};

//类型转换模板类片特化(std::unordered_set<T> 转换成 YAML String)
template<class T>
class LexicalCast<std::unordered_set<T>, std::string> {
public:
    std::string operator()(const std::unordered_set<T>& v) {
        YAML::Node node(YAML::NodeType::Sequence);
        for(auto& i : v) {
            node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
        }
        std::stringstream ss;
        ss << node;
        return ss.str();
    }
};

//类型转换模板类片特化(YAML String 转换成 std::map<std::string, T>)
template<class T>
class LexicalCast<std::string, std::map<std::string, T> > {
public:
    std::map<std::string, T> operator()(const std::string& v) {
        YAML::Node node = YAML::Load(v);
        typename std::map<std::string, T> vec;
        std::stringstream ss;
        for(auto it = node.begin();
                it != node.end(); ++it) {
            ss.str("");
            ss << it->second;
            vec.insert(std::make_pair(it->first.Scalar(),
                        LexicalCast<std::string, T>()(ss.str())));
        }
        return vec;
    }
};

//类型转换模板类片特化(std::map<std::string, T> 转换成 YAML String)
template<class T>
class LexicalCast<std::map<std::string, T>, std::string> {
public:
    std::string operator()(const std::map<std::string, T>& v) {
        YAML::Node node(YAML::NodeType::Map);
        for(auto& i : v) {
            node[i.first] = YAML::Load(LexicalCast<T, std::string>()(i.second));
        }
        std::stringstream ss;
        ss << node;
        return ss.str();
    }
};

//类型转换模板类片特化(YAML String 转换成 std::unordered_map<std::string, T>)
template<class T>
class LexicalCast<std::string, std::unordered_map<std::string, T> > {
public:
    std::unordered_map<std::string, T> operator()(const std::string& v) {
        YAML::Node node = YAML::Load(v);
        typename std::unordered_map<std::string, T> vec;
        std::stringstream ss;
        for(auto it = node.begin();
                it != node.end(); ++it) {
            ss.str("");
            ss << it->second;
            vec.insert(std::make_pair(it->first.Scalar(),
                        LexicalCast<std::string, T>()(ss.str())));
        }
        return vec;
    }
};

//类型转换模板类片特化(std::unordered_map<std::string, T> 转换成 YAML String)
template<class T>
class LexicalCast<std::unordered_map<std::string, T>, std::string> {
public:
    std::string operator()(const std::unordered_map<std::string, T>& v) {
        YAML::Node node(YAML::NodeType::Map);
        for(auto& i : v) {
            node[i.first] = YAML::Load(LexicalCast<T, std::string>()(i.second));
        }
        std::stringstream ss;
        ss << node;
        return ss.str();
    }
};

//FromStr T operator()(const std::string&)ML String 转换成 std::list<T>)
//ToStr std::string operator()(const T&)
//就是把自定义类型写成string，或者string转化为自定义类型
//FiomStr,ToStr是basic的，也就是LexicalCast的特例化类
template<class T, class FromStr = LexicalCast<std::string ,T>
				,class ToStr = LexicalCast<T, std::string> >
class ConfigVar : public ConfigVarBase {
public:
	typedef std::shared_ptr<ConfigVar> ptr;
	typedef std::function<void (const T& old_value, const T& new_value)> on_change_cb;

	ConfigVar(const std::string& name
			,const T& default_value
			,const std::string& description = "")
		:ConfigVarBase(name,description)
		,m_val(default_value) {
	}

	std::string toString() override { 
		try {
			//return boost::lexical_cast<std::string>(m_val);//这个是转化基本类型的；
			return ToStr()(m_val);
		}
		catch (std::exception& e) {
			MSF_LOG_ERROR(MSF_LOG_ROOT()) << "ConfigVar::toString exception"
				<< e.what() << " convert: " << typeid(m_val).name() << " to string";
		}
		return "";
	}
	bool fromString(const std::string& val) override {
		try {
			//m_val = boost::lexical_cast<T>(m_val);//这个是转化基本类型的
			setValue(FromStr()(val));
		}
		catch (std::exception& e) {
			MSF_LOG_ERROR(MSF_LOG_ROOT()) << "ConfigVar::toString exception"
				<< e.what() << " convert: string to " << typeid(m_val).name();
		}
		return false;
	}

	const T getValue() const { return m_val;}
	void setValue(const T& v) {
		if(v == m_val) {
			return;
		}
		for(auto& i : m_cbs) {
			i.second(m_val, v);
		}
		m_val = v;
	}
	std::string getTypeName() const override { return typeid(T).name();}

	void addListener(uint64_t key, on_change_cb cb) {
		m_cbs[key] = cb;
	}
	void delListener(uint64_t key) {
		m_cbs.erase(key);
	}
	on_change_cb getListener(uint64_t key) {
		auto it = m_cbs.find(key);
		return it == m_cbs.end() ? nullptr : it->second;
	}
	void clearListener() {
		m_cbs.clear();
	}
private:
	T m_val;
	//变更回调函数组，由于function是不带比较函数的，所以外围加一个map来知道这是哪一个function；
	//uin64_t， key， hash
	std::map<uint64_t, on_change_cb> m_cbs;
};

class Config {
public:
	typedef std::map<std::string, ConfigVarBase::ptr> ConfigVarMap;

	template<class T>
	static typename ConfigVar<T>::ptr Lookup(const std::string& name,
			const T& default_value, const std::string& description = "") {
		auto it = GetDatas().find(name);
		if(it != GetDatas().end()) {
			auto tmp = std::dynamic_pointer_cast<ConfigVar<T> >(it->second);
			if(tmp) {
				MSF_LOG_INFO(MSF_LOG_ROOT()) << "Lookup name =" << name << " exists";
				return tmp;
			}
			else {
				MSF_LOG_ERROR(MSF_LOG_ROOT()) << "Lookup name= " << name << " exisrs but type not "
					<< typeid(T).name() << " real_type= " << it->second->getTypeName()
					<< it->second->toString();
				return nullptr;
			}
		}

		if(name.find_first_not_of("abcdefghijklmnopqrstuvwxyz._0123456789")
			!= std::string::npos) {
			MSF_LOG_ERROR(MSF_LOG_ROOT()) << "Lookup name invalid " << name;
			throw std::invalid_argument(name);
		}

		typename ConfigVar<T>::ptr v(new ConfigVar<T>(name, default_value, description));
		GetDatas()[name] = v;
		return v;
	}

	template<class T>
	static typename ConfigVar<T>::ptr Lookup(const std::string& name) {
		auto it = GetDatas().find(name);
		if(it == GetDatas().end())
			return nullptr;
		return std::dynamic_pointer_cast<ConfigVar<T> >(it->second);
	}

	static void LoadFromYaml(const YAML::Node& root);

	static ConfigVarBase::ptr LookupBase(const std::string& name);
private:

	static ConfigVarMap& GetDatas() {
		static ConfigVarMap s_datas;
		return s_datas;
	}
};

}

#endif

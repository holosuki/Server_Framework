#include "../MSF/config.h"
#include "../MSF/log.h"
#include <yaml-cpp/yaml.h> 
#include <iostream>

MSF::ConfigVar<int>::ptr g_int_value_config =
	MSF::Config::Lookup("system.port", (int)8080, "system port");

MSF::ConfigVar<float>::ptr g_float_value_config =
	MSF::Config::Lookup("system.value", (float)10.2f, "system value");

MSF::ConfigVar<std::vector<int> >::ptr g_int_vec_value_config =
	MSF::Config::Lookup("system.int_vec", std::vector<int>{1,2}, "system int vec");

MSF::ConfigVar<std::list<int> >::ptr g_int_list_value_config =
    MSF::Config::Lookup("system.int_list", std::list<int>{1,2}, "system int list");

MSF::ConfigVar<std::set<int> >::ptr g_int_set_value_config =
    MSF::Config::Lookup("system.int_set", std::set<int>{1,2}, "system int set");

MSF::ConfigVar<std::unordered_set<int> >::ptr g_int_uset_value_config =
    MSF::Config::Lookup("system.int_uset", std::unordered_set<int>{1,2}, "system int uset");

MSF::ConfigVar<std::map<std::string, int> >::ptr g_str_int_map_value_config =
    MSF::Config::Lookup("system.str_int_map", std::map<std::string, int>{{"k",2}}, "system str int map");

MSF::ConfigVar<std::unordered_map<std::string, int> >::ptr g_str_int_umap_value_config =
    MSF::Config::Lookup("system.str_int_umap", std::unordered_map<std::string, int>{{"k",2}}, "system str int map");

void printf_yaml(const YAML::Node& node, int level) {
	if(node.IsScalar()) {
		MSF_LOG_INFO(MSF_LOG_ROOT()) << std::string(level * 4, ' ')
			<< node.Scalar() << " - " << node.Type() << " - " << level;
	}else if(node.IsNull()) {
		MSF_LOG_INFO(MSF_LOG_ROOT()) << std::string(level * 4, ' ')
			<< "NULL - " << node.Type() << " - " << level;	
	}else if(node.IsMap()) {
		for(auto it = node.begin();
				it != node.end(); ++it) {
			MSF_LOG_INFO(MSF_LOG_ROOT()) << std::string(level * 4, ' ')
				<< it->first << " - " << node.Type() << " - " << level;
			printf_yaml(it->second, level + 1);
		}
	}else if(node.IsSequence()) {
		for(size_t i = 0; i < node.size(); ++i) {
			MSF_LOG_INFO(MSF_LOG_ROOT()) << std::string(level * 4, ' ')
				<< i<< " - " << node[i].Type() << " - " << level;
			printf_yaml(node[i], level + 1);
		}
	}
}

void test_yaml() {
	YAML::Node root = YAML::LoadFile("/home/holo/git/Server_Framework/bin/conf/log.yml");
	printf_yaml(root, 0);
	MSF_LOG_INFO(MSF_LOG_ROOT()) << root.Scalar();
}

void test_config() {
	//YAML::Node root = YAML::LoadFile("/home/holo/git/Server_Framework/bin/conf/log.yml");
	MSF_LOG_INFO(MSF_LOG_ROOT()) << " before: "  << g_int_value_config->getValue();
	MSF_LOG_INFO(MSF_LOG_ROOT()) << " before: "  << g_float_value_config->toString();

#define XX(g_var, name, prefix) \
	{ \
		auto& v = g_var->getValue(); \
        for(auto& i : v) { \
            MSF_LOG_INFO(MSF_LOG_ROOT()) << #prefix " " #name ": " << i; \
        } \
        MSF_LOG_INFO(MSF_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString(); \
    }

#define XX_M(g_var, name, prefix) \
    { \
        auto& v = g_var->getValue(); \
        for(auto& i : v) { \
            MSF_LOG_INFO(MSF_LOG_ROOT()) << #prefix " " #name ": {" \
                    << i.first << " - " << i.second << "}"; \
        } \
        MSF_LOG_INFO(MSF_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString(); \
    }


    XX(g_int_vec_value_config, int_vec, before);
    XX(g_int_list_value_config, int_list, before);
    XX(g_int_set_value_config, int_set, before);
    XX(g_int_uset_value_config, int_uset, before);
    XX_M(g_str_int_map_value_config, str_int_map, before);
    XX_M(g_str_int_umap_value_config, str_int_umap, before);

    YAML::Node root = YAML::LoadFile("/home/holo/git/Server_Framework/bin/conf/log.yml");
    MSF::Config::LoadFromYaml(root);

    MSF_LOG_INFO(MSF_LOG_ROOT()) << "after: " << g_int_value_config->getValue();
    MSF_LOG_INFO(MSF_LOG_ROOT()) << "after: " << g_float_value_config->toString();

    XX(g_int_vec_value_config, int_vec, after);
    XX(g_int_list_value_config, int_list, after);
    XX(g_int_set_value_config, int_set, after);
    XX(g_int_uset_value_config, int_uset, after);
    XX_M(g_str_int_map_value_config, str_int_map, after);
    XX_M(g_str_int_umap_value_config, str_int_umap, after);
}

int main(int argc, char** argv) {
	//test_yaml();
	test_config();
	return 0;
}
#include "../MSF/config.h"
#include "../MSF/log.h"
#include <yaml-cpp/yaml.h> 

MSF::ConfigVar<int>::ptr g_int_value_config =
	MSF::Config::Lookup("system.port", (int)8080, "system port");

MSF::ConfigVar<float>::ptr g_float_value_config =
	MSF::Config::Lookup("system.value", (float)10.2f, "system value");

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
	MSF_LOG_INFO(MSF_LOG_ROOT()) << root;
}

void test_config() {
	//YAML::Node root = YAML::LoadFile("/home/holo/git/Server_Framework/bin/conf/log.yml");
	MSF_LOG_INFO(MSF_LOG_ROOT()) << " before: "  << g_int_value_config->getValue();
	MSF_LOG_INFO(MSF_LOG_ROOT()) << " before: "  << g_float_value_config->toString();

	YAML::Node root = YAML::LoadFile("/home/holo/git/Server_Framework/bin/conf/log.yml");
	MSF_LOG_INFO(MSF_LOG_ROOT()) << root;
	MSF::Config::LoadFromYaml(root);

	MSF_LOG_INFO(MSF_LOG_ROOT()) << " after: " << g_int_value_config->getValue();
	MSF_LOG_INFO(MSF_LOG_ROOT()) << " after: " << g_float_value_config->toString();
}

int main(int argc, char** argv) {
//	test_yaml();
	test_config();
	return 0;
}

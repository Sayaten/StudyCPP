#include <iostream>
#include <ext/hash_map>
#include <string>

int main()
{
	__gnu_cxx::hash_map<std::string, int> map;
	//__gnu_cxx::hash_map<std::String, int>::iterator iter = map.begin();
	

	map.insert(__gnu_cxx::hash_map<std::string, int>::value_type(std::string("a"), 20));

	std::cout << map[std::string("a")] << std::endl;

	return 0;
}

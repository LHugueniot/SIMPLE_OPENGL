#include "Utilities.h"

std::string readFile(std::string_view filePath){
	std::ifstream fileStream(filePath.c_str());
	std::string contents(std::istreambuf_iterator<char>(t),
		std::istreambuf_iterator<char>());
	return string;
}
#include "Utilities.h"

std::string readFile(std::string const & filePath){
	auto contents = std::ostringstream{};
	std::ifstream fileStream(filePath.c_str());
	contents<<fileStream.rdbuf();
	return contents.str();
}
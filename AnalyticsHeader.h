#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <array>

namespace fs = std::filesystem;

std::string path = R"raw(data\)raw";

std::string get_stem(const fs::path& p) 
{
	return (p.stem().string()); 
}

std::string getLineAt(std::string pathToFile, int lineNum)
{
	std::ifstream fooFile;
	fooFile.open(pathToFile);

	for (int i = 0; i < lineNum - 1; i++) {
		fooFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::string result;

	std::getline(fooFile, result);

	return result;
}

/*
for (const auto& entry : fs::directory_iterator(path))
{

}
*/
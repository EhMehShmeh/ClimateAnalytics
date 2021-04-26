#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <array>

namespace fs = std::filesystem;

std::string dataPath = R"raw(rawdata\both\)raw";

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
	
	fooFile.close();

	return result;
}

void processAndExport(std::string pathToFile) //removes Q/S/Rs from data values, averages/records highest values per month and builds the results matrix as it proceeds, then prints formatted results to finalized CSV
{
	std::string stationName;
	std::string stationID;
	std::string latitude;
	std::string longitude;
	std::string elevation;

	int currentMonth = 1;
	int currentDay = 1; //of the current month
	std::array<int, 12> tmin_avg;
	std::array<int, 12> tmax_avg;
	std::array<int, 12> prec_avg;

	std::string lineString;
	std::stringstream currentLine;
	std::string currentToken;
	std::ifstream fooFile;
	fooFile.open(pathToFile);
	std::getline(fooFile, lineString);
	std::getline(fooFile, lineString); // <- calls getline twice to move to the file parameters that i want to know

	currentLine << lineString;

	std::getline(currentLine, currentToken, ',');
	stationName = currentToken;
	std::getline(currentLine, currentToken, ',');
	stationID = currentToken;
	std::getline(currentLine, currentToken, ',');
	latitude = currentToken;
	std::getline(currentLine, currentToken, ',');
	longitude = currentToken;
	std::getline(currentLine, currentToken, ',');
	elevation = currentToken;

	lineString.clear();
	currentLine.str(std::string());
	currentLine.clear(); //so apparently clear() only cleans up eof bits and some other shizz so maybe my old program might have some not so good faults in there might have to check
	fooFile.clear();
	fooFile.close();

	fooFile.open(pathToFile);
	std::getline(fooFile, lineString); // <- resets fooFile to get ready for loop

	while (!fooFile.eof()) {
		std::getline(fooFile, lineString);

		currentLine << lineString;

		std::getline(currentLine, currentToken);
		std::cout << currentToken;
		/*
		for (int i = 0; i < 4; i++) {
			std::getline(currentLine, currentToken, ',');
			std::cout << currentToken;
		}
		*/
		break;

		currentLine.clear();
	}
}


/*
for (const auto& entry : fs::directory_iterator(path))
{

}
*/
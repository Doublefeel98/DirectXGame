#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
/*
std::string split implementation by using delimeter as a character.
*/
class Helper {
public:
	static std::vector<std::string> split(std::string strToSplit, char delimeter)
	{
		std::stringstream ss(strToSplit);
		std::string item;
		std::vector<std::string> splittedStrings;
		while (std::getline(ss, item, delimeter))
		{
			splittedStrings.push_back(item);
		}
		return splittedStrings;
	}
	/*
	std::string split implementation by using delimeter as an another string
	*/
	static std::vector<std::string> split(std::string stringToBeSplitted, std::string delimeter)
	{
		std::vector<std::string> splittedString;
		int startIndex = 0;
		int  endIndex = 0;
		while ((endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size())
		{
			std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
			splittedString.push_back(val);
			startIndex = endIndex + delimeter.size();
		}
		if (startIndex < stringToBeSplitted.size())
		{
			std::string val = stringToBeSplitted.substr(startIndex);
			splittedString.push_back(val);
		}
		return splittedString;
	}

	static int random(int minN, int maxN) {
		return minN + rand() % (maxN + 1 - minN);
	}

	static float float_rand(float min, float max)
	{
		float scale = rand() / (float)RAND_MAX; /* [0, 1.0] */
		return min + scale * (max - min);      /* [min, max] */
	}
};

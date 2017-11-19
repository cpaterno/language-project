#ifndef _language_h
#define _language_h

#include <map>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdlib>
#include <vector>

class language {
	public:
		language(std::string name, std::string text);
		language(std::string fileName);

		std::string getName();

	private:
		std::map<int, int> trigrameFrequency;
		std::string name; 
}	

#endif

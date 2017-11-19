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
		// Test constructor, calculates frequency of given "text"
		language(std::string name, std::string text);

		// Main constructor, takes in fileName and computes the trigram frequency of the file text.
		language(std::string fileName);

		// Gets the name of the language
		std::string getName();

		// Gets the frequency map
		std::map<int, int> getFrequencyMap();

		// Calculates cosine similarity of current language and given language.
		double computeComparison(language toCompare);
		
		// Prints the frequency
		void printFrequency();		

	private:
		// Helper function that updates the local frequency based on currently read in buffer.
		void updateFrequency(*vector<char>);

		// The trigram frequency map
		std::map<int, int> trigrameFrequency;
		
		// The name
		std::string name;
 
}	

#endif

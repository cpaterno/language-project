#ifndef _language_h
#define _language_h

#include <map>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctype.h>

/*
A class to represent languages.
A language object has two member fields: a name, which is the name of the language,
and a trigram frequency, which is a map which holds the counts for each possible trigram in a 27 character alphabet.
*/

class language {
	public:
		/*
		Constructor with separate arguments for name and text, which is used to compute the trigram frequency
		If `text` contains invalid characters, throws a std::runtime_error
		*/
		language(std::string name, std::string text);

		/*
		Constructor that expects an input file with language text.
		If the file can't be opened or the language text contains invalid characters
		(other than newlines, which are removed),
		throws a std::runtime_error
		*/
		language(std::string fileName);

		/*
		Getter methods
		*/
		std::string getName();
		std::map<int, int> getFrequencyMap();

		/*
		Takes in a pointer to a language to compare,
		calculates cosine similarity of current language and language to compare,
		returns a double representing the cosine similarity
		*/
		double computeComparison(language *toCompare);

		/*
		Prints the language's trigramFrequency
		*/
		void printFrequency();

	private:
		/*
		Helper that takes in a pointer to a vector, representing a pointer to a trigram.
		Updates the local frequency based on currently read in buffer.
		*/
		void updateFrequency(std::vector<char> *v);

		/* instance variables */
		std::string name;
		std::map<int, int> trigramFrequency;
};

#endif

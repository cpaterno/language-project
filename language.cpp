#include "language.h"

// Test constructor, calculates frequency of given "text"
language::language(std::string name, std::string text) {
  this->name = name;
  for(unsigned long i = 0; i < 3; i++) {
    std::vector<char> textChars;
    for(unsigned long j = 0; j < text.length(); j++) {
      if(text[j] != '\n') {
        textChars.push_back(text[j]);
      }
      if(textChars.size() == 2) {
        updateFrequency(&textChars);
      }
    }
  }
}

language::language(std::string fileName) {
  this->name = fileName.replace(fileName.find(".txt"), fileName.length(), "");
  std::ifstream infile;
	infile.open(fileName.c_str());
	if (!infile.fail()){
		char ch;
    for(unsigned long i = 0; i < 3; i++) {
      std::vector<char> textChars;
      infile.clear();
      infile.seekg(i, std::ios::beg);
      while (infile.get(ch)) {
        if(ch != '\n') {
          textChars.push_back(ch);
        }
        if(textChars.size() == 2) {
          updateFrequency(&textChars);
        }
  		}
    }
		infile.close();
	}
	else {
		std::cerr << "Could not open file " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}
}

std::string language::getName() {
  return name;
}

std::map<int, int> language::getFrequencyMap() {
  return trigramFrequency;
}

double language::computeComparison(language toCompare) {
  return 1.0;
}

void language::printFrequency() {

}

void language::updateFrequency(std::vector<char> *v) {

}

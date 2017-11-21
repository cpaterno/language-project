#include "language.h"

// Test constructor, calculates frequency of given "text"
language::language(std::string name, std::string text) {
    this->name = name;
    for(unsigned long i = 0; i < 3; i++) {
        std::vector<char> textChars;
        for(unsigned long j = i; j < text.length(); j++) {
            if(text[j] != '\n') {
                textChars.push_back(text[j]);
            }
            if(textChars.size() == 3) {
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
        for(unsigned long i = i; i < 3; i++) {
            std::vector<char> textChars;
            infile.clear();
            infile.seekg(i, std::ios::beg);
            while (infile.get(ch)) {
                if(ch != '\n') {
                    textChars.push_back(ch);
                }
                if(textChars.size() == 3) {
                    updateFrequency(&textChars);
                }
    		}
        }
		infile.close();
	} else {
		std::cerr << "Could not open file " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}
}


void language::updateFrequency(std::vector<char> *v) {
    int hash = 0;

    for (int i = 0; i < 3; i++) {
        // vector at method gets the value at index i
        if (v->at(i) != ' ') {
            hash += (v->at(i) - 96) * pow(27, 2-i);
        }
    }

    // map count method checks if the value exists in the map
    if (trigramFrequency.count(hash)) {
        // adds 1 to an already existing key
        trigramFrequency.find(hash)->second = trigramFrequency[hash] + 1;
    } else{
        trigramFrequency.insert( std::pair<int, int> (hash, 1) );
    }

    v->clear();

}

std::string language::getName() {
    return name;
}

std::map<int, int> language::getFrequencyMap() {
    return trigramFrequency;
}

double language::computeComparison(language *toCompare) {
    std::map<int,int> map2 = toCompare->getFrequencyMap();
    double cosSim = 0.0;
    double abCount = 0.0;
    double aSqrCount = 0.0;
    double bSqrCount = 0.0;
    int a;
    int b;
    for(int i = 0; i < 19682; i++) {
        a = 0;
        b = 0;

        if(trigramFrequency.count(i)) {
            a = trigramFrequency.find(i)->second;
        } else {
            a = 0;
        }

        if(map2.count(i)) {
            b = map2.find(i)->second;
        } else {
            b = 0;
        }

        abCount += (double)a * b;
        aSqrCount += pow((double)a, 2);
        bSqrCount += pow((double)b, 2);
    }

    if(aSqrCount == 0 || bSqrCount == 0) {
        cosSim = 0.0;
    }
    else {
        cosSim = (abCount)/(sqrt(aSqrCount) * sqrt(bSqrCount));
    }
    return cosSim;
}

void language::printFrequency() {
    for (int i = 0; i < 19682; i++) {
        if(trigramFrequency.count(i)) {
            std::cout << trigramFrequency.find(i)->second << std::endl;
        } else {
            std::cout << '0' << std::endl;
        }
    }
}

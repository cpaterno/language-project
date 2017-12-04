#include "language.h"

language::language(std::string name, std::string text) {
    this->name = name;
    for(unsigned long i = 0; i < 3; i++) {
        std::vector<char> textChars;
        for(unsigned long j = i; j < text.length(); j++) {
            // islower function takes in a character and checks if that character is a lowercase letter
            if (islower(text[j]) || text[j] == ' ') {
                textChars.push_back(text[j]);
            } else {
                throw std::runtime_error("Invalid input, a language can only contain lowercase letters or spaces");
            }
            if(textChars.size() == 3) {
                updateFrequency(&textChars);
            }
        }
    }
}

language::language(std::string fileName) {
    /*
    rFind method finds the first instance of a given character starting from the end of the string,
    returns the position of that character
    */
    int slashIndex = fileName.rfind('/');
    this->name = fileName.substr((slashIndex + 1));

    std::ifstream infile;
	infile.open(fileName.c_str());
	if (!infile.fail()){
		char ch;
        for(unsigned long i = 0; i < 3; i++) {
            std::vector<char> textChars;
            // clear method clears the iostream
            infile.clear();
            // seekg method resets buffer to read from the ith byte
            infile.seekg(i, std::ios::beg);
            while (infile.get(ch)) {
                // islower function takes in a character and checks if that character is a lowercase letter
                if (islower(ch) || ch == ' ') {
                    textChars.push_back(ch);
                } else {
                    throw std::runtime_error("Invalid input, a language can only contain lowercase letters or spaces");
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
            // pow function raises the first argument to the second argument
            hash += (v->at(i) - 96) * pow(27, 2-i);
        }
    }

    // map count method checks if the value exists in the map
    if (trigramFrequency.count(hash)) {
        //map find method gets the value based on a given key, adds 1 to an already existing key
        trigramFrequency.find(hash)->second = trigramFrequency[hash] + 1;
    } else{
        // map insert method creates a new key pair value pair to the map
        trigramFrequency.insert( std::pair<int, int> (hash, 1) );
    }
    // vector clear method, clears the vector until it is empty
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
    for(int i = 0; i <= 19682; i++) {
        a = 0;
        b = 0;
        // map count method checks if the value exists in the map
        if(trigramFrequency.count(i)) {
            // map find method gets the value based on a given key
            a = trigramFrequency.find(i)->second;
        } else {
            a = 0;
        }
        // map count method checks if the value exists in the map
        if(map2.count(i)) {
            // map find method gets the value based on a given key
            b = map2.find(i)->second;
        } else {
            b = 0;
        }

        abCount += (double)a * b;
        // pow function raises the first argument to the second argument
        aSqrCount += pow((double)a, 2);
        // pow function raises the first argument to the second argument
        bSqrCount += pow((double)b, 2);
    }

    if(aSqrCount == 0 || bSqrCount == 0) {
        cosSim = 0.0;
    } else {
        cosSim = (abCount)/(sqrt(aSqrCount) * sqrt(bSqrCount));
    }
    return cosSim;
}

void language::printFrequency() {
    for (int i = 0; i <= 19682; i++) {
        // map count method checks if the value exists in the map
        if(trigramFrequency.count(i) && i == 19682) {
            // map find method gets the value based on a given key
            std::cout << trigramFrequency.find(i)->second;
        // map count method checks if the value exists in the map
        } else if (trigramFrequency.count(i)) {
            // map find method gets the value based on a given key
            std::cout << trigramFrequency.find(i)->second << " ";
        // map count method checks if the value exists in the map
        } else if (!trigramFrequency.count(i) && i == 19682) {
            std::cout << '0';
        } else {
            std::cout << '0' << " ";
        }
    }
    std::cout << std::endl;
}

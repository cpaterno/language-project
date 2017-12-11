#include "language.h"

language::language(std::string name, std::string text) {
  this->name = name;
  for (unsigned long i = 0; i < 3; i++) {
    std::vector<char> textChars;
    for (unsigned long j = i; j < text.length(); j++) {
      // islower function takes in a character and checks if that character is a
      // lowercase letter
      if (islower(text[j]) || text[j] == ' ') {
        textChars.push_back(text[j]);
      } else {
        throw std::runtime_error("Invalid input, a language can only contain "
                                 "lowercase letters or spaces");
      }
      if (textChars.size() == 3) {
        updateFrequency(&textChars);
      }
    }
  }
}

language::language(std::string fileName) {
  this->name = fileName;
  std::ifstream infile;
  infile.open(fileName.c_str());
  if (!infile.fail()) {
    char ch;
    for (unsigned long i = 0; i < 3; i++) {
      std::vector<char> textChars;
      // clear method clears the iostream
      infile.clear();
      // seekg method resets buffer to read from the ith byte
      infile.seekg(i, std::ios::beg);
      while (infile.get(ch)) {
        // islower function takes in a character and checks if that character is
        // a lowercase letter
        if (islower(ch) || ch == ' ') {
          textChars.push_back(ch);
        } else {
          throw std::runtime_error("Invalid input, a language can only contain "
                                   "lowercase letters or spaces");
        }
        if (textChars.size() == 3) {
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
      hash += (v->at(i) - 96.0) * pow(27.0, 2.0 - i);
    }
  }

  // map count method checks if the value exists in the map
  if (trigramFrequency.count(hash)) {
    // map find method gets the value based on a given key, adds 1 to an already
    // existing key
    trigramFrequency.find(hash)->second = trigramFrequency[hash] + 1.0;
  } else {
    // map insert method creates a new key pair value pair to the map
    trigramFrequency.insert(std::pair<int, long double>(hash, 1.0));
  }
  // vector clear method, clears the vector until it is empty
  v->clear();
}

std::string language::getName() { return name; }

std::map<int, long long> language::getFrequencyMap() {
  return trigramFrequency;
}

long double language::computeComparison(language *toCompare) {
  std::map<int, long long> comparisonLanguage = toCompare->getFrequencyMap();
  unsigned long long numerator = 0.0;
  unsigned long long a2 = 0.0;
  unsigned long long b2 = 0.0;
  for (int i = 0; i <= 19682; i++) {
    // map count method checks if the value exists in the map
    if (trigramFrequency.count(i) && comparisonLanguage.count(i)) {
      // map count method checks if the value exists in the map
      numerator +=
          trigramFrequency.find(i)->second * comparisonLanguage.find(i)->second;
    }
    // map count method checks if the value exists in the map
    if (trigramFrequency.count(i)) {
      // map count method checks if the value exists in the map
      a2 += (unsigned long long)pow(
          (unsigned long long)trigramFrequency.find(i)->second,
          (unsigned long long)2.0);
    }
    // map count method checks if the value exists in the map
    if (comparisonLanguage.count(i)) {
      // map count method checks if the value exists in the map
      b2 += (unsigned long long)pow(
          (unsigned long long)comparisonLanguage.find(i)->second,
          (unsigned long long)2.0);
    }
  }
  if (a2 == 0 || b2 == 0)
    return 0.0;
  return numerator / (sqrt(a2) * sqrt(b2));
}

void language::printFrequency() {
  for (int i = 0; i <= 19682; i++) {
    // map count method checks if the value exists in the map
    if (trigramFrequency.count(i) && i == 19682) {
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

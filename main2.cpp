#include <cstdlib>
#include <vector>

#include "language.h"

language* findBestMatch(std::vector<language*> *v, language *test);

int main(int argc, char *argv[]) {

    if (argc < 3) {
        throw std::runtime_error("Less than 2 command line arguments");
    } else {
        std::vector<language*> v;
        for (int i = 1; i < argc - 2; i++) {
            v.push_back(new language(argv[i]));
        }
        language *best = findBestMatch(&v, new language(argv[argc - 1]));
        std::cout << best->getName() << '\n' << std::endl;
    }
    return 0;
}

language* findBestMatch(std::vector<language*> *v, language *test) {
	double max = 0.0;
	double bestLanguage = 0;
	double tempComparison = 0.0;

	for (int languageIndex = 0; languageIndex < v->size(); languageIndex ++) {
		tempComparison = v->at(languageIndex)->computeComparison(test);
		if (tempComparison > max) {
			max = tempComparison;
			bestLanguage = languageIndex;
		}
	}

	return v->at(bestLanguage);
}
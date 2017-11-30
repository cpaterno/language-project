#include <cstdlib>

#include "language.h"

int main(int argc, char *argv[]) {

	language *lang = nullptr;
	std::string input = argv[1];

	if (argc == 2) {
		lang = new language("input", input);
	} else{
		throw std::runtime_error("Less than or more than one command line argument.");
	}

	if (lang == nullptr) {
		throw std::runtime_error("An error occurred loading the input string");
	}

	lang->printFrequency();

    return 0;
}

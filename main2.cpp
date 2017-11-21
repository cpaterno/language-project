#include <cstdlib>
#include <vector>

#include "language.h"

language findBestMatch(std::vector<*language> *v, language *test);

int main(int argc, char *argv[]) {

    if (argc < 3) {
        throw std::runtime_error("Less than 2 command line arguments");
    } else {
        std::vector<*language> v;
        for (int i = 0; i < argc - 2; i++) {
            v.push_back(new language(argv[i]));
        }
    }

    language best = findBestMatch(&v, new language(argv[argc - 1]));
    std::cout << best.getName() << std::endl;
    return 0;
}

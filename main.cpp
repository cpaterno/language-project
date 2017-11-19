#include "language.h"

int main(int argc, char *argv[]) {

  language *test = new language("test", "this is i");

  /*std::map<int,int> testMap = test->getFrequencyMap();
  std::map<int,int>::iterator it = testMap.begin();

  for (; it != testMap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';*/

  //test->printFrequency();

  language *test1 = new language("test", "this is i");
  double dist = test->computeComparison(test1);
  std::cout << dist << std::endl;

  return 0;
}

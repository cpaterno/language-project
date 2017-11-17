# language-project
# URI CSC 211 Assignment 5
### Vittorio Papandrea and Christopher Paterno
### vpapandrea@my.uri.edu and cpaterno@my.uri.edu

## Problems to Solve
- [ ] Compute trigram frequency vector for a given lanaguage.
- [ ] Compute cosine similarity between known language and unknown language

## Generale Solution to problems
- [ ] Loop in pairs of three and increment the value of a key in a map. If the value in the map doesn't exists add the key and set the value to 1.

## Classes Needed
- [ ] Language class that represents an abstract language with a name and a trigram frequency collection
- [ ] Language constructor function that takes an input stream to a file
- [ ] Name getter method
- [ ] Trigram frequency collection comparison method, that takes in a Language object
- [ ] Print method that prints the trigram frequency collection

## Other Functions
- [ ] `findBestMatch()` compares test data with the loaded data and returns the language class of best simlarity.

## Files Needed 
- [ ] `language.h` and `language.cpp` for implementation of language class.
- [ ] `main.cpp` 

## Libraries Needed
- [ ] `cmath`
- [ ] `iostream` and `fstream`
- [ ] `cstdlib`
- [ ] `string`

## Compile Script
- [ ] For milestone 1 our executable needs to be frequencies
- [ ] For milestone 2 our executable needs to be language
- [ ] Each compile script will compile `language.cpp` and `main.cpp`. We don't need to include *.h becuase they are included in the *.cpp files.

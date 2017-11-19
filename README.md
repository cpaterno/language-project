# language-project
# URI CSC 211 Assignment 5
### Vittorio Papandrea and Christopher Paterno
### vpapandrea@my.uri.edu and cpaterno@my.uri.edu

## Problems to Solve
- [ ] Compute trigram frequency vector for a given lanaguage.
- [ ] Compute cosine similarity between known language and unknown language

## General Solution to problems
- [ ] Loop in pairs of three and increment the value of a key in a map. If the value in the map doesn't exists add the key and set the value to 1.
- [ ] Compute the cosine similarity of the test language and each given training language, using the given formula. 
Store the lowest distance (represented as 1 - similarity) and output language class of best similarity.

## Classes Needed
- [ ] Language class that represents an abstract language with a name and a trigram frequency collection
- [ ] Language constructor function that takes two strings as input. The first string represents the language's name, 
the second the text of the language (used to compute trigram frequency). 
This constructor is used in Milestone 1.
- [ ] Language constructor function that takes an input stream to a file. Trigram frequency is computed in constructor. 
This constructor is used in Milestone 2.
- [ ] Name getter method, returns a string.
- [ ] `getFrequencyMap()` gets the frequency map.
- [ ] Trigram frequency collection comparison method, that takes in a Language object, and returns a distance represented as a double
- [ ] Print method that prints the trigram frequency collection, and returns nothing (type void).
- [ ] `updateFrequency()` method, type void, takes in a `*vector<char>`, updates trigram frequency collection.  

## Other Functions
- [ ] `findBestMatch()`, type Language, compares test data with the loaded data and returns the language class of best simlarity.  

## Files Needed 
- [ ] `language.h` and `language.cpp` for implementation of language class.
- [ ] Milestone 1: `main.cpp`, checks if user entered 1 command line argument, prints trigram frequency container, 
prints 0 if success, 1 if error
- [ ] Milestone 2: 'main.cpp', checks if user entered 2 or more command line arguments, prints what language the test input is most similar to,
prints 0 if success, 1 if error 

## Libraries Needed
- [x] `cmath`
- [x] `iostream` and `fstream`
- [x] `cstdlib`
- [x] `string`
- [x] `vector`
- [x] `map`

## Compile Script
- [ ] For milestone 1 our executable needs to be frequencies
- [ ] For milestone 2 our executable needs to be language
- [ ] Each compile script will compile `language.cpp` and `main.cpp`. We don't need to include *.h becuase they are included in the *.cpp files.

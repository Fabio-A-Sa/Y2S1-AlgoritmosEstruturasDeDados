#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "bst.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

BST<WordMean> Dictionary::getWords() const {
	return words;
}

bool WordMean::operator < (const WordMean &w) {
    if (this->getWord() == w.getWord()) return this->getMeaning() < w.getMeaning();
    return this->getWord() < w.getWord();
}

void Dictionary::readFile(ifstream &f) {

    string currentWord, currentMeaning;
    while (!f.eof()) {
        getline(f, currentWord);
        getline(f, currentMeaning);
        WordMean current = WordMean(currentWord, currentMeaning);
        bool answer = words.insert(b);
    }
}

//TODO
string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {
    return "";
}

//TODO
bool Dictionary::update(string word1, string mean1) {
    return true;
}

//TODO
void Dictionary::print() const {
}

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

bool WordMean::operator < (const WordMean &w) const {
    return this->getWord() < w.getWord();
}

bool WordMean::operator == (const WordMean &a) const {
    return this->getWord() == a.getWord();
}

void Dictionary::readFile(ifstream &f) {

    WordMean notFound = WordMean("", "");
    string currentWord, currentMeaning;

    while (!f.eof()) {
        getline(f, currentWord);
        getline(f, currentMeaning);
        WordMean current = WordMean(currentWord, currentMeaning);
        WordMean found = words.find(current);
        if (found == notFound) words.insert(current);
    }
}

void Dictionary::print() const {

    BSTItrIn<WordMean> itr(words);
    while (!itr.isAtEnd()) {
        cout << itr.retrieve().getWord() << endl;
        cout << itr.retrieve().getMeaning() << endl;
        itr.advance();
    }
}

string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {

    WordMean toSearch = WordMean(word1, "");
    WordMean notFound = WordMean("", "");
    WordMean found = words.find(toSearch);
    if (found == notFound) {

        WordMean antes("", ""), depois ("","");

        BSTItrIn<WordMean> itr(words);

        while (previous.getWord() > word1 || next.getWord() < word1) {
            previous = next;
            itr.advance();
            next = itr.retrieve();
        }

        return "word not found";

    } else {
        return found.getMeaning();
    }
}

//TODO
bool Dictionary::update(string word1, string mean1) {
    return true;
}
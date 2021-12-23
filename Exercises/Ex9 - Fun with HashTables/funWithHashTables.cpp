// Created on December, 2021
// @author: Fábio Araújo de Sá

#include "funWithHashTables.h"
#include <vector>
#include <iostream>

unsigned FunWithHashTables::hashInt(const int& i) {
  return i;
}

unsigned FunWithHashTables::hashString(const string& s) {
  hash<string> h;
  return h(s);
}

int max (const vector<int>& numbers) {

    int max = numbers[0];
    for (int number : numbers) max = number > max ? number : max;
    return max;
}

int FunWithHashTables::sumPairs(const vector<int>& numbers) {

    int hashTableSize = 2 * max(numbers);
    HashTable<int> allSums = HashTable<int>(hashTableSize, hashInt);
    allSums.clear();

    for (int i = 0 ; i < numbers.size() - 1 ; i++) {
        for (int j = i + 1 ; j < numbers.size() ; j++) {
            allSums.insert(numbers[i] + numbers[j]);
        }
    }

    return allSums.getNumActive();
}

int FunWithHashTables::dnaMotifs(string dna, int k, unordered_set<string>& motifs) {

    unordered_map<string, int> allMotifs = {};
    for (int i = 0 ; i < dna.size() - k + 1; i++) {
        string motif = dna.substr(i, k);
        if (allMotifs.find(motif) == allMotifs.end()) allMotifs[motif] = 1;
        else allMotifs[motif]++;
    }

    int maxOccurrence = 0;
    for (unordered_map<string, int>::iterator it = allMotifs.begin() ; it != allMotifs.end() ; it++) {
        maxOccurrence = maxOccurrence > it->second ? maxOccurrence : it->second;
    }

    for (unordered_map<string, int>::iterator it = allMotifs.begin() ; it != allMotifs.end() ; it++) {
        if (it->second == maxOccurrence) motifs.insert(it->first);
    }

    return maxOccurrence;
}

vector<string> toWords(const string &text) {

    vector<string> allWords = {};
    string currentWord = "";
    for (char letter : text) {
        letter = tolower(letter);
        if ((letter == ' ' || letter == '-' )&& !currentWord.empty()) {
            allWords.push_back(currentWord);
            currentWord = "";
        } else if (isalpha(letter)) currentWord += letter;
    }
    allWords.push_back(currentWord);

    return allWords;
}

bool in(const string &w, const vector<string> &words) {
    for (const string &word : words) if (word == w) return true;
    return false;
}

void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {

    vector<string> allWords = toWords(text);
    unordered_multimap<string, string> occurrence = {};

    for (string word : allWords) {
        for (auto it = dict.begin() ; it != dict.end() ; it++) {
            if (in(word, it->second)) occurrence.insert(make_pair(word, it->first));
        }
    }

    for (auto it = occurrence.begin(); it != occurrence.end(); it++)
        cout << "<" << it->first << ", " << it->second
             << ">  ";

    cout << endl;

    for (auto it = occurrence.begin() ; it != occurrence.end() ; it ++) {
        if (answer.find(it->second) == answer.end()) answer.insert(make_pair(it->second, 1));
        else answer[it->second]++;
    }
}

void FunWithHashTables::wordIndex(const vector<string> &words, vector<int>& answer) {
}
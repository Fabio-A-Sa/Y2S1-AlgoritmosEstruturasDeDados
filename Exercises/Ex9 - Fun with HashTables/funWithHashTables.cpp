// Created on December, 2021
// @author: Fábio Araújo de Sá

#include "funWithHashTables.h"
#include <vector>
#include <iostream>

int max (const vector<int>& numbers) {

    int max = numbers[0];
    for (int number : numbers) max = number > max ? number : max;
    return max;
}

unsigned FunWithHashTables::hashString(const string& s) {
  hash<string> h;
  return h(s);
}

int FunWithHashTables::sumPairs(const vector<int>& numbers) {
  return 0;
}

int FunWithHashTables::dnaMotifs(string dna, int k, unordered_set<string>& motifs) {
  return 0;
}

void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {
}

void FunWithHashTables::wordIndex(const vector<string> &words, vector<int>& answer) {
}
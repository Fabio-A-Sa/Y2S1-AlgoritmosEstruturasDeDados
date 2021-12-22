// Created on December, 2021
// @author: Fábio Araújo de Sá

#include "funWithHashTables.h"
#include "hashTable.h"

#include <vector>
#include <iostream>
#include <cctype>

unsigned FunWithHashTables::hashInt(const int& i) {
  return i;
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
// Created on December, 2021
// @author: Fábio Araújo de Sá

#include "funWithBSTs.h"

int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {

    set<int> unRepeted;
    for (int cromo : collection) unRepeted.insert(cromo);
    int beforeInsertion = unRepeted.size();

    for (int newCromo : bag) unRepeted.insert(newCromo);

    return unRepeted.size() - beforeInsertion;
}

int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
  return 0;
}

int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
  return 0;
}

void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
}

vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    return answer;
}

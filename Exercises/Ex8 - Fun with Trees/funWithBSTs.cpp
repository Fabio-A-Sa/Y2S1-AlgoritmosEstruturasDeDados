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

    multiset<int> mAlice; for (int card : alice) mAlice.insert(card);
    multiset<int> mBruno; for (int card : bruno) mBruno.insert(card);

    multiset<int>::iterator iteratorAlice;
    multiset<int>::iterator iteratorBruno;

    while (!mAlice.empty() && !mBruno.empty()) {

        iteratorAlice = mAlice.end(); iteratorAlice--;
        iteratorBruno = mBruno.end(); iteratorBruno--;

        int maxAlice = *iteratorAlice; mAlice.erase(iteratorAlice);
        int maxBruno = *iteratorBruno; mBruno.erase(iteratorBruno);

        if (maxAlice > maxBruno) {
            maxAlice -= maxBruno;
            mAlice.insert(maxAlice);
        } else if (maxAlice < maxBruno) {
            maxBruno -= maxAlice;
            mBruno.insert(maxBruno);
        } else continue;
    }

    if (!mAlice.empty()) return mAlice.size();
    if (!mBruno.empty()) return -mBruno.size();
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

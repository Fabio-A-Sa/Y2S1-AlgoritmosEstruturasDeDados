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

    set<string> movies = {};
    for (pair<string, int> review : reviews) movies.insert(review.first);
    return movies.size();
}

void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {

    map<string, int> totalReview = {};
    m = 0;
    for (pair<string, int> review : reviews) {
        if (totalReview.find(review.first) != totalReview.end()) totalReview[review.first] += 1;
        else totalReview[review.first] = 1;

        m = totalReview[review.first] > m ? totalReview[review.first] : m;
    }

    n = 0;
    for (map<string, int>::iterator it = totalReview.begin(); it != totalReview.end(); it++) {
        if (it->second == m) n++;
    }
}

vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {

    vector<string> answer = {};
    map<string, int> totalPoints = {};
    map<string, int> occurrence = {};

    for (const pair<string, int> &review : reviews) {

        if (totalPoints.find(review.first) != totalPoints.end()) totalPoints[review.first] += review.second;
        else totalPoints[review.first] = review.second;

        if (occurrence.find(review.first) != occurrence.end()) occurrence[review.first]++;
        else occurrence[review.first] = 1;
    }

    set<string> nonRepeted = {};
    for (const pair<string, int> &review : reviews) {
        if ((float) totalPoints[review.first] / occurrence[review.first] >= k) nonRepeted.insert(review.first);
    }

    answer.assign(nonRepeted.begin(), nonRepeted.end());

    sort(answer.begin(), answer.end());
    return answer;
}
// Created on December, 2021
// @author: Fábio Araújo de Sá

#ifndef _FUNBST_H_
#define _FUNBST_H_

#include "bst.h"
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

class FunWithBSTs {

    public:
    
        static int newBag(const vector<int>& collection, const vector<int>& bag);
        static int battle(const vector<int>& alice, const vector<int>& bruno);
        static int numberMovies(const vector<pair<string, int>>& reviews);
        static void moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n);
        static vector<string> topMovies(const vector<pair<string, int>>& reviews, double k);
};

#endif

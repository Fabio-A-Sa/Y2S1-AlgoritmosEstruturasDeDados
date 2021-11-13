// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "funSortProblem.h"
#include <algorithm>
#include <vector>

FunSortProblem::FunSortProblem() {}

template <class F>
void swapElements(F &p1, F &p2) {
    F temp = p1;
    p1 = p2;
    p2 = temp;
}

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {

    if (products.size() > k) {

        // Sort vector based on Selection Sort Algorithm and operator < implemented in class Product
        for (int i = 0 ; i < products.size() ; i++ ) {
            int min = i;
            for (int j = i+1 ; j < products.size() ; j++ ) {
                if (products[j] < products[min]) min = j;
            }
            swapElements(products[i], products[min]);
        }

        // Buy all first k products
        products.erase(products.begin() + k, products.end());
    }
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {

    if (values.size() >= nc) {

        // Sorting chocolate vector using Selection Sort Algorithm
        vector<unsigned> v = values;

        for (int i = 0 ; i < v.size() ; i++ ) {
            int min = i;
            for (int j = i+1 ; j < v.size() ; j++ ) {
                if (v[j] < v[min]) min = j;
            }
            swapElements(v[i], v[min]);
        }

        // Get minimum difference in [i,i+nc]
        int minDiff = INT_MAX, currentDiff;
        for (int i = 0 ; i < v.size() - nc + 1; i++) {
            currentDiff = v[i+nc-1] - v[i];
            if (currentDiff < minDiff) minDiff = currentDiff;
        }
        return minDiff;

    } else return -1;

    // Time complexity: O(n^2)
    // Space complexity: O(n), clone of initial vector to swap values if necessary
}

bool key (pair<float, char> &p1, pair<float, char> &p2) {
    return p1.first < p2.first;
}

bool exist(const vector<char> & horarios) {
    for (auto h : horarios) if (h != 'V') return true;
    return false;
}

void generateTrain (vector<char> &horarios) {

    char toSeek = 'A';
    for (auto & h : horarios) {
        if (h == toSeek) {
            h = 'V'; // visited
            toSeek = toSeek == 'A' ? 'D' : 'A';
        }
    }
}

unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {

    if (!arrival.empty() || !departure.empty()) {

        int platforms = 0;
        vector<pair<float, char>> order = {};
        for (auto time : arrival) order.push_back(pair<float, char>(time, 'A'));
        for (auto time : departure) order.push_back(pair<float, char>(time, 'D'));

        sort(order.begin(), order.end(), key);
        vector<char> horarios = {};
        for (auto pair : order) horarios.push_back(pair.second);

        while (exist(horarios)) {
            generateTrain(horarios);
            platforms++;
        }

        /**
            A --> Chegada
            D --> Partida
            V --> Horário visitado

            Cada comboio consome uma plataforma e a máxima sequência de pares de horários (A + D)

            A D A A A D D D A A D D --> platforms = 0, existem ainda horários = true;
            V V V A A V D D V A V D --> platforms = 1, existem ainda horários = true;
            V V V V A V V D V V V V --> platforms = 2, existem ainda horários = true;
            V V V V V V V V V V V V --> platforms = 3, existem ainda horários = false;

            A D A D A D --> platforms = 0, existem ainda horários = true;
            V V V V V V --> platforms = 1, existem ainda horários = false;
         */

        return platforms;

    } else return arrival.empty() ? departure.size() : arrival.size();

    // Time complexity: O(n^2)
    // Space complexity: O(n)
}

int partition(vector<Piece> &v, int low, int high) {

    float pivot = v[high].getDiameter();
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (v[j].getDiameter() <= pivot) {
            i++;
            swapElements(v[i], v[j]);
        }
    }
    swapElements(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(vector<Piece> &v, int low, int high) {

    if (low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

bool NBKey (const Piece &p1, const Piece &p2) {
    return p1.getDiameter() < p2.getDiameter();
}

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

    sort(nuts.begin(), nuts.end(), NBKey);
    sort(bolts.begin(), bolts.end(), NBKey);

    // Time complexity: O(n*log(n));
    // Space complexity: O(n);
}
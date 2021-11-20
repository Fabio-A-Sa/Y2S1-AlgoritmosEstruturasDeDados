// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
    int result = 0;
    for (auto c : phrase) if (c == ' ') result++;
    return result ? result + 1 : result;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

list<Kid> Game::getKids() const {
    return kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

void Game::splitKids(list<Kid> &boys, list<Kid> &girls) const {

    for (auto const &kid : kids) {
        if (kid.getSex() == 'm') boys.push_back(kid);
        else girls.push_back(kid);
    }
}

Kid Game::loseGame(string phrase) {

    int words = numberOfWords(phrase);
    int index = 0;

    while (kids.size() > 1) {
        index = (words-1+index) % kids.size();
        list<Kid>::iterator it = kids.begin();
        for (int i = 0 ; i < index ; i++) { it++; }
        kids.remove(*it);
    }

    return kids.front();
}

list<Kid> Game::removeOlder(unsigned id) {

    list<Kid> result = {};
    for (auto kid : kids) {
        if (kid.getAge() > id) {
            result.push_back(kid);
            kids.remove(kid);
        }
    }
    return result;
}

queue<Kid> Game::rearrange() {

    queue<Kid> result = {};
    list<Kid> sortedKids = {}, qBoys = {}, qGirls = {};
    splitKids(qBoys, qGirls);

    int boys = qBoys.size(), girls = qGirls.size();
    int nBoys = girls < boys ? boys/girls : 1;
    int nGirls = girls >= boys ? girls/boys : 1;

    int loop = kids.size() / (nGirls+nBoys);

    while (loop) {

        int qtdGirls = nGirls, qtdBoys = nBoys;
        while (qtdGirls) {
            sortedKids.push_back(qGirls.front());
            qGirls.remove(qGirls.front());
            qtdGirls--;
        }
        while (qtdBoys) {
            sortedKids.push_back(qBoys.front());
            qBoys.remove(qBoys.front());
            qtdBoys--;
        }
        loop--;
    }

    for (auto girl : qGirls) result.push(girl);
    for (auto boy : qBoys) result.push(boy);
    kids = sortedKids;
    return result;
}

bool Game::operator == (Game& g2) {

    if (this->getKids().size() != g2.getKids().size()) return false;

    int i = 0;
    for (auto k1 : this->getKids()) {
        int j = 0;
        for (auto k2 : g2.getKids()) {
            if (i == j && !(k1 == k2)) return false;
            j++;
        }
        i++;
    }

    return true;
}

list<Kid> Game::shuffle() const {

    list<Kid> result = {}, k = kids;
    int index;

    while (k.size()) {

        index = rand() % k.size(); // random index in [0..k.size()]

        int i = 0;
        for (auto kid : k) {
            if (i == index) {
                result.push_back(kid);
                k.remove(kid);
                break;
            }
            i++;
        }

    }
	return result;
}
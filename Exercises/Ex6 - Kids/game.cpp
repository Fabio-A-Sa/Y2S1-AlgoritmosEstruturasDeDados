// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {

  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
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

int Game::getBoys() const {

    int boys = 0;
    for (auto const &kid : kids) {
        if (kid.getSex() == 'm') boys++;
    }
    return 0;
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

    int boys = getBoys();
    int girls = kids.size() - boys;

    return(queue<Kid>());
}

bool Game::operator == (Game& g2) {

    if (this->getKids().size() != g2.getKids().size()) return false;

    auto g1Kids = this->getKids().begin();
    auto g2Kids = g2.getKids().begin();
    for (int i = 0 ; i < this->getKids().size() ; i++) {
        if (!(*g1Kids == *g2Kids)) return false;
        g1Kids++;
        g2Kids++;
    }
    return true;
}

// TODO
list<Kid> Game::shuffle() const {
	return (list<Kid>());
}

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

//-----------------------------------------------------------------

// TODO
void Game::addKid(const Kid k1) {
}

// TODO
list<Kid> Game::getKids() const {
    return (list<Kid>());
}

// TODO
void Game::setKids(const list<Kid>& l1) {
}

// TODO
Kid Game::loseGame(string phrase) {
    return (Kid("",0,'x'));
}

// TODO
list<Kid> Game::removeOlder(unsigned id) {
    return (list<Kid>());
}

// TODO
queue<Kid> Game::rearrange() {
    return(queue<Kid>());
}

// TODO
bool Game::operator==(Game& g2) {
	return true;
}

// TODO
list<Kid> Game::shuffle() const {
	return (list<Kid>());
}

// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "postOffice.h"
#include <string>
#include <sstream>

PostOffice::PostOffice() {}

PostOffice::PostOffice(string firstZCode, string lastZCode) {
    this->firstZipCode = firstZCode;
    this->lastZipCode = lastZCode;
}

NoPostmanException::NoPostmanException(string name) {
    this->name = name;
}

string NoPostmanException::getName() const {
    return name;
}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}

vector<Mail *> PostOffice::removePostman(string name) {

	vector<Mail *> res = {};
    for (vector<Postman>::iterator p = postmen.begin() ; p != postmen.end() ; p++) {
        if ((*p).getName() == name) {
            res = (*p).getMail();
            postmen.erase(p);
            return res;
        }
    }
	return res;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {

	unsigned int total = 0;
    vector<Mail *> answer;
    string n1 = firstZipCode.substr(0, 4) + firstZipCode.substr(5, 3);
    stringstream toInt1(n1);
    int minimo = 0; toInt1 >> minimo;
    string n2 = lastZipCode.substr(0, 4) + lastZipCode.substr(5, 3);
    stringstream toInt2(n2);
    int maximo = 0; toInt2 >> maximo;

    for (vector<Mail *>::iterator i = mailToSend.begin() ; i != mailToSend.end() ; i++) {

        total += (*i)->getPrice();

        string currentZip = (*i)->getZipCode().substr(0, 4) + (*i)->getZipCode().substr(5, 3);
        stringstream toInt(currentZip);
        int current = 0; toInt >> current;

        if (current >= minimo && current <= maximo) {
            addMailToDeliver(*i);
        } else {
            answer.push_back(*i);
        }
    }
    mailToSend.clear();
    balance = total;
	return answer;
}

Postman PostOffice::addMailToPostman(Mail *m, string name) {

    for (auto postman : postmen) {
        if (postman.getName() == name) {
            postman.addMail(m);
            return postman;
        }
    }
    NoPostmanException non = NoPostmanException(name);
    throw (non);
}
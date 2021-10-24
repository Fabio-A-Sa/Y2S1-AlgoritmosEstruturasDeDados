#include "PostOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode) {
    this->firstZipCode = firstZCode;
    this->lastZipCode = lastZCode;
}

PostOffice::PostOffice() { }

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

	vector<Mail *> answer = {};
    for (vector<Postman>::iterator it = postmen.begin() ; it != postmen.end() ; it++) {
        if ((*it).getName() == name) {
            answer = (*it).getMail();
            postmen.erase(it);
            return answer;
        }
    }
	return answer;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {

    vector<Mail *> out;
    unsigned int totalPrice = 0;

    for (vector<Mail *>::iterator it = mailToSend.begin() ; it != mailToSend.end() ; it++ ) {

        totalPrice += (*it)->getPrice();
        if ((*it)->getZipCode() <= lastZipCode && (*it)->getZipCode() >= firstZipCode) {
            addMailToDeliver(*it);
        }
        else {
            out.push_back(*it);
        }
        mailToSend.erase(it);
    }
    balance = totalPrice;
	return out;
}


Postman PostOffice::addMailToPostman(Mail *m, string name) {
	Postman p1;
    return p1;
}


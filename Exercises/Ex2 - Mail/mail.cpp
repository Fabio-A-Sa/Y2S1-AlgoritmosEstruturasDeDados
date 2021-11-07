// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "mail.h"

Mail::Mail(string send, string rec, string zcode) {
    this->sender = send;
    this->zipCode = zcode;
    this->receiver = rec;
}

Mail::~Mail() {};

string Mail::getZipCode() const {
	return zipCode;
}

RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w) : Mail(send, rec, zcode) {
    this->weight = w;
}

GreenMail::GreenMail(string send, string rec, string zcode, string t) : Mail(send, rec, zcode) {
    this->type = t;
}

unsigned int RegularMail::getPrice() const {
	if (weight <= 20) return 50;
    if (weight > 20 && weight <= 100) return 75;
    if (weight > 100 && weight <= 500) return 140;
    return 325;
}

unsigned int GreenMail::getPrice() const {
    if (type == "envelope") return 80;
    if (type == "bag") return 200;
    return 240;
}
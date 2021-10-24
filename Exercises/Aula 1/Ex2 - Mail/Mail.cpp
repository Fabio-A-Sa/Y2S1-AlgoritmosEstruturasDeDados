#include "Mail.h"

Mail::Mail() {
    this->zipCode = "";
    this->sender = "";
    this->receiver = "";
}

Mail::Mail(string send, string rec, string zcode) {
    this->receiver = rec;
    this->sender = send;
    this->zipCode = zcode;
}

string Mail::getZipCode() const {
	return zipCode;
}

unsigned int Mail::getPrice() const {
    return 0;
}

RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w) {
    Mail(send, rec, zcode);
    this->weight = w;
}

GreenMail::GreenMail(string send, string rec, string zcode, string t) {
    Mail(send, rec, zcode);
    this->type = t;
}

unsigned int GreenMail::getPrice() const {

    if (type == "envelope") return 80;
    if (type == "bag") return 200;
    if (type == "box") return 240;
    return 0;
}

unsigned int RegularMail::getPrice() const {

    if (weight <= 20) return 50;
    if (weight > 20 && weight <= 100) return 75;
    if (weight > 100 && weight <= 500) return 140;
    return 325;
}
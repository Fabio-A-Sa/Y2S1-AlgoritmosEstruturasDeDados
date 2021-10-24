#include "Mail.h"

Mail::Mail(string send, string rec, string zcode) {
    this->receiver = rec;
    this->sender = send;
    this->zipCode = code;
}

virtual Mail::~Mail() {
    cout << "Email sent" << endl;
}

string Mail::getZipCode() const {
	return zipCode;
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

    switch (type) {
        case "envelope": return 80;
        break;
        case "bag": return 200;
        break;
        case "box": return 240;
        break;
        default: return 0
    }
}

unsigned int RegularMail::getPrice() const {

    if (weight <= 20): return 50;
    if (weight > 20 && weight <= 100): return 75;
    if (weight > 100 && weight <= 500): return 140;
    return 325;
}
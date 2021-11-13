// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}

bool Product::operator < (const Product &p) const {
    if (this->getPrice() == p.getPrice()) {
        return this->getWeight() < p.getWeight();
    }
    return this->getPrice() < p.getPrice();
}
// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "piece.h"

Piece::Piece(string i, float d): id(i), diameter(d) {}

string Piece::getId() const {
    return id;
}

float Piece::getDiameter() const {
    return diameter;
}

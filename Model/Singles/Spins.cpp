//
// Created by amina on 2/26/2022.
//

#include "Spins.h"

Spins::Spins(std::string name, std::string abbr, int level, bool f, bool c,
             bool co, double bv, int goe, double goem, int shf, bool vf): Element(bv, goe, goem, shf, vf) {

    this->spinType = name;
    this->abbreviation = abbr;
    this->level = level;
    this->flyingFlag = f;
    this->changeofFootFlag = c;
    this->comboFlag = co;
}

Spins::~Spins() {

}

std::string Spins::getName() {
    return this->spinType;
}

void Spins::setName(std::string n) {
    this->spinType = n;
}

bool Spins::getFlyingFlag() {
    return this->flyingFlag;
}

void Spins::setFlyingFlag(bool f) {
    this->flyingFlag = f;
}

bool Spins::getChangeOfFootFlag() {
    return this->changeofFootFlag;
}

void Spins::setChangeofFootFlag(bool c) {
    this->changeofFootFlag = c;
}

bool Spins::getCombinationFlag() {
    return this->comboFlag;
}

void Spins::setCombinationFlag(bool c) {
    this->comboFlag = c;
}

std::string Spins::getAbbreviation() {
    return this->abbreviation;
}

void Spins::setAbbreviation(std::string a) {
    this->abbreviation = a;
}

int Spins::getLevel() {
    return this->level;
}

void Spins::setLevel(int l) {
    this->level = l;
}

std::string Spins::toString() {
    std::string name = "";

    if(flyingFlag)
        name += "F";

    if(changeofFootFlag)
        name += "C";

    if(comboFlag){
        name += "CoSp";
    }
    else{
        name += abbreviation;

    }
    if(this->level == 0)
        name += "B";
    else
        name += std::to_string(this->level);

    return name;
}

Spins::Spins(const Spins &s): Element(s), abbreviation{s.abbreviation}, level{s.level}, flyingFlag{s.flyingFlag},
                              changeofFootFlag{s.changeofFootFlag}, comboFlag{s.comboFlag}{

}
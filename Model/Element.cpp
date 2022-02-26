//
// Created by amina on 2/26/2022.
//

#include "Element.h"

Element::Element(double bv, int goe, double goem, int shf, bool vf){

    BaseValue = bv;
    GOE = goe;
    GOEMark = goem;
    secondHalfFlag = shf;
    validFlag = vf;
}

double Element::getBaseValue() {
    if(this->validFlag)
        return this->BaseValue;
    else
        return 0;
}

void Element::setBaseValue(double bv) {
    this->BaseValue = bv;
}

int Element::getGOE() {
    return this->GOE;
}

void Element::setGOE(int goe) {
    this->GOE = goe;
}

double Element::getGOEMark() {
    if(this->validFlag)
        return this->GOEMark;
    else
        return 0;
}

void Element::setGOEMark(int mark) {
    this->GOEMark = mark;
}

int Element::getSecondHalfFlag() {
    return this->secondHalfFlag;
}

void Element::setSecondHalfFlag(int flag) {
    this->secondHalfFlag = flag;
}

void Element::computeGOEMark() {

}

bool Element::getValidFlag() {
    return this->validFlag;
}

void Element::setValidFlag(bool f) {
    this->validFlag = f;
}



//
// Created by amina on 2/26/2022.
//

#include "Jumps.h"

Jumps::Jumps(std::string jump, std::string abbr, int rot,double bv, int goe, double goem, int shf, bool vf, bool ef, bool urf) : Element(bv, goe, goem, shf, vf) {
    this->jumpName = jump;
    this->abbreviation = abbr;
    this->rotationNumber = rot;
    this->edgeFlag = ef;
    this->underrotationFlag = urf;
}

bool Jumps::getUnderrotationFlag() {
    return this->underrotationFlag;
}

bool Jumps::getEdgeFlag() {
    return this->edgeFlag;
}

std::string Jumps::getJumpName() {
    return this->jumpName;
}

std::string Jumps::getAbbreviationName() {
    return this->abbreviation;
}

int Jumps::getRotationNumber() {
    return this->rotationNumber;
}

std::string Jumps::toString() {

    auto str = std::to_string(this->rotationNumber)+this->abbreviation;

    if(this->getEdgeFlag())
        str+= "e";

    if(this->getUnderrotationFlag())
        str+= "<";

    if(!this->getValidFlag())
        str += "*";

    str +="\n" + Element::toString();

    return str;
}

std::ostream &operator<<(std::ostream &os, const Jumps &j) {

    os << std::to_string(j.rotationNumber) << j.abbreviation;

    if(j.edgeFlag){
        std::string str = "e";
        os << str;
    }

    if(j.underrotationFlag) {
        std::string str = "<";
        os << str;
    }

    return os;

}

Jumps::Jumps(const Jumps &j): Element(j), abbreviation{j.abbreviation}, rotationNumber{j.rotationNumber}, edgeFlag{j.edgeFlag}, underrotationFlag{j.underrotationFlag}  {

}

Jumps &Jumps::operator=(const Jumps &j) {

    Element::operator=(j);
    this->jumpName = j.jumpName;
    this->abbreviation = j.abbreviation;
    this->rotationNumber = j.rotationNumber;
    this->edgeFlag = j.edgeFlag;
    this->underrotationFlag = j.underrotationFlag;

    return *this;
}

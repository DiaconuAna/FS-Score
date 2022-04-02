//
// Created by amina on 2/26/2022.
//

#include "StepSequence.h"

StepSequence::StepSequence(int lvl, double bv, int goe, double goem, int shf, bool vf): Element(bv, goe, goem, shf, vf) {
    this->level = lvl;
}

StepSequence::~StepSequence() {

}

std::string StepSequence::toString() {
    std::string lvl;
    if(level == 0){
        lvl = "B";
    }
    else
        lvl = std::to_string(level);
    return "Stsq" + lvl;
}

int StepSequence::getLevel() {
    return this->level;
}

void StepSequence::setLevel(int lvl) {
    this->level = lvl;
}

StepSequence::StepSequence(const StepSequence &stsq): Element(stsq), level{stsq.level} {

}

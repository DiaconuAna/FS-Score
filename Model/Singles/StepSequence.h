//
// Created by amina on 2/26/2022.
//

#ifndef FS_SCORE_V2_STEPSEQUENCE_H
#define FS_SCORE_V2_STEPSEQUENCE_H


#include <Model/Element.h>

class StepSequence : public Element {

private:
    int level;
public:
    StepSequence(int lvl, double bv, int goe, double goem, int shf, bool vf);
    ~StepSequence();

    int getLevel();
    void setLevel(int lvl);

    std::string toString();

};


#endif //FS_SCORE_V2_STEPSEQUENCE_H

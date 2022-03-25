//
// Created by amina on 2/26/2022.
//

#ifndef FS_SCORE_V2_ELEMENT_H
#define FS_SCORE_V2_ELEMENT_H


#include <string>

class Element {
private:
    double BaseValue;
    int GOE;
    double GOEMark;
    int secondHalfFlag;
    bool validFlag;

public:
    Element(double bv, int goe, double goem, int shf, bool vf);
    ~Element()= default;

    double getBaseValue();
    void setBaseValue(double bv);

    bool getValidFlag();
    void setValidFlag(bool f);

    int getGOE();
    void setGOE(int goe);

    virtual double getGOEMark();
    virtual void setGOEMark(int mark);

    int getSecondHalfFlag();
    void setSecondHalfFlag(int flag);

    virtual void computeGOEMark();

    virtual std::string toString();

};


#endif //FS_SCORE_V2_ELEMENT_H

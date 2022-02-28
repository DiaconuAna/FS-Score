//
// Created by amina on 2/26/2022.
//

#ifndef FS_SCORE_V2_SPINS_H
#define FS_SCORE_V2_SPINS_H


#include <Model/Element.h>

class Spins : public Element{
private:

    std::string spinType, abbreviation;
    int level;
    bool flyingFlag;
    bool changeofFootFlag;
    bool comboFlag;

public:

    Spins(std::string name, std::string abbr, int level, bool f, bool c, bool co, double bv, int goe, double goem, int shf, bool vf);
    ~Spins();

    std::string getName();
    void setName(std::string n);
    std::string getAbbreviation();
    void setAbbreviation(std::string a);
    int getLevel();
    void setLevel(int l);
    bool getFlyingFlag();
    void setFlyingFlag(bool f);
    bool getChangeOfFootFlag();
    void setChangeofFootFlag(bool c);
    bool getCombinationFlag();
    void setCombinationFlag(bool c);

    std::string toString();
};


#endif //FS_SCORE_V2_SPINS_H

//
// Created by amina on 2/26/2022.
//

#ifndef FS_SCORE_V2_JUMPS_H
#define FS_SCORE_V2_JUMPS_H


#include <Model/Element.h>

class Jumps : public Element {

private:
    std::string jumpName;
    std::string abbreviation;
    bool underrotationFlag;
    bool edgeFlag;
    int rotationNumber;

public:
    Jumps(std::string jump, std::string abbr, int rot, double bv, int goe, double goem, int shf, bool vf, bool ef, bool urf);
    ~Jumps() {

    }

    //copy constructor
    Jumps(const Jumps& j);

    std::string getJumpName();
    std::string getAbbreviationName();
    int getRotationNumber();
    bool getUnderrotationFlag();
    bool getEdgeFlag();

    friend std::ostream& operator<<(std::ostream&, const Jumps&);


    std::string toString() override;

};


#endif //FS_SCORE_V2_JUMPS_H

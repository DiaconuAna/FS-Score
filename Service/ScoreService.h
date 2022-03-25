//
// Created by amina on 8/2/2021.
//

#ifndef FS_PROGRAM_SCORE_CALCULATOR_SCORESERVICE_H
#define FS_PROGRAM_SCORE_CALCULATOR_SCORESERVICE_H


#include <Repository/ElementsRepo.h>

class ScoreService {

private:
    ElementsRepo* elementsRepository;

public:
    explicit ScoreService(ElementsRepo& er);

    std::vector<Element*> getElements();
    std::vector<Jumps*> getJumps();
    std::vector<StepSequence*> getStsq();
    std::vector<Spins*> getSpins();

    Spins* getSpin(bool flyingFlag, bool changeFlag, std::string name, int level);
    Jumps* getJump(bool urflag, bool edgeflag, int level, std::string name);

    void getElementScores(std::vector<Element*> elements);


    ~ScoreService();

};


#endif //FS_PROGRAM_SCORE_CALCULATOR_SCORESERVICE_H

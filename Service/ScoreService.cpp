//
// Created by amina on 8/2/2021.
//

#include <algorithm>
#include <iostream>
#include <Exception/ElementException.h>
#include "ScoreService.h"

ScoreService::ScoreService(ElementsRepo& er): elementsRepository{&er} {

}

std::vector<Element*> ScoreService::getElements() {
    return elementsRepository->getElements();
}

ScoreService::~ScoreService() {

}

std::vector<Jumps *> ScoreService::getJumps() {
    return elementsRepository->getJumps();
}

std::vector<StepSequence *> ScoreService::getStsq() {
    return elementsRepository->getStsqs();
}

std::vector<Spins *> ScoreService::getSpins() {
    return elementsRepository->getSpins();
}


Spins *ScoreService::getSpin(bool flyingFlag, bool changeFlag, std::string name, int level) {
    std::vector<Spins*> spins = this->getSpins();


    //   auto it = std::copy_if (foo.begin(), foo.end(), bar.begin(), [](int i){return !(i<0);} );
    //   bar.resize(std::distance(bar.begin(),it));  // shrink container to new size

    std::vector<Spins*> levelSpins(spins.size());
    auto it = std::copy_if(spins.begin(), spins.end(), levelSpins.begin(), [&level, &changeFlag, &flyingFlag, &name](
            const auto& x)
            {return x->getLevel() == level && x->getChangeOfFootFlag() == changeFlag
            && x->getFlyingFlag() == flyingFlag && x->getAbbreviation() == name;});
    levelSpins.resize(std::distance(levelSpins.begin(), it));

//    for(const auto& s: levelSpins){
//        std::cout<<s->toString()<<"\n";
//    }

    return levelSpins[0];
}

Jumps *ScoreService::getJump(bool urflag, bool edgeflag, int level, std::string name) {
    std::vector<Jumps*> jumps = this->getJumps();
    int ok;

    if(edgeflag){
        if(name == "Flip" || name == "Lutz")
            ok = 1;
        else ok = 0;
    }
    else
        ok = 1;

    if(ok){
    std::vector<Jumps*> levelJumps(jumps.size());
    auto it = std::copy_if(jumps.begin(), jumps.end(), levelJumps.begin(), [&level, &urflag, &edgeflag, &name](
            const auto&x){
        return x->getRotationNumber() == level && x->getUnderrotationFlag() == urflag && x->getEdgeFlag() == edgeflag &&
        x->getJumpName() == name;
    });

    levelJumps.resize(std::distance(levelJumps.begin(), it));

    // !! you can only have edge calls in flip and lutz

    return levelJumps[0];}

    throw ElementException("You do not have edge calls on toe jumps! (Axel/Loop/Salchow) and Toeloop");

}

void ScoreService::getElementScores(std::vector<Element *> elements) {
    for(auto& el: elements)
        std::cout<<el->toString()<<"\n";
}


//
// Created by amina on 8/2/2021.
//

#include <algorithm>
#include <iostream>
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


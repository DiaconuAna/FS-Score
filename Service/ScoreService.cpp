//
// Created by amina on 8/2/2021.
//

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

//
// Created by amina on 2/26/2022.
//

#include "ElementsRepo.h"

ElementsRepo::ElementsRepo() {
    populateJumps();
}

ElementsRepo::~ElementsRepo() {
    int s = this->elements.size();

    for(int i=0;i<s;i++)
        delete elements[i];

}

void ElementsRepo::populateJumps() {

    // single jumps
    this->elements.push_back(new Jumps("Lutz","Lz",1,0.6,0,0,0, true,false, false));
    this->elements.push_back(new Jumps("Flip","F",1,0.5,0,0,0, true, false, false));
    this->elements.push_back(new Jumps("Toeloop","T",1,0.4,0,0,0, true, false, false));
    this->elements.push_back(new Jumps("Salchow","S",1,0.4,0,0,0, true, false, false));
    this->elements.push_back(new Jumps("Loop","Lo",1,0.5,0,0,0, true, false, false));
    this->elements.push_back(new Jumps("Euler","Eu",1,0.5,0,0,0, true, false, false));

    // single jumps with calls
    this->elements.push_back(new Jumps("Lutz","Lz",1,0.48,0,0,0, true, true, false));
    this->elements.push_back(new Jumps("Lutz","Lz",1,0.48,0,0,0, true, false, true));
    this->elements.push_back(new Jumps("Lutz","Lz",1,0.36,0,0,0, true, true, true));

    this->elements.push_back(new Jumps("Flip","F",1,0.4,0,0,0, true, true, false));
    this->elements.push_back(new Jumps("Flip","F",1,0.4,0,0,0, true, false, true));
    this->elements.push_back(new Jumps("Flip","F",1,0.3,0,0,0, true, true, true));


    this->elements.push_back(new Jumps("Toeloop","T",1,0.32,0,0,0, true, false, true));
    this->elements.push_back(new Jumps("Salchow","S",1,0.32,0,0,0, true, false, true));
    this->elements.push_back(new Jumps("Loop","Lo",1,0.4,0,0,0, true, false, true));




}

void ElementsRepo::addElement(Element* e) {
    this->elements.push_back(e);

}

std::vector<Element *> ElementsRepo::getElements() {
    return this->elements;
}

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
    this->jumps.push_back(new Jumps("Lutz","Lz",1,0.6,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Flip","F",1,0.5,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Toeloop","T",1,0.4,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Salchow","S",1,0.4,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Loop","Lo",1,0.5,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Euler","Eu",1,0.5,0,0,0, true, false, false));

    // single jumps with calls
    this->jumps.push_back(new Jumps("Lutz","Lz",1,0.48,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Lutz","Lz",1,0.48,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Lutz","Lz",1,0.36,0,0,0, true, true, true));

    this->jumps.push_back(new Jumps("Flip","F",1,0.4,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Flip","F",1,0.4,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Flip","F",1,0.3,0,0,0, true, true, true));


    this->jumps.push_back(new Jumps("Toeloop","T",1,0.32,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Salchow","S",1,0.32,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Loop","Lo",1,0.4,0,0,0, true, false, true));

    //double jumps & Axel
    this->jumps.push_back(new Jumps("Axel","A",1,1.1,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Lutz","Lz",2,2.1,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Flip","F",2,1.8,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Toeloop","T",2,1.3,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Salchow","S",2,1.3,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Loop","Lo",2,1.7,0,0,0, true, false, false));

    // double jumps with calls
    this->jumps.push_back(new Jumps("Axel","A",1,0.88,0,0,0, true,false, true));

    this->jumps.push_back(new Jumps("Lutz","Lz",2,1.68,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Lutz","Lz",2,1.68,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Lutz","Lz",2,1.26,0,0,0, true, true, true));

    this->jumps.push_back(new Jumps("Flip","F",2,1.44,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Flip","F",2,1.44,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Flip","F",2,1.08,0,0,0, true, true, true));


    this->jumps.push_back(new Jumps("Toeloop","T",2,1.04,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Salchow","S",2,1.04,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Loop","Lo",2,1.36,0,0,0, true, false, true));

    // triple jumps and 2Axel
    this->jumps.push_back(new Jumps("Axel","A",2,3.3,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Lutz","Lz",3,5.9,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Flip","F",3,5.3,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Toeloop","T",3,4.2,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Salchow","S",3,4.3,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Loop","Lo",3,4.9,0,0,0, true, false, false));

    // triple jumps with calls
    this->jumps.push_back(new Jumps("Axel","A",2,2.64,0,0,0, true,false, true));

    this->jumps.push_back(new Jumps("Lutz","Lz",3,4.72,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Lutz","Lz",3,4.72,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Lutz","Lz",3,3.54,0,0,0, true, true, true));

    this->jumps.push_back(new Jumps("Flip","F",3,4.24,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Flip","F",3,4.24,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Flip","F",3,3.18,0,0,0, true, true, true));

    this->jumps.push_back(new Jumps("Toeloop","T",3,3.36,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Salchow","S",3,3.44,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Loop","Lo",3,3.92,0,0,0, true, false, true));

    

}

void ElementsRepo::addElement(Element* e) {
    this->elements.push_back(e);

}

std::vector<Element *> ElementsRepo::getElements() {
    return this->elements;
}

std::vector<Jumps *> ElementsRepo::getJumps() {
    return this->jumps;
}

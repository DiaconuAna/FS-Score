//
// Created by amina on 2/26/2022.
//

#include "ElementsRepo.h"

ElementsRepo::ElementsRepo() {
    populateJumps();
    populateStepSequences();
    populateSpins();
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

    // quad jumps + triple axel
    this->jumps.push_back(new Jumps("Axel","A",3,8,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Axel","A",4,12.5,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Lutz","Lz",4,11.5,0,0,0, true,false, false));
    this->jumps.push_back(new Jumps("Flip","F",4,11,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Toeloop","T",4,9.5,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Salchow","S",4,9.7,0,0,0, true, false, false));
    this->jumps.push_back(new Jumps("Loop","Lo",4,10.5,0,0,0, true, false, false));

    // quad jumps with calls
    this->jumps.push_back(new Jumps("Axel","A",3,6.4,0,0,0, true,false, true));
    this->jumps.push_back(new Jumps("Axel","A",4,10,0,0,0, true,false, true));


    this->jumps.push_back(new Jumps("Lutz","Lz",4,9.2,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Lutz","Lz",4,9.2,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Lutz","Lz",4,6.9,0,0,0, true, true, true));

    this->jumps.push_back(new Jumps("Flip","F",4,8.8,0,0,0, true, true, false));
    this->jumps.push_back(new Jumps("Flip","F",4,8.8,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Flip","F",4,6.6,0,0,0, true, true, true));

    this->jumps.push_back(new Jumps("Toeloop","T",4,7.6,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Salchow","S",4,7.76,0,0,0, true, false, true));
    this->jumps.push_back(new Jumps("Loop","Lo",4,8.4,0,0,0, true, false, true));

}

void ElementsRepo::populateStepSequences() {
    stsqs.push_back(new StepSequence{0,1.5,0,0,0,true});
    stsqs.push_back(new StepSequence{1,1.8,0,0,0,true});
    stsqs.push_back(new StepSequence{2,2.6,0,0,0,true});
    stsqs.push_back(new StepSequence{3,3.3,0,0,0,true});
    stsqs.push_back(new StepSequence{4,3.9,0,0,0,true});
}

void ElementsRepo::populateSpins() {

    //basic positions
    spins.push_back(new Spins("Upright","USp",0,false,false,false,1,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",1,false,false,false,1.2,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",2,false,false,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",3,false,false,false,1.9,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",4,false,false,false,2.4,0,0,0,true));

    spins.push_back(new Spins("Layback","LSp",0,false,false,false,1.2,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",1,false,false,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",2,false,false,false,1.9,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",3,false,false,false,2.4,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",4,false,false,false,2.7,0,0,0,true));

    spins.push_back(new Spins("Camel","CSp",0,false,false,false,1.1,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",1,false,false,false,1.4,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",2,false,false,false,1.8,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",3,false,false,false,2.3,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",4,false,false,false,2.6,0,0,0,true));

    spins.push_back(new Spins("Sit","SSp",0,false,false,false,1.1,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",1,false,false,false,1.3,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",2,false,false,false,1.6,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",3,false,false,false,2.1,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",4,false,false,false,2.5,0,0,0,true));

    // flying spins
    spins.push_back(new Spins("Upright","USp",0,true,false,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",1,true,false,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",2,true,false,false,2,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",3,true,false,false,2.4,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",4,true,false,false,2.9,0,0,0,true));

    spins.push_back(new Spins("Upright","USpV",0,true,false,false,1.13,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",1,true,false,false,1.28,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",2,true,false,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",3,true,false,false,1.8,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",4,true,false,false,2.18,0,0,0,true));

    spins.push_back(new Spins("Layback","LSp",0,true,false,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",1,true,false,false,2,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",2,true,false,false,2.4,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",3,true,false,false,2.9,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",4,true,false,false,3.2,0,0,0,true));

    spins.push_back(new Spins("Layback","LSpV",0,true,false,false,1.28,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",1,true,false,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",2,true,false,false,1.8,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",3,true,false,false,2.18,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",4,true,false,false,2.40,0,0,0,true));

    spins.push_back(new Spins("Camel","CSp",0,true,false,false,1.6,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",1,true,false,false,1.9,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",2,true,false,false,2.3,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",3,true,false,false,2.8,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",4,true,false,false,3.2,0,0,0,true));

    spins.push_back(new Spins("Camel","CSpV",0,true,false,false,1.2,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",1,true,false,false,1.43,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",2,true,false,false,1.73,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",3,true,false,false,2.1,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",4,true,false,false,2.4,0,0,0,true));

    spins.push_back(new Spins("Sit","SSp",0,true,false,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",1,true,false,false,2,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",2,true,false,false,2.3,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",3,true,false,false,2.6,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",4,true,false,false,3,0,0,0,true));

    spins.push_back(new Spins("Sit","SSpV",0,true,false,false,1.28,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",1,true,false,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",2,true,false,false,1.73,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",3,true,false,false,1.95,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",4,true,false,false,2.25,0,0,0,true));

    // change of foot spins
    spins.push_back(new Spins("Upright","USp",0,false,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",1,false,true,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",2,false,true,false,2,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",3,false,true,false,2.4,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",4,false,true,false,2.9,0,0,0,true));

    spins.push_back(new Spins("Upright","USpV",0,false,true,false,1.13,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",1,false,true,false,1.28,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",2,false,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",3,false,true,false,1.8,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",4,false,true,false,2.18,0,0,0,true));

    spins.push_back(new Spins("Layback","LSp",0,false,true,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",1,false,true,false,2,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",2,false,true,false,2.4,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",3,false,true,false,2.9,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",4,false,true,false,3.2,0,0,0,true));

    spins.push_back(new Spins("Layback","LSpV",0,false,true,false,1.28,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",1,false,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",2,false,true,false,1.8,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",3,false,true,false,2.18,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",4,false,true,false,2.40,0,0,0,true));

    spins.push_back(new Spins("Camel","CSp",0,false,true,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",1,false,true,false,2,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",2,false,true,false,2.3,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",3,false,true,false,2.8,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",4,false,true,false,3.2,0,0,0,true));

    spins.push_back(new Spins("Camel","CSpV",0,false,true,false,1.2,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",1,false,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",2,false,true,false,1.73,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",3,false,true,false,2.1,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",4,false,true,false,2.4,0,0,0,true));

    spins.push_back(new Spins("Sit","SSp",0,false,true,false,1.6,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",1,false,true,false,1.9,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",2,false,true,false,2.3,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",3,false,true,false,2.6,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",4,false,true,false,3,0,0,0,true));

    spins.push_back(new Spins("Sit","SSpV",0,false,true,false,1.20,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",1,false,true,false,1.43,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",2,false,true,false,1.73,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",3,false,true,false,1.95,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",4,false,true,false,2.25,0,0,0,true));

    // spin combo with change of position and NO change of foot
    spins.push_back(new Spins("Combo","CoSp",0,false,false,true,1.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",1,false,false,true,1.7,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",2,false,false,true,2,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",3,false,false,true,2.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",4,false,false,true,3,0,0,0,true));

    spins.push_back(new Spins("Combo","CoSpV",0,false,false,true,1.13,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",1,false,false,true,1.28,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",2,false,false,true,1.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",3,false,false,true,1.88,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",4,false,false,true,2.25,0,0,0,true));

    // spin combo with change of position and change of foot
    spins.push_back(new Spins("Combo","CoSp",0,false,true,true,1.7,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",1,false,true,true,2,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",2,false,true,true,2.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",3,false,true,true,3,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",4,false,true,true,3.5,0,0,0,true));

    spins.push_back(new Spins("Combo","CoSpV",0,false,true,true,1.28,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",1,false,true,true,1.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",2,false,true,true,1.88,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",3,false,true,true,2.25,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",4,false,true,true,2.63,0,0,0,true));

    // flying + other spins
    // change of foot spins
    spins.push_back(new Spins("Upright","USp",0,true,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",1,true,true,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",2,true,true,false,2,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",3,true,true,false,2.4,0,0,0,true));
    spins.push_back(new Spins("Upright","USp",4,true,true,false,2.9,0,0,0,true));

    spins.push_back(new Spins("Upright","USpV",0,true,true,false,1.13,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",1,true,true,false,1.28,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",2,true,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",3,true,true,false,1.8,0,0,0,true));
    spins.push_back(new Spins("Upright","USpV",4,true,true,false,2.18,0,0,0,true));

    spins.push_back(new Spins("Layback","LSp",0,true,true,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",1,true,true,false,2,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",2,true,true,false,2.4,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",3,true,true,false,2.9,0,0,0,true));
    spins.push_back(new Spins("Layback","LSp",4,true,true,false,3.2,0,0,0,true));

    spins.push_back(new Spins("Layback","LSpV",0,true,true,false,1.28,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",1,true,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",2,true,true,false,1.8,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",3,true,true,false,2.18,0,0,0,true));
    spins.push_back(new Spins("Layback","LSpV",4,true,true,false,2.40,0,0,0,true));

    spins.push_back(new Spins("Camel","CSp",0,true,true,false,1.7,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",1,true,true,false,2,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",2,true,true,false,2.3,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",3,true,true,false,2.8,0,0,0,true));
    spins.push_back(new Spins("Camel","CSp",4,true,true,false,3.2,0,0,0,true));

    spins.push_back(new Spins("Camel","CSpV",0,true,true,false,1.2,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",1,true,true,false,1.5,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",2,true,true,false,1.73,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",3,true,true,false,2.1,0,0,0,true));
    spins.push_back(new Spins("Camel","CSpV",4,true,true,false,2.4,0,0,0,true));

    spins.push_back(new Spins("Sit","SSp",0,true,true,false,1.6,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",1,true,true,false,1.9,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",2,true,true,false,2.3,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",3,true,true,false,2.6,0,0,0,true));
    spins.push_back(new Spins("Sit","SSp",4,true,true,false,3,0,0,0,true));

    spins.push_back(new Spins("Sit","SSpV",0,true,true,false,1.20,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",1,true,true,false,1.43,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",2,true,true,false,1.73,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",3,true,true,false,1.95,0,0,0,true));
    spins.push_back(new Spins("Sit","SSpV",4,true,true,false,2.25,0,0,0,true));

    // spin combo with change of position and NO change of foot
    spins.push_back(new Spins("Combo","CoSp",0,true,false,true,1.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",1,true,false,true,1.7,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",2,true,false,true,2,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",3,true,false,true,2.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",4,true,false,true,3,0,0,0,true));

    spins.push_back(new Spins("Combo","CoSpV",0,true,false,true,1.13,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",1,true,false,true,1.28,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",2,true,false,true,1.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",3,true,false,true,1.88,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",4,true,false,true,2.25,0,0,0,true));

    // spin combo with change of position and change of foot
    spins.push_back(new Spins("Combo","CoSp",0,true,true,true,1.7,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",1,true,true,true,2,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",2,true,true,true,2.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",3,true,true,true,3,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSp",4,true,true,true,3.5,0,0,0,true));

    spins.push_back(new Spins("Combo","CoSpV",0,true,true,true,1.28,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",1,true,true,true,1.5,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",2,true,true,true,1.88,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",3,true,true,true,2.25,0,0,0,true));
    spins.push_back(new Spins("Combo","CoSpV",4,true,true,true,2.63,0,0,0,true));

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

std::vector<StepSequence *> ElementsRepo::getStsqs() {
    return this->stsqs;
}

std::vector<Spins *> ElementsRepo::getSpins() {
    return this->spins;
}

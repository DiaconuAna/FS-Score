//
// Created by amina on 2/26/2022.
//

#ifndef FS_SCORE_V2_ELEMENTSREPO_H
#define FS_SCORE_V2_ELEMENTSREPO_H


#include <vector>
#include <Model/Element.h>
#include <Model/Singles/Jumps.h>


class ElementsRepo {
private:
    std::vector<Element*> elements;
    std::vector<Jumps*> jumps;
public:
    ElementsRepo();
    ~ElementsRepo();

    void populateJumps();
    void addElement(Element* e);


    std::vector<Element*> getElements();
    std::vector<Jumps*> getJumps();


};


#endif //FS_SCORE_V2_ELEMENTSREPO_H

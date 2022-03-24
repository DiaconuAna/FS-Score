//
// Created by amina on 7/31/2021.
//


#include <iostream>
#include <QApplication>
#include <QIcon>
#include <Repository/ElementsRepo.h>
#include <Service/ScoreService.h>
#include "GUI/mainGUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("D:/Personal projects/FS Score v2/Resources/figure-skating.ico"));

    ElementsRepo repo;
    ScoreService s{repo};
    //s.getSpin(true, true, "CoSp",4);

    mainGUI gui{s};
    gui.setFixedSize(300,350);

    gui.setStyleSheet("background-image:url(D:/Personal projects/FS Score v2/Resources/icee.jpg); background-position: center; ");
    gui.show();



    //for(auto* el: repo.getSpins())
       //std::cout<<el->toString()<<"\n";
//
    a.exec();


    return 0;
}

//
// Created by amina on 7/31/2021.
//


#include <iostream>
#include <QApplication>
#include <QIcon>
#include <Repository/ElementsRepo.h>
#include "GUI/mainGUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("D:/Personal projects/FS Score v2/figure-skating.ico"));

    mainGUI gui{};
    gui.setFixedSize(300,350);

    gui.setStyleSheet("background-image:url(D:/Personal projects/FS Score v2/icee.jpg); background-position: center; ");
    gui.show();

    ElementsRepo repo = ElementsRepo();

    for(auto* el: repo.getElements())
        std::cout<<el->toString()<<"\n";

    a.exec();


    return 0;
}

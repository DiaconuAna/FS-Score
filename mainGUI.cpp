//
// Created by amina on 8/2/2021.
//

#include <QFormLayout>
#include "mainGUI.h"

mainGUI::mainGUI() {
    initGUI();
    connectGUI();
}

mainGUI::~mainGUI() {
    delete this->LadiesButton;
    delete this->MenButton;
    delete this->PairsButton;
    delete this->IceDanceButton;
    delete this->JuniorPairsButton;
    delete this->JuniorLadiesButton;
    delete this->JuniorIceDanceButton;
    delete this->JuniorMenButton;
}

void mainGUI::initGUI() {

    auto* mainLayout = new QVBoxLayout{this};


    this->LadiesButton = new QPushButton{"Ladies"};
    this->MenButton = new QPushButton{"Men"};
    this->PairsButton = new QPushButton{"Pairs"};
    this->IceDanceButton = new QPushButton{"Ice Dance"};
    this->JuniorLadiesButton = new QPushButton{"Junior Ladies"};
    this->JuniorMenButton = new QPushButton{"Junior Men"};
    this->JuniorIceDanceButton = new QPushButton{"Junior Ice Dance"};
    this->JuniorPairsButton = new QPushButton{"Junior Pairs"};

    mainLayout->addWidget(this->LadiesButton);
    mainLayout->addWidget(this->JuniorLadiesButton);
    mainLayout->addWidget(this->MenButton);
    mainLayout->addWidget(this->JuniorMenButton);
    mainLayout->addWidget(this->PairsButton);
    mainLayout->addWidget(this->JuniorPairsButton);
    mainLayout->addWidget(this->IceDanceButton);
    mainLayout->addWidget(this->JuniorIceDanceButton);

    //this->programDialog = new QDialog{this};

}

void mainGUI::connectGUI() {
    QObject::connect(this->LadiesButton, &QPushButton::clicked, this, &mainGUI::openLadiesWindow);

}

void mainGUI::openLadiesWindow() {
    this->ladiesWindow = new LadiesFSWindow();
    ladiesWindow->show();

}

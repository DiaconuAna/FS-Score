//
// Created by amina on 8/2/2021.
//

#include <QFormLayout>
#include <iostream>
#include <QMessageBox>
#include "LadiesFSWindow.h"

LadiesFSWindow::LadiesFSWindow(ScoreService& s): _service{s} {
    initGUI();
    connect();
}

LadiesFSWindow::~LadiesFSWindow() {
    delete this->nameEdit;
    delete this->ladiesLong;
    delete this->ladiesShort;
    delete this->mainMenu;

}

void LadiesFSWindow::initGUI() {

    //auto* ladiesWindow = new QVBoxLayout{this};
    this->mainMenu = new QVBoxLayout{this};
    auto* label = new QLabel{};
    label->setText("Skater name: ");
    this->nameEdit = new QLineEdit{};

    auto* skaterName = new QFormLayout{};
    skaterName->addRow(label, nameEdit);



    this->ladiesShort = new QPushButton{"Short Program"};
    this->ladiesLong = new QPushButton{"Long Program"};

    mainMenu->addLayout(skaterName);
    mainMenu->addWidget(ladiesShort);
    mainMenu->addWidget(ladiesLong);


}

//
//void LadiesFSWindow::FSWidget() {
//    this->FPMenu = new QVBoxLayout{this};
//    QString skaterName = this->nameEdit->text();
//
//    auto* nameLabel = new QLabel;
//    nameLabel->setText(skaterName);
//    FPMenu->addWidget(nameLabel);
//
//}

void LadiesFSWindow::connect() {
    QObject::connect(this->ladiesShort, &QPushButton::clicked, this, &LadiesFSWindow::openSP);
    //QObject::connect(this->ladiesLong, &QPushButton::clicked, this, &LadiesFSWindow::FSWidget);
   // QObject::connect(this->deductionBox, &QSpinBox::valueChanged, this, &LadiesFSWindow::aux);
    //connectSPPCS();

//    QObject::connect(this->SPpcs[0], qOverload<double>(&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
//    QObject::connect(this->SPpcs[1], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
//    QObject::connect(this->SPpcs[2], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
//    QObject::connect(this->SPpcs[3], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
//    QObject::connect(this->SPpcs[4], qOverload<double>(&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::aux);
//    QObject::connect(this->deductionBox, &QSpinBox::valueChanged, this, &LadiesFSWindow::aux);


}


//
//void LadiesFSWindow::computeSPPCS() {
//    float pcs = 0;
//    std::cout<<"hello\n";
//    std::cout<<this->SPpcs[0]->value()<<"\n";
//    std::cout<<this->SPpcs[1]->value()<<"\n";
//    std::cout<<this->SPpcs[2]->value()<<"\n";
//    std::cout<<this->SPpcs[3]->value()<<"\n";
//    std::cout<<this->SPpcs[4]->value()<<"\n";
//
//}
//
//void LadiesFSWindow::connectSPPCS() {
//    if(this->SPpcs.size() == 5) {
//        for (int i = 0; i < 5; i++) {
//        QObject::connect(this->SPpcs[i], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
//    }
////        QObject::connect(this->SPpcs[1], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
////        QObject::connect(this->SPpcs[2], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
////        QObject::connect(this->SPpcs[3], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
////        QObject::connect(this->SPpcs[4], (&QDoubleSpinBox::valueChanged), this, &LadiesFSWindow::computeSPPCS);
//    }
//
//
//
//}




void LadiesFSWindow::openSP() {
    QString skaterName = this->nameEdit->text();

    if(skaterName == ""){
        QMessageBox msg;
        msg.setText(QString::fromStdString("Please input a name!"));
        msg.exec();
    }
    else {
        this->SPWindow = new LadiesSPWindow(skaterName.toStdString(), this->_service);
        SPWindow->show();
    }
}

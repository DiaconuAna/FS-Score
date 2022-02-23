//
// Created by amina on 8/2/2021.
//

#include <QFormLayout>
#include "LadiesFSWindow.h"

LadiesFSWindow::LadiesFSWindow() {
    initGUI();
    connect();
}

LadiesFSWindow::~LadiesFSWindow() {
    delete this->nameEdit;
    delete this->ladiesLong;
    delete this->ladiesShort;
    delete this->mainMenu;
    delete this->SPMenu;
    delete this->FPMenu;
    delete this->SPW;
    delete this->FPW;
    delete this->deductionBox;
}

void LadiesFSWindow::initGUI() {

    //auto* ladiesWindow = new QVBoxLayout{this};
    this->mainMenu = new QVBoxLayout{this};
    auto* label = new QLabel{};
    label->setText("Skater name: ");
    this->nameEdit = new QLineEdit{};

    auto* skaterName = new QFormLayout{};
    skaterName->addRow(label, nameEdit);

    this->deductionBox = new QSpinBox{};
    this->deductionBox->setRange(-10, 0);
    this->deductionBox->setSingleStep(1);
    this->deductionBox->setValue(0);


    this->ladiesShort = new QPushButton{"Short Program"};
    this->ladiesLong = new QPushButton{"Long Program"};

    mainMenu->addLayout(skaterName);
    mainMenu->addWidget(ladiesShort);
    mainMenu->addWidget(ladiesLong);

}

void LadiesFSWindow::SPWidget() {

    this->SPW = new QWidget{};
    this->SPMenu = new QVBoxLayout{this->SPW};
    QString skaterName = this->nameEdit->text();

    auto* nameLabel = new QLabel;
    nameLabel->setText(skaterName);
    //SPMenu->addWidget(nameLabel);

    auto* firstLayout = new QFormLayout{};

    auto* deductionLayout = new QFormLayout{};
    auto* deductionLabel = new QLabel{};
    deductionLabel->setText("Deduction");

    deductionLayout->addRow(deductionLabel, deductionBox);
    //deductionLayout->addWidget(deductionLabel);
    //deductionLayout->addWidget(deductionBox);


    firstLayout->addRow(skaterName, deductionLayout);

    auto* secondLayout = new QVBoxLayout{this->SPW};

    QVector<QComboBox *> elements(7);
    QVector<QSpinBox* > goes(7);

    this->SPbaseValueLabels.resize(7);
    this->SPGOEMarkLabels.resize(7);
    this->SPGOETotalLabels.resize(7);
    this->SPTotalLabels.resize(7);

    auto* gridLayout = new QGridLayout{};

    //initialising the grid layout
    gridLayout->addWidget(new QLabel{"Element"},0,0);
    gridLayout->addWidget(new QLabel{"Base Value"},0,1);
    gridLayout->addWidget(new QLabel{"GOE Mark"},0,2);
    gridLayout->addWidget(new QLabel{"GOE"},0,3);
    gridLayout->addWidget(new QLabel{"Total"},0,4);

    for(int i=0;i<7;i++){
        (elements)[i] = new QComboBox;
        goes[i] = new QSpinBox{};
        goes[i]->setRange(-5, 5);
        goes[i]->setSingleStep(1);
        goes[i]->setValue(0);

        SPbaseValueLabels[i] = new QLabel;
        SPGOEMarkLabels[i] = new QLabel;
        SPGOETotalLabels[i] = new QLabel;
        SPTotalLabels[i] = new QLabel;

        auto* lbl = new QLabel;
        lbl->setText(QString::number(i+1));
        auto* auxl = new QFormLayout;
        auxl->addRow(lbl, elements[i]);

        gridLayout->addLayout(auxl,i+1,0);
        gridLayout->addWidget(SPbaseValueLabels[i],i+1,1);
        gridLayout->addWidget(SPGOEMarkLabels[i],i+1,2);
        gridLayout->addWidget(goes[i],i+1,3);
        gridLayout->addWidget(SPTotalLabels[i],i+1,4);


    }

    //todo: total base value + value | total component score + value
    //grid layout for pcs
    //columns -> component, factor (SP: 0,8 FP: 1,6), pcs mark
    //skating skills, transition, performance, composition, interpretation
    //total component score

    gridLayout->setSpacing(5);
    secondLayout->addLayout(gridLayout);

    //auto* auxLayout = new QVBoxLayout{};
    //auxLayout->addLayout(firstLayout);
    //auxLayout->addLayout(secondLayout);

    SPMenu->addLayout(firstLayout);
    SPMenu->addLayout(secondLayout);

    SPMenu->setSpacing(0);

    SPW->resize(200,300);
    SPW->show();
}

void LadiesFSWindow::FSWidget() {
    this->FPMenu = new QVBoxLayout{this};
    QString skaterName = this->nameEdit->text();

    auto* nameLabel = new QLabel;
    nameLabel->setText(skaterName);
    FPMenu->addWidget(nameLabel);

}

void LadiesFSWindow::connect() {
    QObject::connect(this->ladiesShort, &QPushButton::clicked, this, &LadiesFSWindow::SPWidget);
    QObject::connect(this->ladiesLong, &QPushButton::clicked, this, &LadiesFSWindow::FSWidget);

}

void LadiesFSWindow::clearLayout() {



    auto* label = new QLabel{};
    label->setText("Skater name: ");

    auto* skaterName = new QFormLayout{};
    skaterName->addRow(label, nameEdit);

    mainMenu->addLayout(skaterName);
}

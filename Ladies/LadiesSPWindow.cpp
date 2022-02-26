//
// Created by amina on 8/2/2021.
//

#include <QFormLayout>
#include <iostream>
#include "LadiesSPWindow.h"

LadiesSPWindow::LadiesSPWindow(std::string name) {

    this->skaterName = name;
    initGUI();
    connect();

}

LadiesSPWindow::~LadiesSPWindow() {

    delete this->SPMenu;

    for(int i=0;i<5;i++){
        delete this->SPpcs[i];}

    for(int i=0;i<7;i++){
        delete this->SPgoes[i];}

    delete this->deductionBox;
    delete this->SPPCSLabel;
    delete this->SPTESLabel;
    delete this->SPBVLabel;

    // todo: delete the rest of the qvectors


}

void LadiesSPWindow::initGUI() {

    this->SPMenu = new QVBoxLayout{this};

    auto* nameLabel = new QLabel;
    nameLabel->setText(QString::fromStdString(skaterName));
    //SPMenu->addWidget(nameLabel);

    this->deductionBox = new QSpinBox{};
    this->deductionBox->setRange(-10, 0);
    this->deductionBox->setSingleStep(1);
    this->deductionBox->setValue(0);


    auto* firstLayout = new QGridLayout{};

    auto* deductionLabel = new QLabel{};
    deductionLabel->setText("Deduction");
    this->SPTotalLabel = new QLabel{};

    firstLayout->addWidget(nameLabel, 0, 0);
    firstLayout->addWidget(deductionBox,0 ,1);
    firstLayout->addWidget(new QLabel{"Total: "},1,0);
    firstLayout->addWidget(this->SPTotalLabel,1,1);


    //deductionLayout->addRow(deductionLabel, deductionBox);
    //deductionLayout->addWidget(deductionLabel);
    //deductionLayout->addWidget(deductionBox);


    //firstLayout->addRow(skaterName, deductionLayout);

    auto* secondLayout = new QVBoxLayout{};

    //QVector<QComboBox *> elements(7);
    //QVector<QSpinBox* > goes(7);

    this->SPelements.resize(7);
    this->SPgoes.resize(7);
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
        (SPelements)[i] = new QComboBox;
        SPgoes[i] = new QSpinBox{};
        SPgoes[i]->setRange(-5, 5);
        SPgoes[i]->setSingleStep(1);
        SPgoes[i]->setValue(0);

        SPbaseValueLabels[i] = new QLabel;
        SPGOEMarkLabels[i] = new QLabel;
        SPGOETotalLabels[i] = new QLabel;
        SPTotalLabels[i] = new QLabel;

        auto* lbl = new QLabel;
        lbl->setText(QString::number(i+1));
        auto* auxl = new QFormLayout;
        auxl->addRow(lbl, SPelements[i]);

        gridLayout->addLayout(auxl,i+1,0);
        gridLayout->addWidget(SPbaseValueLabels[i],i+1,1);
        gridLayout->addWidget(SPGOEMarkLabels[i],i+1,2);
        gridLayout->addWidget(SPgoes[i],i+1,3);
        gridLayout->addWidget(SPTotalLabels[i],i+1,4);
    }

    this->SPBVLabel = new QLabel{};
    this->SPTESLabel = new QLabel{};
    auto* tesLayout = new QGridLayout{};
    tesLayout->addWidget(new QLabel{"Total Base Value"},0,0);
    tesLayout->addWidget(SPBVLabel,0,1);
    tesLayout->addWidget(new QLabel{"Total TES: "},0,2);
    tesLayout->addWidget(SPTESLabel,0,3);




    //todo: total base value + value | total component score + value
    //grid layout for pcs
    //columns -> component, factor (SP: 0,8 FP: 1,6), pcs mark
    //skating skills, transition, performance, composition, interpretation
    //total component score

    gridLayout->setSpacing(5);
    QFrame* TESframe = new QFrame{};
    TESframe->setObjectName("TESframe");
    //TESframe->setLayout(gridLayout);

    QFrame *line2;
    line2 = new QFrame;
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Sunken);
    secondLayout->addLayout(gridLayout);
    secondLayout->addLayout(tesLayout);
    secondLayout->addWidget(line2);


    // working on the pcs part
    auto* pcsgrid = new QGridLayout{};
    auto* l1 = new QLabel{"Component"};
    auto *l2 = new QLabel{"Factor"};
    auto* l3 = new QLabel{"PCS Mark"};

    pcsgrid->addWidget(l1,0,0);
    pcsgrid->addWidget(l2,0,1);
    pcsgrid->addWidget(l3,0,2);

    pcsgrid->addWidget(new QLabel{"Skating Skills"},1,0);
    pcsgrid->addWidget(new QLabel{"Transitions"},2,0);
    pcsgrid->addWidget(new QLabel{"Performance"},3,0);
    pcsgrid->addWidget(new QLabel{"Composition"},4,0);
    pcsgrid->addWidget(new QLabel{"Interpretation"},5,0);

    SPpcs.resize(5);

    for(int i=0;i<5;i++){
        pcsgrid->addWidget(new QLabel{"0,8"},i+1,1);
        SPpcs[i] = new QDoubleSpinBox{};
        SPpcs[i]->setRange(0, 10);
        SPpcs[i]->setSingleStep(0.25);
        SPpcs[i]->setValue(8.5);
        pcsgrid->addWidget(SPpcs[i],i+1,2);
    }

    //auto* auxLayout = new QVBoxLayout{};
    //auxLayout->addLayout(firstLayout);
    //auxLayout->addLayout(secondLayout);

    QFrame *line1;
    line1 = new QFrame;
    line1->setFrameShape(QFrame::HLine);
    line1->setFrameShadow(QFrame::Sunken);

    secondLayout->addLayout(pcsgrid);

    auto* pcslay = new QGridLayout{};
    pcslay->addWidget(new QLabel{"Total Program Component Score: "},0,0);
    this->SPPCSLabel = new QLabel{};
    pcslay->addWidget(SPPCSLabel,0,1);

    secondLayout->addLayout(pcslay);

    SPMenu->addLayout(firstLayout);
    SPMenu->addWidget(line1);
    SPMenu->addLayout(secondLayout);


    SPMenu->setSpacing(0);


}

void LadiesSPWindow::connect() {
    connectPCS();
}

void LadiesSPWindow::connectPCS() {
    if (this->SPpcs.size() == 5) {
        for (int i = 0; i < 5; i++) {
            QObject::connect(this->SPpcs[i], (&QDoubleSpinBox::valueChanged), this, &LadiesSPWindow::computePCS);
        }
    }
}

void LadiesSPWindow::computePCS() {
    float pcs = 0;
    std::cout<<"hello\n";
    std::cout<<this->SPpcs[0]->value()<<"\n";
    std::cout<<this->SPpcs[1]->value()<<"\n";
    std::cout<<this->SPpcs[2]->value()<<"\n";
    std::cout<<this->SPpcs[3]->value()<<"\n";
    std::cout<<this->SPpcs[4]->value()<<"\n";
}

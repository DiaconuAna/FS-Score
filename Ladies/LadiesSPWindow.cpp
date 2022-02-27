//
// Created by amina on 8/2/2021.
//

#include <QFormLayout>
#include <iostream>
#include "LadiesSPWindow.h"

LadiesSPWindow::LadiesSPWindow(std::string name, ScoreService& s): _service{s} {

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

    delete this->j1;
    delete this->jump1;
    delete this->j2;
    delete this->jump2;
    delete this->cj;
    delete this->combojump2;
    delete this->combojump1;
    delete this->spin1;
    delete this->spin2;
    delete this->spin3;
    delete this->stsq;

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

    //this->SPelements.resize(7);



    this->SPgoes.resize(7);
    this->SPbaseValueLabels.resize(7);
    this->SPGOEMarkLabels.resize(7);
    this->SPGOETotalLabels.resize(7);
    this->SPTotalLabels.resize(7);

    auto* gridLayout = new QGridLayout{};

    this->jump1 = new QComboBox;
    this->jump2 = new QComboBox;
    this->combojump1 = new QComboBox;
    this->combojump2 = new QComboBox;
    this->j1 = new QCheckBox;
    this->j2 = new QCheckBox;
    this->cj = new QCheckBox;
    this->spin1 = new QComboBox;
    this->spin2 = new QComboBox;
    this->spin3 = new QComboBox;
    this->stsq = new QComboBox;

    //initialising the grid layout
    gridLayout->addWidget(new QLabel{"Element"},0,0);
    gridLayout->addWidget(new QLabel{"Base Value"},0,2);
    gridLayout->addWidget(new QLabel{"GOE Mark"},0,3);
    gridLayout->addWidget(new QLabel{"GOE"},0,4);
    gridLayout->addWidget(new QLabel{"Second Half"},0,5);
    gridLayout->addWidget(new QLabel{"Total"},0,6);

    gridLayout->addWidget(new QLabel{"Jump 1."},1,0);
    gridLayout->addWidget(jump1,1,1);
    gridLayout->addWidget(j1,1,5);
    gridLayout->addWidget(new QLabel{"Jump 2."},2,0);
    gridLayout->addWidget(jump2,2,1);
    gridLayout->addWidget(j2,2,5);
    gridLayout->addWidget(new QLabel{"Combination Jump."},3,0);
    auto* comboLayout = new QGridLayout{};
    comboLayout->addWidget(combojump1, 0,0);
    comboLayout->addWidget(new QLabel{"+"},0,1);
    comboLayout->addWidget(combojump2,0,2);
    gridLayout->addLayout(comboLayout,3,1);
    gridLayout->addWidget(cj,3,5);
    gridLayout->addWidget(new QLabel{"Spin 1."},4,0);
    gridLayout->addWidget(spin1,4,1);
    gridLayout->addWidget(new QLabel{"Spin 2."},5,0);
    gridLayout->addWidget(spin2,5,1);
    gridLayout->addWidget(new QLabel{"Spin 3."},6,0);
    gridLayout->addWidget(spin3,6,1);
    gridLayout->addWidget(new QLabel{"Stsq."},7,0);
    gridLayout->addWidget(stsq,7,1);

    addJumps();

    for(int i=0;i<7;i++){
        //(SPelements)[i] = new QComboBox;
        SPgoes[i] = new QSpinBox{};
        SPgoes[i]->setRange(-5, 5);
        SPgoes[i]->setSingleStep(1);
        SPgoes[i]->setValue(0);

        SPbaseValueLabels[i] = new QLabel;
        SPGOEMarkLabels[i] = new QLabel;
        SPGOETotalLabels[i] = new QLabel;
        SPTotalLabels[i] = new QLabel;

       // auto* lbl = new QLabel;
       // lbl->setText(QString::number(i+1));
        //auto* auxl = new QFormLayout;
        //auxl->addRow(lbl, SPelements[i]);

        //gridLayout->addLayout(auxl,i+1,0);
        gridLayout->addWidget(SPbaseValueLabels[i],i+1,2);
        gridLayout->addWidget(SPGOEMarkLabels[i],i+1,3);
        gridLayout->addWidget(SPgoes[i],i+1,4);
        gridLayout->addWidget(SPTotalLabels[i],i+1,6);
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
    QObject::connect(this->jump1, &QComboBox::currentIndexChanged, this, [this](){
        int index = jump1->currentIndex();
        Jumps* currentJump = this->_service.getJumps()[index-1];

        double baseValue = currentJump->getBaseValue();
        this->SPbaseValueLabels[0]->setText(QString::number(baseValue, 'f', 2));
        this->SPTotalLabels[0]->setText(QString::number(baseValue,'f',2));
        updateTotals();

    });

    QObject::connect(this->jump2, &QComboBox::currentIndexChanged, this, [this](){
        int index = jump2->currentIndex();
        Jumps* currentJump = this->_service.getJumps()[index-1];

        double baseValue = currentJump->getBaseValue();
        this->SPbaseValueLabels[1]->setText(QString::number(baseValue, 'f', 2));
        this->SPTotalLabels[1]->setText(QString::number(baseValue,'f',2));
        updateTotals();
    });

    QObject::connect(this->combojump1, &QComboBox::currentIndexChanged, this, [this](){
        int index = combojump1->currentIndex()-1;
        Jumps* currentJump = this->_service.getJumps()[index];

        double baseValue = 0;

        if(combojump2->currentIndex()!=0){
            baseValue += this->_service.getJumps()[combojump2->currentIndex()-1]->getBaseValue();
        }

        baseValue += currentJump->getBaseValue();
        this->SPbaseValueLabels[2]->setText(QString::number(baseValue, 'f', 2));
        this->SPTotalLabels[2]->setText(QString::number(baseValue,'f',2));
        updateTotals();
    });

    QObject::connect(this->combojump2, &QComboBox::currentIndexChanged, this, [this](){
        int index = combojump2->currentIndex()-1;
        Jumps* currentJump = this->_service.getJumps()[index];

        double baseValue = 0;

        if(combojump1->currentIndex()!=0){
            baseValue += this->_service.getJumps()[combojump1->currentIndex()-1]->getBaseValue();
        }

        baseValue += currentJump->getBaseValue();
        this->SPbaseValueLabels[2]->setText(QString::number(baseValue, 'f', 2));
        this->SPTotalLabels[2]->setText(QString::number(baseValue,'f',2));
        updateTotals();
    });

    QObject::connect(this->j1, &QCheckBox::stateChanged, this, [this](){

        if(this->j1->isChecked()){
            double bv = this->SPbaseValueLabels[0]->text().toDouble();
            double goe = this->SPGOEMarkLabels[0]->text().toDouble();
            bv = bv * 1.1 + goe;
            this->SPTotalLabels[0]->setText(QString::number(bv, 'f', 2));
        }
        else{
            double bv = this->SPbaseValueLabels[0]->text().toDouble();
            double goe = this->SPGOEMarkLabels[0]->text().toDouble();
            bv = bv + goe;
            this->SPTotalLabels[0]->setText(QString::number(bv, 'f', 2));
        }
        updateTotals();
    });

    QObject::connect(this->j2, &QCheckBox::stateChanged, this, [this](){

        if(this->j2->isChecked()){
            double bv = this->SPbaseValueLabels[1]->text().toDouble();
            double goe = this->SPGOEMarkLabels[1]->text().toDouble();
            bv = bv * 1.1 + goe;
            this->SPTotalLabels[1]->setText(QString::number(bv, 'f', 2));
        }
        else{
            double bv = this->SPbaseValueLabels[1]->text().toDouble();
            double goe = this->SPGOEMarkLabels[1]->text().toDouble();
            bv = bv + goe;
            this->SPTotalLabels[1]->setText(QString::number(bv, 'f', 2));
        }
        updateTotals();
    });

    QObject::connect(this->cj, &QCheckBox::stateChanged, this, [this](){

        if(this->cj->isChecked()){
            double bv = this->SPbaseValueLabels[2]->text().toDouble();
            double goe = this->SPGOEMarkLabels[2]->text().toDouble();
            bv = bv * 1.1 + goe;
            this->SPTotalLabels[2]->setText(QString::number(bv, 'f', 2));
        }
        else{
            double bv = this->SPbaseValueLabels[2]->text().toDouble();
            double goe = this->SPGOEMarkLabels[2]->text().toDouble();
            bv = bv + goe;
            this->SPTotalLabels[2]->setText(QString::number(bv, 'f', 2));
        }
        updateTotals();

    });

    connectPCS();
    connectGOE();
    connectTotalBV();
    connectTotalTES();
}

void LadiesSPWindow::connectPCS() {
    if (this->SPpcs.size() == 5) {
        for (int i = 0; i < 5; i++) {
            QObject::connect(this->SPpcs[i], (&QDoubleSpinBox::valueChanged), this, &LadiesSPWindow::computePCS);
            updateTotals();
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

void LadiesSPWindow::addJumps() {

    std::vector<Jumps*> jumps = this->_service.getJumps();

    jump1->addItem("none");
    jump2->addItem("none");
    combojump1->addItem("none");
    combojump2->addItem("none");

    for(auto* j: jumps){
        jump1->addItem(QString::fromStdString(j->toString()));
        jump2->addItem(QString::fromStdString(j->toString()));
        combojump1->addItem(QString::fromStdString(j->toString()));
        combojump2->addItem(QString::fromStdString(j->toString()));
    }

}

void LadiesSPWindow::connectGOE() {
    if (this->SPgoes.size() == 7) {
        for (int i = 0; i < 7; i++) {
            QObject::connect(this->SPgoes[i], (&QSpinBox::valueChanged), this, [this, i](){

                double bv = this->SPbaseValueLabels[i]->text().toDouble();
                //     this->GOEMark = this->GOE * 0.1 * this->BaseValue;
                double goemark = bv * 0.1 * this->SPgoes[i]->value();
                this->SPGOEMarkLabels[i]->setText(QString::number(goemark, 'f', 2));
                double newtotal = goemark + bv;
                this->SPTotalLabels[i]->setText(QString::number(newtotal, 'f', 2));
                updateTotals();
            });
        }
    }
}

void LadiesSPWindow::connectTotalBV() {
    double total = 0;
    if(this->SPbaseValueLabels.size() == 7){
        for(int i=0;i<7;i++){
            total += this->SPbaseValueLabels[i]->text().toDouble();
        }
    }
    this->SPBVLabel->setText(QString::number(total, 'f', 2));

}

void LadiesSPWindow::connectTotalTES() {
    double total = 0;
    if(this->SPTotalLabels.size() == 7){
        for(int i=0;i<7;i++){
            total += this->SPTotalLabels[i]->text().toDouble();
        }
    }
    this->SPTESLabel->setText(QString::number(total, 'f', 2));
}

void LadiesSPWindow::updateTotals() {
    connectTotalTES();
    connectTotalBV();
}

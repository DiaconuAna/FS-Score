//
// Created by amina on 8/2/2021.
//

#include <QFormLayout>
#include <iostream>
#include <Exception/ElementException.h>
#include <QMessageBox>
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
    firstLayout->addWidget(new QLabel{"Deduction:"},0,1);
    firstLayout->addWidget(deductionBox,0 ,2);
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
    this->fs1 = new QComboBox;
    this->cs1 = new QComboBox;
    this->lvls1 = new QComboBox;
    this->fs2 = new QComboBox;
    this->cs2 = new QComboBox;
    this->lvls2 = new QComboBox;
    this->fs3 = new QComboBox;
    this->cs3 = new QComboBox;
    this->lvls3 = new QComboBox;
    this->je1 = new QComboBox;
    this->je2 = new QComboBox;
    this->je3 = new QComboBox;
    this->je4 = new QComboBox;
    this->ju1 = new QComboBox;
    this->ju2 = new QComboBox;
    this->ju3 = new QComboBox;
    this->ju4 = new QComboBox;
    this->jlvl1 = new QComboBox;
    this->jlvl2 = new QComboBox;
    this->jlvl3 = new QComboBox;
    this->jlvl4 = new QComboBox;




    //initialising the grid layout
    gridLayout->addWidget(new QLabel{"Element"},0,0);
    gridLayout->addWidget(new QLabel{"Base Value"},0,2);
    gridLayout->addWidget(new QLabel{"GOE Mark"},0,3);
    gridLayout->addWidget(new QLabel{"GOE"},0,4);
    gridLayout->addWidget(new QLabel{"Second Half"},0,5);
    gridLayout->addWidget(new QLabel{"Total"},0,6);

    gridLayout->addWidget(new QLabel{"Jump 1."},1,0);
    auto* jump1Layout = new QGridLayout{};
    jump1Layout->addWidget(jlvl1,0,0);
    jump1Layout->addWidget(jump1,0,1);
    jump1Layout->addWidget(je1,0,2);
    jump1Layout->addWidget(ju1,0,3);
    gridLayout->addLayout(jump1Layout,1,1);
    gridLayout->addWidget(j1,1,5);
    gridLayout->addWidget(new QLabel{"Jump 2."},2,0);
    auto* jump2Layout = new QGridLayout{};
    jump2Layout->addWidget(jlvl2,0,0);
    jump2Layout->addWidget(jump2,0,1);
    jump2Layout->addWidget(je2,0,2);
    jump2Layout->addWidget(ju2,0,3);
    gridLayout->addLayout(jump2Layout,2,1);
    gridLayout->addWidget(j2,2,5);
    gridLayout->addWidget(new QLabel{"Combination Jump."},3,0);
    auto* comboLayout = new QGridLayout{};
    auto* combojump1Layout = new QGridLayout{};
    combojump1Layout->addWidget(jlvl3,0,0);
    combojump1Layout->addWidget(combojump1,0,1);
    combojump1Layout->addWidget(je3,0,2);
    combojump1Layout->addWidget(ju3,0,3);
    comboLayout->addLayout(combojump1Layout, 0,0);
    comboLayout->addWidget(new QLabel{"+"},0,1);
    auto* combojump2Layout = new QGridLayout{};
    combojump2Layout->addWidget(jlvl4,0,0);
    combojump2Layout->addWidget(combojump2,0,1);
    combojump2Layout->addWidget(je4,0,2);
    combojump2Layout->addWidget(ju4,0,3);
    comboLayout->addLayout(combojump2Layout,0,2);
    gridLayout->addLayout(comboLayout,3,1);
    gridLayout->addWidget(cj,3,5);

    auto* spin1Layout = new QGridLayout{};
    spin1Layout->addWidget(fs1,0,0);
    spin1Layout->addWidget(cs1,0,1);
    spin1Layout->addWidget(spin1,0,2);
    spin1Layout->addWidget(lvls1,0,3);

    gridLayout->addWidget(new QLabel{"Spin 1."},4,0);
    gridLayout->addLayout(spin1Layout,4,1);

    auto* spin2Layout = new QGridLayout{};
    spin2Layout->addWidget(fs2,0,0);
    spin2Layout->addWidget(cs2,0,1);
    spin2Layout->addWidget(spin2,0,2);
    spin2Layout->addWidget(lvls2,0,3);

    gridLayout->addWidget(new QLabel{"Spin 2."},5,0);
    gridLayout->addLayout(spin2Layout,5,1);

    auto* spin3Layout = new QGridLayout{};
    spin3Layout->addWidget(fs3,0,0);
    spin3Layout->addWidget(cs3,0,1);
    spin3Layout->addWidget(spin3,0,2);
    spin3Layout->addWidget(lvls3,0,3);

    gridLayout->addWidget(new QLabel{"Spin 3."},6,0);
    gridLayout->addLayout(spin3Layout,6,1);

    gridLayout->addWidget(new QLabel{"Stsq."},7,0);
    gridLayout->addWidget(stsq,7,1);

    addJumps();
    addStsq();
    addSpins();

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

    auto* thirdLayout = new QGridLayout;
    this->SPComputeScore = new QPushButton{"Compute Score"};
    this->SPClearScore = new QPushButton{"Clear Score"};

    thirdLayout->addWidget(SPComputeScore,0,0);
    thirdLayout->addWidget(SPClearScore,0,1);

    SPMenu->addWidget(line1);
    SPMenu->addLayout(thirdLayout);

    SPMenu->setSpacing(0);


}

void LadiesSPWindow::connect() {

    QObject::connect(this->SPClearScore, &QPushButton::clicked, this, &LadiesSPWindow::clearScore);

    QObject::connect(this->stsq, &QComboBox::currentIndexChanged, this, [this](){
       int index = stsq->currentIndex()-1;
       if(index >= 0) {
           StepSequence *s = this->_service.getStsq()[index];

           double baseValue = s->getBaseValue();
           this->SPbaseValueLabels[6]->setText(QString::number(baseValue, 'f', 2));
           this->SPTotalLabels[6]->setText(QString::number(baseValue, 'f', 2));
           updateTotals();
       }

    });

//    QObject::connect(this->jump1, &QComboBox::currentIndexChanged, this, [this]() {
//        int index = jump1->currentIndex();
//        if (index - 1 >= 0) {
//        Jumps *currentJump = this->_service.getJumps()[index - 1];
//
//        double baseValue = currentJump->getBaseValue();
//        this->SPbaseValueLabels[0]->setText(QString::number(baseValue, 'f', 2));
//        this->SPTotalLabels[0]->setText(QString::number(baseValue, 'f', 2));
//        updateTotals();
//    }
//
//    });

//    QObject::connect(this->jump2, &QComboBox::currentIndexChanged, this, [this](){
//        int index = jump2->currentIndex();
//        if(index - 1 >= 0) {
//            Jumps *currentJump = this->_service.getJumps()[index - 1];
//
//            double baseValue = currentJump->getBaseValue();
//            this->SPbaseValueLabels[1]->setText(QString::number(baseValue, 'f', 2));
//            this->SPTotalLabels[1]->setText(QString::number(baseValue, 'f', 2));
//            updateTotals();
//        }
//    });

//    QObject::connect(this->combojump1, &QComboBox::currentIndexChanged, this, [this](){
//        int index = combojump1->currentIndex()-1;
//        if(index > 0) {
//            Jumps *currentJump = this->_service.getJumps()[index];
//
//            double baseValue = 0;
//
//            if (combojump2->currentIndex() != 0) {
//                baseValue += this->_service.getJumps()[combojump2->currentIndex() - 1]->getBaseValue();
//            }
//
//            baseValue += currentJump->getBaseValue();
//            this->SPbaseValueLabels[2]->setText(QString::number(baseValue, 'f', 2));
//            this->SPTotalLabels[2]->setText(QString::number(baseValue, 'f', 2));
//            updateTotals();
//        }
//    });
//
//    QObject::connect(this->combojump2, &QComboBox::currentIndexChanged, this, [this](){
//        int index = combojump2->currentIndex()-1;
//        if(index > 0) {
//            Jumps *currentJump = this->_service.getJumps()[index];
//
//            double baseValue = 0;
//
//            if (combojump1->currentIndex() != 0) {
//                baseValue += this->_service.getJumps()[combojump1->currentIndex() - 1]->getBaseValue();
//            }
//
//            baseValue += currentJump->getBaseValue();
//            this->SPbaseValueLabels[2]->setText(QString::number(baseValue, 'f', 2));
//            this->SPTotalLabels[2]->setText(QString::number(baseValue, 'f', 2));
//            updateTotals();
//        }
//    });

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
    connectSpins();
    connectJumps();

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

    for(int i=0;i<5;i++){
        pcs += (this->SPpcs[i]->value() * 0.8);
    }

    this->SPPCSLabel->setText(QString::number(pcs, 'f', 2));
    updateTotals();

}
// QComboBox* je1, *je2, *je3, *je4;
//    QComboBox* ju1, *ju2, *ju3, *ju4;
//    QComboBox* jlvl1, *jlvl2, *jlvl3, *jlvl4;
void LadiesSPWindow::addJumps() {

    std::vector<Jumps*> jumps = this->_service.getJumps();

    jump1->addItem("");
    jump2->addItem("");
    combojump1->addItem("");
    combojump2->addItem("");

    jump1->addItem("Lutz");
    jump1->addItem("Flip");
    jump1->addItem("Toeloop");
    jump1->addItem("Salchow");
    jump1->addItem("Loop");
    jump1->addItem("Axel");

    jump2->addItem("Lutz");
    jump2->addItem("Flip");
    jump2->addItem("Toeloop");
    jump2->addItem("Salchow");
    jump2->addItem("Loop");
    jump2->addItem("Axel");

    combojump1->addItem("Lutz");
    combojump1->addItem("Flip");
    combojump1->addItem("Toeloop");
    combojump1->addItem("Salchow");
    combojump1->addItem("Loop");
    combojump1->addItem("Axel");

    combojump2->addItem("Lutz");
    combojump2->addItem("Flip");
    combojump2->addItem("Toeloop");
    combojump2->addItem("Salchow");
    combojump2->addItem("Loop");
    combojump2->addItem("Axel");

    jlvl1->addItem("");
    jlvl1->addItem("1");
    jlvl1->addItem("2");
    jlvl1->addItem("3");
    jlvl1->addItem("4");

    jlvl2->addItem("");
    jlvl2->addItem("1");
    jlvl2->addItem("2");
    jlvl2->addItem("3");
    jlvl2->addItem("4");

    jlvl3->addItem("");
    jlvl3->addItem("1");
    jlvl3->addItem("2");
    jlvl3->addItem("3");
    jlvl3->addItem("4");

    jlvl4->addItem("");
    jlvl4->addItem("1");
    jlvl4->addItem("2");
    jlvl4->addItem("3");
    jlvl4->addItem("4");

    ju1->addItem("");
    ju1->addItem("<");
    ju2->addItem("");
    ju2->addItem("<");
    ju3->addItem("");
    ju4->addItem("");
    ju3->addItem("<");
    ju4->addItem("<");

    je1->addItem("");
    je2->addItem("");
    je3->addItem("");
    je4->addItem("");
    je1->addItem("e");
    je2->addItem("e");
    je3->addItem("e");
    je4->addItem("e");

  //  for(auto* j: jumps){
//        jump1->addItem(QString::fromStdString(j->toString()));
//        jump2->addItem(QString::fromStdString(j->toString()));
//        combojump1->addItem(QString::fromStdString(j->toString()));
//        combojump2->addItem(QString::fromStdString(j->toString()));
   // }



}


void LadiesSPWindow::addStsq() {

    std::vector<StepSequence*> stsqs = this->_service.getStsq();

    stsq->addItem("");

    for(auto* s: stsqs)
        stsq->addItem(QString::fromStdString(s->toString()));

}

void LadiesSPWindow::addSpins() {

    spin1->addItem("");
    spin1->addItem("USp");
    spin1->addItem("LSp");
    spin1->addItem("CSp");
    spin1->addItem("SSp");
    spin1->addItem("CoSp");
    fs1->addItem("");
    fs1->addItem("F");
    cs1->addItem("");
    cs1->addItem("C");
    lvls1->addItem("");
    lvls1->addItem("B");
    lvls1->addItem("1");
    lvls1->addItem("2");
    lvls1->addItem("3");
    lvls1->addItem("4");


    spin2->addItem("");
    spin2->addItem("USp");
    spin2->addItem("LSp");
    spin2->addItem("CSp");
    spin2->addItem("SSp");
    spin2->addItem("CoSp");
    fs2->addItem("");
    fs2->addItem("F");
    cs2->addItem("");
    cs2->addItem("C");
    lvls2->addItem("");
    lvls2->addItem("B");
    lvls2->addItem("1");
    lvls2->addItem("2");
    lvls2->addItem("3");
    lvls2->addItem("4");


    spin3->addItem("");
    spin3->addItem("USp");
    spin3->addItem("LSp");
    spin3->addItem("CSp");
    spin3->addItem("SSp");
    spin3->addItem("CoSp");
    fs3->addItem("");
    fs3->addItem("F");

    cs3->addItem("");
    cs3->addItem("C");
    lvls3->addItem("");
    lvls3->addItem("B");
    lvls3->addItem("1");
    lvls3->addItem("2");
    lvls3->addItem("3");
    lvls3->addItem("4");
}

void LadiesSPWindow::connectJumps() {
    QObject::connect(this->jump1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump1);
    QObject::connect(this->jlvl1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump1);
    QObject::connect(this->ju1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump1);
    QObject::connect(this->je1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump1);

    QObject::connect(this->jump2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump2);
    QObject::connect(this->jlvl2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump2);
    QObject::connect(this->ju2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump2);
    QObject::connect(this->je2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectJump2);

    QObject::connect(this->combojump1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump1);
    QObject::connect(this->jlvl3, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump1);
    QObject::connect(this->ju3, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump1);
    QObject::connect(this->je3, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump1);

    QObject::connect(this->combojump2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump2);
    QObject::connect(this->jlvl4, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump2);
    QObject::connect(this->ju4, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump2);
    QObject::connect(this->je4, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectComboJump2);
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

void LadiesSPWindow::connectSpins() {
    QObject::connect(this->spin1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin1);
    QObject::connect(this->fs1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin1);
    QObject::connect(this->cs1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin1);
    QObject::connect(this->lvls1, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin1);

    QObject::connect(this->spin2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin2);
    QObject::connect(this->fs2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin2);
    QObject::connect(this->cs2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin2);
    QObject::connect(this->lvls2, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin2);

    QObject::connect(this->spin3, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin3);
    QObject::connect(this->fs3, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin3);
    QObject::connect(this->cs3, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin3);
    QObject::connect(this->lvls3, &QComboBox::currentIndexChanged, this, &LadiesSPWindow::connectSpin3);
}


void LadiesSPWindow::connectSpin1() {
    if(spin1->currentIndex() && lvls1->currentIndex()){

        bool fly;
        bool change;
        if(this->fs1->currentIndex()){
            fly = true;
        }
        else
            fly = false;

        if(this->cs1->currentIndex())
            change = true;
        else
            change = false;

        auto name = this->spin1->currentText().toStdString();
        auto lvl = this->lvls1->currentText().toInt();

        Spins* spin = this->_service.getSpin(fly, change, name, lvl);
        std::cout<<spin->toString()<<" "<<spin->getBaseValue()<<"\n";
        this->SPbaseValueLabels[3]->setText(QString::number(spin->getBaseValue(), 'f', 2));
    }

}



void LadiesSPWindow::updateTotals() {
    connectTotalTES();
    connectTotalBV();

    double TES = this->SPTESLabel->text().toDouble();
    double PCS = this->SPPCSLabel->text().toDouble();
    std::cout<<PCS<<std::endl;
    double total = TES + PCS;

    this->SPTotalLabel->setText(QString::number(total, 'f', 2));
}

void LadiesSPWindow::connectSpin2() {
    std::cout<<spin2->currentIndex()<<" "<<lvls2->currentIndex();
    if(spin2->currentIndex() && lvls2->currentIndex()){

        bool fly;
        bool change;
        if(this->fs2->currentIndex()){
            fly = true;
        }
        else
            fly = false;

        if(this->cs2->currentIndex())
            change = true;
        else
            change = false;

        auto name = this->spin2->currentText().toStdString();
        auto lvl = this->lvls2->currentText().toInt();

        Spins* spin = this->_service.getSpin(fly, change, name, lvl);
        std::cout<<spin->toString()<<" "<<spin->getBaseValue()<<"\n";
        this->SPbaseValueLabels[4]->setText(QString::number(spin->getBaseValue(), 'f', 2));
    }

}


void LadiesSPWindow::connectSpin3() {
    if(spin3->currentIndex() && lvls3->currentIndex()){

        bool fly;
        bool change;
        if(this->fs3->currentIndex()){
            fly = true;
        }
        else
            fly = false;

        if(this->cs3->currentIndex())
            change = true;
        else
            change = false;

        auto name = this->spin3->currentText().toStdString();
        auto lvl = this->lvls3->currentText().toInt();

        Spins* spin = this->_service.getSpin(fly, change, name, lvl);
        std::cout<<spin->toString()<<" "<<spin->getBaseValue()<<"\n";
        this->SPbaseValueLabels[5]->setText(QString::number(spin->getBaseValue(), 'f', 2));
    }

}

void LadiesSPWindow::connectJump1() {

    if(jump1->currentIndex() && jlvl1->currentIndex()){
        bool ur, edge;

        if(this->ju1->currentIndex())
            ur = true;
        else
            ur = false;

        if(this->je1->currentIndex())
            edge = true;
        else
            edge = false;

        auto name = this->jump1->currentText().toStdString();
        auto lvl = this->jlvl1->currentText().toInt();


        try {
            Jumps *jump = this->_service.getJump(ur, edge, lvl, name);
            std::cout<<"my jump is: "<<jump->toString()<<" "<< jump->getBaseValue()<<std::endl;
            double baseValue = jump->getBaseValue();
            this->SPbaseValueLabels[0]->setText(QString::number(baseValue, 'f', 2));
            this->SPTotalLabels[0]->setText(QString::number(baseValue, 'f', 2));
            updateTotals();

        }
        catch (const ElementException &ve) {
            QMessageBox msg;
            msg.setText(QString::fromStdString(ve.get_message()));
            msg.exec();
            this->je1->setCurrentIndex(0);
        }
        //todo: catch this somewhere else

    }
}

void LadiesSPWindow::connectJump2() {

    if(jump2->currentIndex() && jlvl2->currentIndex()){
        bool ur, edge;

        if(this->ju2->currentIndex())
            ur = true;
        else
            ur = false;

        if(this->je2->currentIndex())
            edge = true;
        else
            edge = false;

        auto name = this->jump2->currentText().toStdString();
        auto lvl = this->jlvl2->currentText().toInt();

        std::cout<<name<<" "<<lvl<<" "<<edge<<" "<<ur<<std::endl;


        try {
            Jumps *jump = this->_service.getJump(ur, edge, lvl, name);
            std::cout<<"my jump is: "<<jump->toString()<<" "<< jump->getBaseValue()<<std::endl;
            double baseValue = jump->getBaseValue();
            this->SPbaseValueLabels[1]->setText(QString::number(baseValue, 'f', 2));
            this->SPTotalLabels[1]->setText(QString::number(baseValue, 'f', 2));
            updateTotals();

        }
        catch (const ElementException &ve) {
            QMessageBox msg;
            msg.setText(QString::fromStdString(ve.get_message()));
            msg.exec();
        }
        //todo: catch this somewhere else

    }
}



void LadiesSPWindow::clearScore() {

    this->deductionBox->setValue(0);
    this->jump1->setCurrentIndex(0);
    this->jump2->setCurrentIndex(0);
    this->combojump2->setCurrentIndex(0);
    this->combojump1->setCurrentIndex(0);
    this->stsq->setCurrentIndex(0);
    this->spin1->setCurrentIndex(0);
    this->spin2->setCurrentIndex(0);
    this->spin3->setCurrentIndex(0);
    this->fs1->setCurrentIndex(0);
    this->fs2->setCurrentIndex(0);
    this->fs3->setCurrentIndex(0);
    this->cs1->setCurrentIndex(0);
    this->cs2->setCurrentIndex(0);
    this->cs3->setCurrentIndex(0);
    this->lvls1->setCurrentIndex(0);
    this->lvls2->setCurrentIndex(0);
    this->lvls3->setCurrentIndex(0);

    this->je1->setCurrentIndex(0);
    this->je2->setCurrentIndex(0);
    this->je3->setCurrentIndex(0);
    this->je4->setCurrentIndex(0);

    this->ju1->setCurrentIndex(0);
    this->ju2->setCurrentIndex(0);
    this->ju3->setCurrentIndex(0);
    this->ju4->setCurrentIndex(0);

    this->jlvl1->setCurrentIndex(0);
    this->jlvl2->setCurrentIndex(0);
    this->jlvl3->setCurrentIndex(0);
    this->jlvl4->setCurrentIndex(0);

    for(int i=0;i<7;i++){
        this->SPbaseValueLabels[i]->clear();
        this->SPTotalLabels[i]->clear();
        this->SPGOEMarkLabels[i]->clear();
        this->SPgoes[i]->setValue(0);
    }

    this->j1->setCheckState(static_cast<Qt::CheckState>(false));
    this->j2->setCheckState(static_cast<Qt::CheckState>(false));
    this->cj->setCheckState(static_cast<Qt::CheckState>(false));

    for(int i=0;i<5;i++)
        this->SPpcs[i]->setValue(8.5);

    this->SPTotalLabel->clear();
}

void LadiesSPWindow::connectComboJump1() {
    if(combojump1->currentIndex() && jlvl3->currentIndex()){
        bool ur, edge;

        if(this->ju3->currentIndex())
            ur = true;
        else
            ur = false;

        if(this->je3->currentIndex())
            edge = true;
        else
            edge = false;

        auto name = this->combojump1->currentText().toStdString();
        auto lvl = this->jlvl3->currentText().toInt();

        //std::cout<<name<<" "<<lvl<<" "<<edge<<" "<<ur<<std::endl;


        try {
            Jumps *jump = this->_service.getJump(ur, edge, lvl, name);
            //std::cout<<"my jump is: "<<jump->toString()<<" "<< jump->getBaseValue()<<std::endl;
            double baseValue = 0;

            if (combojump2->currentIndex() != 0 && jlvl4->currentIndex()) {
                bool u, e;
                int l;
                l = jlvl4->currentText().toInt();

                if(ju4->currentIndex())
                    u = true;
                else
                    u = false;

                if(je4->currentIndex())
                    e = true;
                else
                    e = false;

                auto * j =  this->_service.getJump(u,e,l,combojump2->currentText().toStdString());
                baseValue += j->getBaseValue();
            }

            baseValue += jump->getBaseValue();
            this->SPbaseValueLabels[2]->setText(QString::number(baseValue, 'f', 2));
            this->SPTotalLabels[2]->setText(QString::number(baseValue, 'f', 2));
            updateTotals();

        }
        catch (const ElementException &ve) {
            QMessageBox msg;
            msg.setText(QString::fromStdString(ve.get_message()));
            msg.exec();
            this->je3->setCurrentIndex(0);
        }
        //todo: catch this somewhere else

    }
}


void LadiesSPWindow::connectComboJump2() {
    if(combojump2->currentIndex() && jlvl4->currentIndex()){
        bool ur, edge;

        if(this->ju4->currentIndex())
            ur = true;
        else
            ur = false;

        if(this->je4->currentIndex())
            edge = true;
        else
            edge = false;

        auto name = this->combojump2->currentText().toStdString();
        auto lvl = this->jlvl4->currentText().toInt();

        std::cout<<name<<" "<<lvl<<" "<<edge<<" "<<ur<<std::endl;


        try {
            Jumps *jump = this->_service.getJump(ur, edge, lvl, name);
            std::cout<<"my jump is: "<<jump->toString()<<" "<< jump->getBaseValue()<<std::endl;
            double baseValue = 0;
            if (combojump1->currentIndex() != 0 && jlvl3->currentIndex()) {
                bool u, e;
                int l;

                std::cout<<"combo jump 1 level index: "<<jlvl3->currentIndex()<<" "<<jlvl3->currentText().toInt()<<std::endl;
                l = this->jlvl3->currentText().toInt();

                if(ju3->currentIndex())
                    u = true;
                else
                    u = false;

                if(je3->currentIndex())
                    e = true;
                else
                    e = false;

                std::cout<<combojump1->currentText().toStdString()<<" "<<l<<" "<<e<<" "<<u<<std::endl;
                auto* j = this->_service.getJump(u,e,l,combojump1->currentText().toStdString());
                baseValue += j->getBaseValue();
                std::cout<<"Combo jump1 is: "<<j->toString()<<std::endl;
            }

            baseValue += jump->getBaseValue();

            this->SPbaseValueLabels[2]->setText(QString::number(baseValue, 'f', 2));
            this->SPTotalLabels[2]->setText(QString::number(baseValue, 'f', 2));
            updateTotals();

        }
        catch (const ElementException &ve) {
            QMessageBox msg;
            msg.setText(QString::fromStdString(ve.get_message()));
            msg.exec();
            this->je4->setCurrentIndex(0);
        }
        //todo: catch this somewhere else

    }
}



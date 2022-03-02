//
// Created by amina on 8/2/2021.
//

#ifndef FS_PROGRAM_SCORE_CALCULATOR_LADIESSPWINDOW_H
#define FS_PROGRAM_SCORE_CALCULATOR_LADIESSPWINDOW_H


#include <QWidget>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <Service/ScoreService.h>

class LadiesSPWindow : public QWidget {
    Q_OBJECT

private:
    std::string skaterName;

    QSpinBox* deductionBox;
    QVBoxLayout* SPMenu;

    QLineEdit* nameEdit;
    //QVector<QComboBox *> SPelements;
    QComboBox* jump1, *jump2, *combojump1, *combojump2;
    QCheckBox* j1, *j2, *cj;
    QComboBox* fs1, *fs2, *fs3;
    QComboBox* cs1, *cs2, *cs3;
    QComboBox* lvls1, *lvls2, *lvls3;
    QComboBox* spin1, *spin2, *spin3;
    QComboBox* stsq;
    QVector<QSpinBox* > SPgoes;
    QVector<QLabel*> SPbaseValueLabels;
    QVector<QLabel*> SPGOEMarkLabels;
    QVector<QLabel*> SPGOETotalLabels;
    QVector<QLabel*> SPTotalLabels;
    QVector<QDoubleSpinBox*> SPpcs;
    QLabel* SPTotalLabel;
    QLabel* SPBVLabel;
    QLabel* SPTESLabel;
    QLabel* SPPCSLabel;
    QPushButton* SPComputeScore;
    QPushButton* SPClearScore;

    int SPPCSbullets[5];
    ScoreService& _service;

public:
    LadiesSPWindow(std::string name, ScoreService& s);
    ~LadiesSPWindow();

    void initGUI();

    void connect();
    void connectPCS();
    void connectGOE();
    void connectTotalBV();
    void connectTotalTES();
    void connectSpins();

    void connectSpin1();
    void connectSpin2();
    void connectSpin3();

    void updateTotals();

    void computePCS();
    void addJumps();
    void addStsq();
    void addSpins();

    void clearScore();

};


#endif //FS_PROGRAM_SCORE_CALCULATOR_LADIESSPWINDOW_H

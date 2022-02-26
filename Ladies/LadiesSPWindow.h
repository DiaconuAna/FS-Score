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

class LadiesSPWindow : public QWidget {
    Q_OBJECT

private:
    std::string skaterName;

    QSpinBox* deductionBox;
    QVBoxLayout* SPMenu;

    QLineEdit* nameEdit;
    QVector<QComboBox *> SPelements;
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

public:
    LadiesSPWindow(std::string name);
    ~LadiesSPWindow();

    void initGUI();

    void connect();
    void connectPCS();

    void computePCS();


};


#endif //FS_PROGRAM_SCORE_CALCULATOR_LADIESSPWINDOW_H

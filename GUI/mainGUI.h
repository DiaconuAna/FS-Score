//
// Created by amina on 8/2/2021.
//


#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QSortFilterProxyModel>
#include <QSpinBox>
#include <QSlider>
#include <QListWidget>
#include <Service/ScoreService.h>
#include "Ladies/LadiesFSWindow.h"

class mainGUI : public QWidget {
    private:

    QPushButton* LadiesButton;
    QPushButton* MenButton;
    QPushButton* PairsButton;
    QPushButton* IceDanceButton;
    QPushButton* JuniorLadiesButton;
    QPushButton* JuniorMenButton;
    QPushButton* JuniorIceDanceButton;
    QPushButton* JuniorPairsButton;


    LadiesFSWindow* ladiesWindow;


    ScoreService& _service;

    public:

    //mainGUI();
    mainGUI(ScoreService& s);
    ~mainGUI();

    void initGUI();
    void connectGUI();

    void openLadiesWindow();

};


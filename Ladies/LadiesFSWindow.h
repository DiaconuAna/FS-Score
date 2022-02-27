//
// Created by amina on 8/2/2021.
//

#include <qwidget.h>
#include <qabstractspinbox.h>
#include <QLineEdit>
#include <qlistwidget.h>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <Service/ScoreService.h>
#include "LadiesSPWindow.h"

class LadiesFSWindow : public QWidget {

    Q_OBJECT

private:

    QVBoxLayout* mainMenu;
    QPushButton* ladiesShort;
    QPushButton* ladiesLong;

    QLineEdit* nameEdit;

    LadiesSPWindow* SPWindow;
    ScoreService& _service;


public:
    LadiesFSWindow(ScoreService& s);
    ~LadiesFSWindow() override;

    void initGUI();
    void connect();


    void openSP();
    void openFP();


    void computeSPPCS();

    void connectSPPCS();
    void connectSPGOE();

    void aux();


};



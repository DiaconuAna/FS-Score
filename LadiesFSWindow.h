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

class LadiesFSWindow : public QWidget {

    Q_OBJECT

private:

    QVBoxLayout* mainMenu;
    QPushButton* ladiesShort;
    QPushButton* ladiesLong;

    QLineEdit* nameEdit;

    QVBoxLayout* SPMenu;
    QVBoxLayout* FPMenu;

    QWidget* SPW;
    QWidget* FPW;

    QSpinBox* deductionBox;

    QVector<QLabel*> SPbaseValueLabels;
    QVector<QLabel*> SPGOEMarkLabels;
    QVector<QLabel*> SPGOETotalLabels;
    QVector<QLabel*> SPTotalLabels;


    //QComboBox* SP1, *SP2, *SP3, *SP4, *SP5, *SP6, *SP7;


public:
    LadiesFSWindow();
    ~LadiesFSWindow();

    void initGUI();
    void connect();

    void SPWidget();
    void FSWidget();

    void clearLayout();

};



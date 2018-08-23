/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *TimeLable_2;
    QLabel *TimeLable;
    QSplitter *splitter;
    QPushButton *AddNewSensor;
    QPushButton *AnalysisCompare;
    QPushButton *OutputCSV;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1071, 753);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(550, 20, 511, 501));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 511, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TimeLable_2 = new QLabel(centralWidget);
        TimeLable_2->setObjectName(QStringLiteral("TimeLable_2"));
        TimeLable_2->setGeometry(QRect(30, 630, 509, 21));
        TimeLable = new QLabel(centralWidget);
        TimeLable->setObjectName(QStringLiteral("TimeLable"));
        TimeLable->setGeometry(QRect(30, 660, 509, 31));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(550, 530, 511, 61));
        splitter->setOrientation(Qt::Horizontal);
        AddNewSensor = new QPushButton(splitter);
        AddNewSensor->setObjectName(QStringLiteral("AddNewSensor"));
        splitter->addWidget(AddNewSensor);
        AnalysisCompare = new QPushButton(splitter);
        AnalysisCompare->setObjectName(QStringLiteral("AnalysisCompare"));
        splitter->addWidget(AnalysisCompare);
        OutputCSV = new QPushButton(splitter);
        OutputCSV->setObjectName(QStringLiteral("OutputCSV"));
        splitter->addWidget(OutputCSV);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1071, 24));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        TimeLable_2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        TimeLable->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        AddNewSensor->setText(QApplication::translate("MainWindow", "\346\226\260\345\242\236\346\204\237\346\207\211\345\231\250", nullptr));
        AnalysisCompare->setText(QApplication::translate("MainWindow", "\350\203\275\350\200\227\345\210\206\346\236\220\346\257\224\350\274\203", nullptr));
        OutputCSV->setText(QApplication::translate("MainWindow", "\345\214\257\345\207\272\350\241\250\345\226\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'qtdiskinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDISKINFO_H
#define UI_QTDISKINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDiskInfo
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *te_Log;
    QPushButton *pb_Get;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtDiskInfo)
    {
        if (QtDiskInfo->objectName().isEmpty())
            QtDiskInfo->setObjectName(QStringLiteral("QtDiskInfo"));
        QtDiskInfo->resize(400, 300);
        centralWidget = new QWidget(QtDiskInfo);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 54, 12));
        te_Log = new QTextEdit(centralWidget);
        te_Log->setObjectName(QStringLiteral("te_Log"));
        te_Log->setGeometry(QRect(40, 30, 331, 171));
        pb_Get = new QPushButton(centralWidget);
        pb_Get->setObjectName(QStringLiteral("pb_Get"));
        pb_Get->setGeometry(QRect(140, 210, 111, 41));
        QtDiskInfo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtDiskInfo);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        QtDiskInfo->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtDiskInfo);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtDiskInfo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtDiskInfo);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtDiskInfo->setStatusBar(statusBar);

        retranslateUi(QtDiskInfo);

        QMetaObject::connectSlotsByName(QtDiskInfo);
    } // setupUi

    void retranslateUi(QMainWindow *QtDiskInfo)
    {
        QtDiskInfo->setWindowTitle(QApplication::translate("QtDiskInfo", "QtDiskInfo", Q_NULLPTR));
        label->setText(QApplication::translate("QtDiskInfo", "Disk Info", Q_NULLPTR));
        pb_Get->setText(QApplication::translate("QtDiskInfo", "Get Disk Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtDiskInfo: public Ui_QtDiskInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDISKINFO_H

/********************************************************************************
** Form generated from reading ui file 'cadi.ui'
**
** Created: Sat Apr 3 08:56:45 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CADI_H
#define UI_CADI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cadi
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QWidget *generalTab;
    QGridLayout *gridLayout;
    QLabel *distroNameLabel;
    QLabel *kernelLabel;
    QLabel *DELabel;
    QToolButton *updateButton;
    QToolButton *distroLogoButton;
    QWidget *softwareTab;
    QWidget *hardwareTab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cadi)
    {
        if (Cadi->objectName().isEmpty())
            Cadi->setObjectName(QString::fromUtf8("Cadi"));
        Cadi->resize(600, 400);
        centralWidget = new QWidget(Cadi);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(0);
        mainLayout->setMargin(0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setDocumentMode(false);
        generalTab = new QWidget();
        generalTab->setObjectName(QString::fromUtf8("generalTab"));
        generalTab->setMaximumSize(QSize(600, 400));
        gridLayout = new QGridLayout(generalTab);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        distroNameLabel = new QLabel(generalTab);
        distroNameLabel->setObjectName(QString::fromUtf8("distroNameLabel"));
        distroNameLabel->setWordWrap(true);

        gridLayout->addWidget(distroNameLabel, 0, 1, 1, 1);

        kernelLabel = new QLabel(generalTab);
        kernelLabel->setObjectName(QString::fromUtf8("kernelLabel"));
        kernelLabel->setWordWrap(true);

        gridLayout->addWidget(kernelLabel, 1, 1, 1, 1);

        DELabel = new QLabel(generalTab);
        DELabel->setObjectName(QString::fromUtf8("DELabel"));
        DELabel->setWordWrap(true);

        gridLayout->addWidget(DELabel, 2, 1, 1, 1);

        updateButton = new QToolButton(generalTab);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(updateButton->sizePolicy().hasHeightForWidth());
        updateButton->setSizePolicy(sizePolicy);
        updateButton->setIconSize(QSize(48, 48));

        gridLayout->addWidget(updateButton, 2, 0, 1, 1);

        distroLogoButton = new QToolButton(generalTab);
        distroLogoButton->setObjectName(QString::fromUtf8("distroLogoButton"));
        sizePolicy.setHeightForWidth(distroLogoButton->sizePolicy().hasHeightForWidth());
        distroLogoButton->setSizePolicy(sizePolicy);
        distroLogoButton->setIconSize(QSize(128, 128));
        distroLogoButton->setCheckable(false);
        distroLogoButton->setAutoRaise(true);

        gridLayout->addWidget(distroLogoButton, 0, 0, 1, 1);

        tabWidget->addTab(generalTab, QString());
        softwareTab = new QWidget();
        softwareTab->setObjectName(QString::fromUtf8("softwareTab"));
        tabWidget->addTab(softwareTab, QString());
        hardwareTab = new QWidget();
        hardwareTab->setObjectName(QString::fromUtf8("hardwareTab"));
        tabWidget->addTab(hardwareTab, QString());

        mainLayout->addWidget(tabWidget);

        Cadi->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Cadi);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        Cadi->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Cadi);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Cadi->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Cadi);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Cadi->setStatusBar(statusBar);

        retranslateUi(Cadi);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Cadi);
    } // setupUi

    void retranslateUi(QMainWindow *Cadi)
    {
        Cadi->setWindowTitle(QApplication::translate("Cadi", "Cadi", 0, QApplication::UnicodeUTF8));
        distroNameLabel->setText(QApplication::translate("Cadi", "DistroName", 0, QApplication::UnicodeUTF8));
        kernelLabel->setText(QApplication::translate("Cadi", "Kernel", 0, QApplication::UnicodeUTF8));
        DELabel->setText(QApplication::translate("Cadi", "DE", 0, QApplication::UnicodeUTF8));
        updateButton->setText(QApplication::translate("Cadi", "Update", 0, QApplication::UnicodeUTF8));
        distroLogoButton->setText(QApplication::translate("Cadi", "DistroLogo", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(generalTab), QApplication::translate("Cadi", "General", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(softwareTab), QApplication::translate("Cadi", "Software", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(hardwareTab), QApplication::translate("Cadi", "Hardware", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Cadi);
    } // retranslateUi

};

namespace Ui {
    class Cadi: public Ui_Cadi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADI_H

/********************************************************************************
** Form generated from reading UI file 'EDFDEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDFDEDITOR_H
#define UI_EDFDEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ADrawWidget.h"
#include "AWorkspaceWidget.h"

QT_BEGIN_NAMESPACE

class Ui_EDFDEditor
{
public:
    QAction *actionAbout;
    QAction *ASave;
    QAction *ASaveAs;
    QAction *ALoad;
    QAction *AExit;
    QAction *ANewFile;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    AWorkspaceWidget *gvDocument;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    ADrawWidget *listWidget;

    void setupUi(QMainWindow *EDFDEditor)
    {
        if (EDFDEditor->objectName().isEmpty())
            EDFDEditor->setObjectName(QString::fromUtf8("EDFDEditor"));
        EDFDEditor->resize(1052, 929);
        actionAbout = new QAction(EDFDEditor);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        ASave = new QAction(EDFDEditor);
        ASave->setObjectName(QString::fromUtf8("ASave"));
        ASaveAs = new QAction(EDFDEditor);
        ASaveAs->setObjectName(QString::fromUtf8("ASaveAs"));
        ALoad = new QAction(EDFDEditor);
        ALoad->setObjectName(QString::fromUtf8("ALoad"));
        AExit = new QAction(EDFDEditor);
        AExit->setObjectName(QString::fromUtf8("AExit"));
        ANewFile = new QAction(EDFDEditor);
        ANewFile->setObjectName(QString::fromUtf8("ANewFile"));
        centralWidget = new QWidget(EDFDEditor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gvDocument = new AWorkspaceWidget(centralWidget);
        gvDocument->setObjectName(QString::fromUtf8("gvDocument"));

        horizontalLayout->addWidget(gvDocument);

        EDFDEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EDFDEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1052, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        EDFDEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EDFDEditor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EDFDEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EDFDEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EDFDEditor->setStatusBar(statusBar);
        dockWidget = new QDockWidget(EDFDEditor);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new ADrawWidget(dockWidgetContents);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        dockWidget->setWidget(dockWidgetContents);
        EDFDEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(ANewFile);
        menuFile->addAction(ASave);
        menuFile->addAction(ASaveAs);
        menuFile->addAction(ALoad);
        menuFile->addSeparator();
        menuFile->addAction(AExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(EDFDEditor);

        QMetaObject::connectSlotsByName(EDFDEditor);
    } // setupUi

    void retranslateUi(QMainWindow *EDFDEditor)
    {
        EDFDEditor->setWindowTitle(QApplication::translate("EDFDEditor", "EDFDEditor", nullptr));
        actionAbout->setText(QApplication::translate("EDFDEditor", "About", nullptr));
        ASave->setText(QApplication::translate("EDFDEditor", "Save()", nullptr));
        ASaveAs->setText(QApplication::translate("EDFDEditor", "SaveAs()", nullptr));
        ALoad->setText(QApplication::translate("EDFDEditor", "Load()", nullptr));
        AExit->setText(QApplication::translate("EDFDEditor", "Exit", nullptr));
        ANewFile->setText(QApplication::translate("EDFDEditor", "New File", nullptr));
        menuFile->setTitle(QApplication::translate("EDFDEditor", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("EDFDEditor", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EDFDEditor: public Ui_EDFDEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDFDEDITOR_H

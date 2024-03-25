/********************************************************************************
** Form generated from reading UI file 'ATEnvironment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATENVIRONMENT_H
#define UI_ATENVIRONMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AProjectExplorer.h"

QT_BEGIN_NAMESPACE

class Ui_ATEnvironmentClass
{
public:
    QAction *actionNewProject;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionSave_Project;
    QAction *actionNewFile;
    QAction *actionPlugins;
    QAction *actionSaveFile;
    QAction *actionSaveAsFile;
    QAction *actionSave_all;
    QAction *actionOpenProject;
    QAction *actionOpenFile;
    QAction *actionBuildProject;
    QAction *actionBuildCleanProject;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuOpen;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuTools;
    QMenu *menuBuild;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dwProjectExplorer;
    AProjectExplorer *wdgProjectExplorer;
    QVBoxLayout *verticalLayout;
    QDockWidget *dockPlanner;
    QWidget *dockWidgetContents_2;

    void setupUi(QMainWindow *ATEnvironmentClass)
    {
        if (ATEnvironmentClass->objectName().isEmpty())
            ATEnvironmentClass->setObjectName(QString::fromUtf8("ATEnvironmentClass"));
        ATEnvironmentClass->resize(997, 717);
        actionNewProject = new QAction(ATEnvironmentClass);
        actionNewProject->setObjectName(QString::fromUtf8("actionNewProject"));
        actionExit = new QAction(ATEnvironmentClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(ATEnvironmentClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSave_Project = new QAction(ATEnvironmentClass);
        actionSave_Project->setObjectName(QString::fromUtf8("actionSave_Project"));
        actionNewFile = new QAction(ATEnvironmentClass);
        actionNewFile->setObjectName(QString::fromUtf8("actionNewFile"));
        actionPlugins = new QAction(ATEnvironmentClass);
        actionPlugins->setObjectName(QString::fromUtf8("actionPlugins"));
        actionSaveFile = new QAction(ATEnvironmentClass);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        actionSaveFile->setEnabled(false);
        actionSaveAsFile = new QAction(ATEnvironmentClass);
        actionSaveAsFile->setObjectName(QString::fromUtf8("actionSaveAsFile"));
        actionSaveAsFile->setEnabled(false);
        actionSave_all = new QAction(ATEnvironmentClass);
        actionSave_all->setObjectName(QString::fromUtf8("actionSave_all"));
        actionOpenProject = new QAction(ATEnvironmentClass);
        actionOpenProject->setObjectName(QString::fromUtf8("actionOpenProject"));
        actionOpenFile = new QAction(ATEnvironmentClass);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionBuildProject = new QAction(ATEnvironmentClass);
        actionBuildProject->setObjectName(QString::fromUtf8("actionBuildProject"));
        actionBuildCleanProject = new QAction(ATEnvironmentClass);
        actionBuildCleanProject->setObjectName(QString::fromUtf8("actionBuildCleanProject"));
        centralWidget = new QWidget(ATEnvironmentClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);

        horizontalLayout->addWidget(mdiArea);

        ATEnvironmentClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ATEnvironmentClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 997, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuBuild = new QMenu(menuBar);
        menuBuild->setObjectName(QString::fromUtf8("menuBuild"));
        ATEnvironmentClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ATEnvironmentClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ATEnvironmentClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ATEnvironmentClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ATEnvironmentClass->setStatusBar(statusBar);
        dwProjectExplorer = new QDockWidget(ATEnvironmentClass);
        dwProjectExplorer->setObjectName(QString::fromUtf8("dwProjectExplorer"));
        dwProjectExplorer->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        wdgProjectExplorer = new AProjectExplorer();
        wdgProjectExplorer->setObjectName(QString::fromUtf8("wdgProjectExplorer"));
        verticalLayout = new QVBoxLayout(wdgProjectExplorer);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dwProjectExplorer->setWidget(wdgProjectExplorer);
        ATEnvironmentClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dwProjectExplorer);
        dockPlanner = new QDockWidget(ATEnvironmentClass);
        dockPlanner->setObjectName(QString::fromUtf8("dockPlanner"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        dockPlanner->setWidget(dockWidgetContents_2);
        ATEnvironmentClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockPlanner);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuBuild->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(actionSave_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionSaveFile);
        menuFile->addAction(actionSaveAsFile);
        menuFile->addAction(actionSave_all);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuNew->addAction(actionNewProject);
        menuNew->addAction(actionNewFile);
        menuOpen->addAction(actionOpenProject);
        menuOpen->addAction(actionOpenFile);
        menuHelp->addAction(actionAbout);
        menuTools->addAction(actionPlugins);
        menuBuild->addAction(actionBuildProject);
        menuBuild->addAction(actionBuildCleanProject);

        retranslateUi(ATEnvironmentClass);

        QMetaObject::connectSlotsByName(ATEnvironmentClass);
    } // setupUi

    void retranslateUi(QMainWindow *ATEnvironmentClass)
    {
        ATEnvironmentClass->setWindowTitle(QApplication::translate("ATEnvironmentClass", "ATEnvironment", nullptr));
        actionNewProject->setText(QApplication::translate("ATEnvironmentClass", "Project...", nullptr));
        actionExit->setText(QApplication::translate("ATEnvironmentClass", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("ATEnvironmentClass", "Alt+F4", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("ATEnvironmentClass", "About", nullptr));
        actionSave_Project->setText(QApplication::translate("ATEnvironmentClass", "Save Project", nullptr));
        actionNewFile->setText(QApplication::translate("ATEnvironmentClass", "File...", nullptr));
        actionPlugins->setText(QApplication::translate("ATEnvironmentClass", "Plugins", nullptr));
        actionSaveFile->setText(QApplication::translate("ATEnvironmentClass", "Save", nullptr));
        actionSaveAsFile->setText(QApplication::translate("ATEnvironmentClass", "Save as...", nullptr));
        actionSave_all->setText(QApplication::translate("ATEnvironmentClass", "Save all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_all->setShortcut(QApplication::translate("ATEnvironmentClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpenProject->setText(QApplication::translate("ATEnvironmentClass", "Project...", nullptr));
        actionOpenFile->setText(QApplication::translate("ATEnvironmentClass", "File...", nullptr));
        actionBuildProject->setText(QApplication::translate("ATEnvironmentClass", "Build Project", nullptr));
        actionBuildCleanProject->setText(QApplication::translate("ATEnvironmentClass", "Clean", nullptr));
        menuFile->setTitle(QApplication::translate("ATEnvironmentClass", "File", nullptr));
        menuNew->setTitle(QApplication::translate("ATEnvironmentClass", "New", nullptr));
        menuOpen->setTitle(QApplication::translate("ATEnvironmentClass", "Open", nullptr));
        menuView->setTitle(QApplication::translate("ATEnvironmentClass", "View", nullptr));
        menuHelp->setTitle(QApplication::translate("ATEnvironmentClass", "Help", nullptr));
        menuTools->setTitle(QApplication::translate("ATEnvironmentClass", "Tools", nullptr));
        menuBuild->setTitle(QApplication::translate("ATEnvironmentClass", "Build", nullptr));
        dwProjectExplorer->setWindowTitle(QApplication::translate("ATEnvironmentClass", "Project Explorer", nullptr));
        dockPlanner->setWindowTitle(QApplication::translate("ATEnvironmentClass", "Planner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ATEnvironmentClass: public Ui_ATEnvironmentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATENVIRONMENT_H

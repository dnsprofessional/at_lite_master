/********************************************************************************
** Form generated from reading UI file 'windowres.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWRES_H
#define UI_WINDOWRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupres;
    QListWidget *listres;
    QTextBrowser *textBrowser;
    QLabel *label;
    QTableWidget *tableanoms;
    QWidget *tab_2;
    QLabel *label_2;
    QGroupBox *groupres_2;
    QListWidget *listres_2;
    QTextBrowser *textBrowser_2;
    QTableWidget *tableanoms_2;
    QPushButton *exitButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QLatin1String("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(745, 642);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMaximumSize(QSize(800, 800));
        Dialog->setSizeGripEnabled(false);
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QLatin1String("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 721, 591));
        tab = new QWidget();
        tab->setObjectName(QLatin1String("tab"));
        groupres = new QGroupBox(tab);
        groupres->setObjectName(QLatin1String("groupres"));
        groupres->setGeometry(QRect(10, 250, 681, 301));
        listres = new QListWidget(groupres);
        listres->setObjectName(QLatin1String("listres"));
        listres->setGeometry(QRect(10, 30, 181, 261));
        textBrowser = new QTextBrowser(groupres);
        textBrowser->setObjectName(QLatin1String("textBrowser"));
        textBrowser->setGeometry(QRect(200, 30, 471, 261));
        label = new QLabel(tab);
        label->setObjectName(QLatin1String("label"));
        label->setGeometry(QRect(10, 20, 241, 21));
        label->setTextFormat(Qt::AutoText);
        tableanoms = new QTableWidget(tab);
        if (tableanoms->columnCount() < 2)
            tableanoms->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableanoms->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableanoms->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableanoms->setObjectName(QLatin1String("tableanoms"));
        tableanoms->setGeometry(QRect(10, 50, 681, 191));
        tableanoms->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableanoms->setShowGrid(true);
        tableanoms->setGridStyle(Qt::SolidLine);
        tableanoms->horizontalHeader()->setVisible(false);
        tableanoms->horizontalHeader()->setCascadingSectionResizes(false);
        tableanoms->horizontalHeader()->setDefaultSectionSize(339);
        tableanoms->horizontalHeader()->setStretchLastSection(true);
        tableanoms->verticalHeader()->setVisible(false);
        tableanoms->verticalHeader()->setDefaultSectionSize(40);
        tableanoms->verticalHeader()->setHighlightSections(true);
        tableanoms->verticalHeader()->setMinimumSectionSize(21);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QLatin1String("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QLatin1String("label_2"));
        label_2->setGeometry(QRect(10, 20, 241, 21));
        label_2->setTextFormat(Qt::AutoText);
        groupres_2 = new QGroupBox(tab_2);
        groupres_2->setObjectName(QLatin1String("groupres_2"));
        groupres_2->setGeometry(QRect(10, 250, 681, 301));
        listres_2 = new QListWidget(groupres_2);
        listres_2->setObjectName(QLatin1String("listres_2"));
        listres_2->setGeometry(QRect(10, 30, 201, 261));
        textBrowser_2 = new QTextBrowser(groupres_2);
        textBrowser_2->setObjectName(QLatin1String("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(220, 30, 451, 261));
        tableanoms_2 = new QTableWidget(tab_2);
        if (tableanoms_2->columnCount() < 2)
            tableanoms_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableanoms_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableanoms_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableanoms_2->setObjectName(QLatin1String("tableanoms_2"));
        tableanoms_2->setGeometry(QRect(10, 50, 681, 191));
        tableanoms_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableanoms_2->setShowGrid(true);
        tableanoms_2->setGridStyle(Qt::SolidLine);
        tableanoms_2->horizontalHeader()->setVisible(false);
        tableanoms_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableanoms_2->horizontalHeader()->setDefaultSectionSize(339);
        tableanoms_2->horizontalHeader()->setStretchLastSection(true);
        tableanoms_2->verticalHeader()->setVisible(false);
        tableanoms_2->verticalHeader()->setDefaultSectionSize(40);
        tableanoms_2->verticalHeader()->setHighlightSections(true);
        tableanoms_2->verticalHeader()->setMinimumSectionSize(21);
        tabWidget->addTab(tab_2, QString());
        exitButton = new QPushButton(Dialog);
        exitButton->setObjectName(QLatin1String("exitButton"));
        exitButton->setGeometry(QRect(640, 610, 89, 25));

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\237\321\200\320\276\321\202\320\272\320\276\320\273 \320\262\320\265\321\200\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270", nullptr));
        groupres->setTitle(QString());
        label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\320\230\321\201\320\272\320\276\320\274\321\213\320\265 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270:</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableanoms->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "\320\242\320\270\320\277 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableanoms->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "\320\242\320\265\320\274\320\277\320\276\321\200\320\260\320\273\321\214\320\275\321\213\320\265 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270", nullptr));
        label_2->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\320\230\321\201\320\272\320\276\320\274\321\213\320\265 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270:</span></p></body></html>", nullptr));
        groupres_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem2 = tableanoms_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("Dialog", "\320\242\320\270\320\277 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableanoms_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("Dialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "\320\221\320\260\320\267\320\276\320\262\321\213\320\265 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270", nullptr));
        exitButton->setText(QApplication::translate("Dialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWRES_H

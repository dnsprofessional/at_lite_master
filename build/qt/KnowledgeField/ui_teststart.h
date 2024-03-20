/********************************************************************************
** Form generated from reading UI file 'teststart.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSTART_H
#define UI_TESTSTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TestStart
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *TestStart)
    {
        if (TestStart->objectName().isEmpty())
            TestStart->setObjectName(QStringLiteral("TestStart"));
        TestStart->resize(752, 300);
        label = new QLabel(TestStart);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 20, 341, 34));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton = new QPushButton(TestStart);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 120, 341, 48));
        pushButton_2 = new QPushButton(TestStart);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 120, 341, 48));

        retranslateUi(TestStart);

        QMetaObject::connectSlotsByName(TestStart);
    } // setupUi

    void retranslateUi(QDialog *TestStart)
    {
        TestStart->setWindowTitle(QApplication::translate("TestStart", "Dialog", nullptr));
        label->setText(QApplication::translate("TestStart", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265?", nullptr));
        pushButton->setText(QApplication::translate("TestStart", "\320\234\320\276\320\264\320\265\320\273\321\214\320\275\321\213\320\271 \320\264\320\270\320\260\320\273\320\276\320\263 \342\204\2261", nullptr));
        pushButton_2->setText(QApplication::translate("TestStart", "\320\234\320\276\320\264\320\265\320\273\321\214\320\275\321\213\320\271 \320\264\320\270\320\260\320\273\320\276\320\263 \342\204\2262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestStart: public Ui_TestStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSTART_H

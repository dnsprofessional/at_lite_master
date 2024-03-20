/********************************************************************************
** Form generated from reading UI file 'alertshow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERTSHOW_H
#define UI_ALERTSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_alertshow
{
public:
    QLabel *label;
    QFrame *frame;
    QGridLayout *gridLayout;
    QTextEdit *m_pre;
    QTextEdit *m_act;
    QTextEdit *ss_pre;
    QTextEdit *ss_act;
    QTextEdit *si_pre;
    QTextEdit *si_act;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *alertshow)
    {
        if (alertshow->objectName().isEmpty())
            alertshow->setObjectName(QStringLiteral("alertshow"));
        alertshow->resize(1354, 992);
        label = new QLabel(alertshow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 10, 451, 34));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        frame = new QFrame(alertshow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(390, 140, 931, 841));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_pre = new QTextEdit(frame);
        m_pre->setObjectName(QStringLiteral("m_pre"));

        gridLayout->addWidget(m_pre, 0, 0, 1, 1);

        m_act = new QTextEdit(frame);
        m_act->setObjectName(QStringLiteral("m_act"));

        gridLayout->addWidget(m_act, 0, 1, 1, 1);

        ss_pre = new QTextEdit(frame);
        ss_pre->setObjectName(QStringLiteral("ss_pre"));

        gridLayout->addWidget(ss_pre, 1, 0, 1, 1);

        ss_act = new QTextEdit(frame);
        ss_act->setObjectName(QStringLiteral("ss_act"));

        gridLayout->addWidget(ss_act, 1, 1, 1, 1);

        si_pre = new QTextEdit(frame);
        si_pre->setObjectName(QStringLiteral("si_pre"));

        gridLayout->addWidget(si_pre, 2, 0, 1, 1);

        si_act = new QTextEdit(frame);
        si_act->setObjectName(QStringLiteral("si_act"));

        gridLayout->addWidget(si_act, 2, 1, 1, 1);

        label_2 = new QLabel(alertshow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 80, 331, 51));
        label_3 = new QLabel(alertshow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(920, 80, 331, 51));
        label_4 = new QLabel(alertshow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 240, 381, 51));
        label_5 = new QLabel(alertshow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 540, 381, 81));
        label_6 = new QLabel(alertshow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 810, 381, 81));

        retranslateUi(alertshow);

        QMetaObject::connectSlotsByName(alertshow);
    } // setupUi

    void retranslateUi(QDialog *alertshow)
    {
        alertshow->setWindowTitle(QApplication::translate("alertshow", "Dialog", nullptr));
        label->setText(QApplication::translate("alertshow", "\320\244\320\276\321\200\320\274\320\260 \320\264\320\273\321\217 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_2->setText(QApplication::translate("alertshow", "\320\236\320\266\320\270\320\264\320\260\320\265\320\274\321\213\320\271 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_3->setText(QApplication::translate("alertshow", "\320\244\320\260\320\272\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_4->setText(QApplication::translate("alertshow", "\320\234\320\276\321\200\321\204\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\260\320\275\320\260\320\273\320\270\320\267", nullptr));
        label_5->setText(QApplication::translate("alertshow", "\320\241\320\270\320\275\321\202\320\260\320\272\321\202\320\270\320\272\320\276-\321\201\320\265\320\274\320\260\320\275\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271\n"
"\320\260\320\275\320\260\320\273\320\270\320\267", nullptr));
        label_6->setText(QApplication::translate("alertshow", "\320\241\320\265\320\274\320\260\320\275\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217\n"
"\320\270\320\275\321\202\320\265\321\200\320\277\321\200\320\265\321\202\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alertshow: public Ui_alertshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERTSHOW_H

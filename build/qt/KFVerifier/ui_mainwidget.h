/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QFrame *frameAnom;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupTempAnom;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkEventsWithoutRef;
    QCheckBox *checkIntervalsWithoutRef;
    QCheckBox *checkWrongAttributesValues;
    QCheckBox *checkImpossiblePositioning;
    QGroupBox *groupBaseAnom;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkExcessiveRules;
    QCheckBox *checkIntersecionRules;
    QFrame *frame_2;
    QLabel *label;
    QWidget *widget;
    QLabel *label_2;
    QTextBrowser *non_t_count_le;
    QTextBrowser *t_count_le;
    QLabel *label_3;
    QPushButton *verifyButton;
    QComboBox *comboBox;
    QLabel *label_4;
    QPushButton *seeKFButtom;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QLatin1String("MainWidget"));
        MainWidget->resize(718, 465);
        frameAnom = new QFrame(MainWidget);
        frameAnom->setObjectName(QLatin1String("frameAnom"));
        frameAnom->setGeometry(QRect(9, 50, 691, 211));
        frameAnom->setFrameShape(QFrame::StyledPanel);
        frameAnom->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameAnom);
        horizontalLayout->setObjectName(QLatin1String("horizontalLayout"));
        groupTempAnom = new QGroupBox(frameAnom);
        groupTempAnom->setObjectName(QLatin1String("groupTempAnom"));
        verticalLayout_3 = new QVBoxLayout(groupTempAnom);
        verticalLayout_3->setObjectName(QLatin1String("verticalLayout_3"));
        checkEventsWithoutRef = new QCheckBox(groupTempAnom);
        checkEventsWithoutRef->setObjectName(QLatin1String("checkEventsWithoutRef"));

        verticalLayout_3->addWidget(checkEventsWithoutRef);

        checkIntervalsWithoutRef = new QCheckBox(groupTempAnom);
        checkIntervalsWithoutRef->setObjectName(QLatin1String("checkIntervalsWithoutRef"));

        verticalLayout_3->addWidget(checkIntervalsWithoutRef);

        checkWrongAttributesValues = new QCheckBox(groupTempAnom);
        checkWrongAttributesValues->setObjectName(QLatin1String("checkWrongAttributesValues"));

        verticalLayout_3->addWidget(checkWrongAttributesValues);

        checkImpossiblePositioning = new QCheckBox(groupTempAnom);
        checkImpossiblePositioning->setObjectName(QLatin1String("checkImpossiblePositioning"));

        verticalLayout_3->addWidget(checkImpossiblePositioning);


        horizontalLayout->addWidget(groupTempAnom);

        groupBaseAnom = new QGroupBox(frameAnom);
        groupBaseAnom->setObjectName(QLatin1String("groupBaseAnom"));
        verticalLayout = new QVBoxLayout(groupBaseAnom);
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        checkExcessiveRules = new QCheckBox(groupBaseAnom);
        checkExcessiveRules->setObjectName(QLatin1String("checkExcessiveRules"));

        verticalLayout->addWidget(checkExcessiveRules);

        checkIntersecionRules = new QCheckBox(groupBaseAnom);
        checkIntersecionRules->setObjectName(QLatin1String("checkIntersecionRules"));

        verticalLayout->addWidget(checkIntersecionRules);


        horizontalLayout->addWidget(groupBaseAnom);

        frame_2 = new QFrame(MainWidget);
        frame_2->setObjectName(QLatin1String("frame_2"));
        frame_2->setGeometry(QRect(10, 270, 691, 141));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_2);
        label->setObjectName(QLatin1String("label"));
        label->setGeometry(QRect(20, 10, 67, 17));
        widget = new QWidget(frame_2);
        widget->setObjectName(QLatin1String("widget"));
        widget->setGeometry(QRect(10, 30, 671, 101));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QLatin1String("label_2"));
        label_2->setGeometry(QRect(60, 10, 601, 41));
        non_t_count_le = new QTextBrowser(widget);
        non_t_count_le->setObjectName(QLatin1String("non_t_count_le"));
        non_t_count_le->setGeometry(QRect(0, 10, 51, 31));
        t_count_le = new QTextBrowser(widget);
        t_count_le->setObjectName(QLatin1String("t_count_le"));
        t_count_le->setGeometry(QRect(0, 60, 51, 31));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QLatin1String("label_3"));
        label_3->setGeometry(QRect(60, 50, 601, 41));
        verifyButton = new QPushButton(MainWidget);
        verifyButton->setObjectName(QLatin1String("verifyButton"));
        verifyButton->setGeometry(QRect(580, 420, 121, 31));
        comboBox = new QComboBox(MainWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QLatin1String("comboBox"));
        comboBox->setGeometry(QRect(200, 10, 251, 25));
        comboBox->setEditable(false);
        label_4 = new QLabel(MainWidget);
        label_4->setObjectName(QLatin1String("label_4"));
        label_4->setGeometry(QRect(16, 10, 161, 20));
        seeKFButtom = new QPushButton(MainWidget);
        seeKFButtom->setObjectName(QLatin1String("seeKFButtom"));
        seeKFButtom->setGeometry(QRect(500, 10, 201, 31));

        retranslateUi(MainWidget);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Form", nullptr));
        groupTempAnom->setTitle(QApplication::translate("MainWidget", "\320\242\320\265\320\274\320\277\320\276\321\200\320\260\320\273\321\214\320\275\321\213\320\265 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270", nullptr));
        checkEventsWithoutRef->setText(QApplication::translate("MainWidget", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217 \320\261\320\265\320\267 \321\201\321\201\321\213\320\273\320\276\320\272", nullptr));
        checkIntervalsWithoutRef->setText(QApplication::translate("MainWidget", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273\321\213 \320\261\320\265\320\267 \321\201\321\201\321\213\320\273\320\276\320\272", nullptr));
        checkWrongAttributesValues->setText(QApplication::translate("MainWidget", "\320\235\320\265\320\262\320\265\321\200\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\260\321\202\321\200\320\270\320\261\321\203\321\202\320\260", nullptr));
        checkImpossiblePositioning->setText(QApplication::translate("MainWidget", "\320\235\320\265\320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276\320\265 \320\262\320\267\320\260\320\270\320\274\320\276\321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\201\320\276\320\261\321\213\321\202\320\270\320\271 \320\270\n"
" \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\276\320\262", nullptr));
        groupBaseAnom->setTitle(QApplication::translate("MainWidget", "\320\221\320\260\320\267\320\276\320\262\321\213\320\265 \320\260\320\275\320\276\320\274\320\260\320\273\320\270\320\270", nullptr));
        checkExcessiveRules->setText(QApplication::translate("MainWidget", "\320\230\320\267\320\261\321\213\321\202\320\276\321\207\320\275\321\213\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        checkIntersecionRules->setText(QApplication::translate("MainWidget", "\320\237\320\265\321\200\320\265\321\201\320\265\320\272\320\260\321\216\321\211\320\270\320\265\321\201\321\217 \320\277\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        label->setText(QApplication::translate("MainWidget", "\320\235\320\260\320\271\320\264\320\265\320\275\320\276", nullptr));
        label_2->setText(QApplication::translate("MainWidget", "\320\237\321\200\320\260\320\262\320\270\320\273, \320\275\320\265 \321\201\320\276\320\264\320\265\321\200\320\266\320\260\321\211\320\270\321\205 \321\202\320\265\320\274\320\277\320\276\321\200\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\321\203\321\211\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_3->setText(QApplication::translate("MainWidget", "\320\237\321\200\320\260\320\262\320\270\320\273, \321\201\320\276\320\264\320\265\321\200\320\266\320\260\321\211\320\270\321\205 \321\202\320\265\320\274\320\277\320\276\321\200\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\321\203\321\211\320\275\320\276\321\201\321\202\320\270", nullptr));
        verifyButton->setText(QApplication::translate("MainWidget", "\320\222\320\265\321\200\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWidget", "kf", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWidget", "test_kf", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWidget", "test_kf_1", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWidget", "test_kf_2", nullptr));

        label_4->setText(QApplication::translate("MainWidget", "\320\222\320\265\321\200\320\270\321\204\320\270\321\206\320\270\321\200\321\203\320\265\320\274\320\276\320\265 \320\237\320\227:", nullptr));
        seeKFButtom->setText(QApplication::translate("MainWidget", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\277\320\276\320\273\320\265 \320\267\320\275\320\260\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H

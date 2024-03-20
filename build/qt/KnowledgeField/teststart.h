#ifndef TESTSTART_H
#define TESTSTART_H

#include "/home/everyone/Bobrovskaya8_2/at_lite-amrr-md-mod/build/qt/KnowledgeField/alertshow.h"
#include <QDialog>

namespace Ui {
class TestStart;
}

class TestStart : public QDialog
{
    Q_OBJECT

public:
    explicit TestStart(QWidget *parent = nullptr);
    ~TestStart();

private slots:
   alertshow* on_pushButton_clicked();

   alertshow* on_pushButton_2_clicked();

private:
    Ui::TestStart *ui;
};

#endif // TESTSTART_H

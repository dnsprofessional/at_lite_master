#ifndef TESTSTART_H
#define TESTSTART_H

#include "/home/malloc/at_lite-master/build/qt/KnowledgeField/alertshow.h"
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

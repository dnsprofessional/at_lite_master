#include "debug_pz.h"
#include "ui_debug_pz.h"

#include <QStandardIte
m>

#include <iostream>

DebugPZ::DebugPZ(QWidget* parent, const QString& bz)
    : QDialog(parent)
    , ui(new Ui::DebugPZ)
{
    ui->setupUi(this);

    ui->plainTextEdit->setPlainText(bz);
}

DebugPZ::~DebugPZ()
{
     ui;
}

void DebugPZ::on_pushButton_clicked()
{
    hide();
}

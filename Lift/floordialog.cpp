#include "floordialog.h"
#include "ui_floordialog.h"

FloorDialog::FloorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FloorDialog)
{
    ui->setupUi(this);
}

FloorDialog::~FloorDialog()
{
    delete ui;
}

int FloorDialog::getFloorNumber(){
    return ui->spinBox->value();
}

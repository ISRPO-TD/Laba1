#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    setConnections();
    QDoubleValidator* doubleValidator = new QDoubleValidator(this);
    ui->leDeposit->setValidator(doubleValidator);

    ui->rbAmericano->setChecked(true);
    on_rbBeverage_clicked();
    updateNumbers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setConnections(){
    QObject::connect(ui->rbAmericano, SIGNAL(clicked()), this, SLOT(on_rbBeverage_clicked()));
    QObject::connect(ui->rbCacao, SIGNAL(clicked()), this, SLOT(on_rbBeverage_clicked()));
    QObject::connect(ui->rbCapuchino, SIGNAL(clicked()), this, SLOT(on_rbBeverage_clicked()));
    QObject::connect(ui->rbEspresso, SIGNAL(clicked()), this, SLOT(on_rbBeverage_clicked()));

    QObject::connect(ui->cbSugar, SIGNAL(clicked()), this, SLOT(on_rbBeverage_clicked()));
    QObject::connect(ui->cbMilk, SIGNAL(clicked()), this, SLOT(on_rbBeverage_clicked()));
}

void MainWindow::on_rbBeverage_clicked()
{
    if (currBeverage != nullptr){
        delete currBeverage;
        currBeverage = nullptr;
    }

    if (ui->rbAmericano->isChecked()){
        ui->beverageImg->setStyleSheet("image: url(:/img/Res/Americano.png);");
        currBeverage = new Americano();
    }
    else if (ui->rbCapuchino->isChecked()){
        ui->beverageImg->setStyleSheet("image: url(:/img/Res/Capuchino.png);");
        currBeverage = new Capuchino();
    }
    else if (ui->rbCacao->isChecked()){
        ui->beverageImg->setStyleSheet("image: url(:/img/Res/Cacao.png);");
        currBeverage = new Cacao();
    }
    else if (ui->rbEspresso->isChecked()){
        ui->beverageImg->setStyleSheet("image: url(:/img/Res/Espresso.png);");
        currBeverage = new Espresso();
    }

    if (ui->cbMilk->isChecked()){
        ui->milkImg->setStyleSheet("image: url(:/img/Res/Milk.png);");
        currBeverage = new Milk(*currBeverage);
    } else
        ui->milkImg->setStyleSheet("");

    if (ui->cbSugar->isChecked()){
        ui->sugarImg->setStyleSheet("image: url(:/img/Res/Sugar.png);");
        currBeverage = new Sugar(*currBeverage);
    } else
        ui->sugarImg->setStyleSheet("");

    ui->label_2->setText("Цена напитка: " + QString::number(currBeverage->getCost()));

    updateNumbers();
}

void MainWindow::on_btnDeposit_clicked()
{
    bool ok;
    double deposit = ui->leDeposit->text().toDouble(&ok);
    if (ok) {
        DepositedCash += deposit;
    }
    updateNumbers();
}

void MainWindow::on_btnBuy_clicked()
{
    if (DepositedCash > currBeverage->getCost()){
        DepositedCash = DepositedCash - currBeverage->getCost();
    }
    else {
        QMessageBox msg;
        msg.setText("Недостаточно денег");
    }
    updateNumbers();
}

void MainWindow::updateNumbers(){
    ui->label_3->setText("Внесенная сумма: " + QString::number(DepositedCash));
    ui->label_2->setText("Цена напитка: " + QString::number(currBeverage->getCost()));
    if (DepositedCash > currBeverage->getCost())
        ui->label->setText("Сдача: " + QString::number(DepositedCash - currBeverage->getCost()));
    else
        ui->label->setText("Сдача: нет");
}

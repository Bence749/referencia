#include "szamol.h"
#include "ui_szamol.h"
#include <QRandomGenerator>
#include <QMessageBox>

szamol::szamol(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::szamol)
{
    ui->setupUi(this);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(changeOp()));
    connect(ui->mult, SIGNAL(clicked()), this, SLOT(changeOp()));
    connect(ui->sub, SIGNAL(clicked()), this, SLOT(changeOp()));
    connect(ui->div, SIGNAL(clicked()), this, SLOT(changeOp()));
    connect(ui->generate, SIGNAL(clicked()), this, SLOT(generate()));

}

void szamol::changeOp()
{
    if(ui->add->isChecked()) ui->operation->setText("+");
    if(ui->mult->isChecked()) ui->operation->setText("*");
    if(ui->sub->isChecked()) ui->operation->setText("-");
    if(ui->div->isChecked()) ui->operation->setText("/");
}

void szamol::generate()
{
    ui->firstNum->setText(QString::number(QRandomGenerator::global()->bounded(100)));
    ui->secondNum->setText(QString::number(QRandomGenerator::global()->bounded(100)));
    ui->generate->setText("Értékel");
    ui->equalNum->clear();
    ui->add->setDisabled(true);
    ui->mult->setDisabled(true);
    ui->sub->setDisabled(true);
    ui->div->setDisabled(true);
    disconnect(ui->generate, SIGNAL(clicked()), this, SLOT(generate()));
    connect(ui->equalNum, SIGNAL(returnPressed()), this, SLOT(evaluate()));
    connect(ui->generate, SIGNAL(clicked()), this, SLOT(evaluate()));

}

void szamol::evaluate()
{
    bool success;
    int input = ui->equalNum->text().toInt(&success);
    int firstIn = ui->firstNum->text().toInt();
    int secondIn = ui->secondNum->text().toInt();
    if(success)
    {
        if(ui->add->isChecked() && input == (firstIn + secondIn)) ui->results->addItem("Jó: " + QString::number(firstIn) + " + " + QString::number(secondIn) + " = " + QString::number(input));
            else if(ui->add->isChecked()) ui->results->addItem("Rossz: " + QString::number(firstIn) + " + " + QString::number(secondIn) + " = " + QString::number(input));
        if(ui->mult->isChecked() && input == (firstIn * secondIn)) ui->results->addItem("Jó: " + QString::number(firstIn) + " * " + QString::number(secondIn) + " = " + QString::number(input));
        else if(ui->mult->isChecked()) ui->results->addItem("Rossz: " + QString::number(firstIn) + " * " + QString::number(secondIn) + " = " + QString::number(input));
        if(ui->sub->isChecked() && input == (firstIn - secondIn)) ui->results->addItem("Jó: " + QString::number(firstIn) + " - " + QString::number(secondIn) + " = " + QString::number(input));
        else if(ui->sub->isChecked()) ui->results->addItem("Rossz: " + QString::number(firstIn) + " - " + QString::number(secondIn) + " = " + QString::number(input));
        if(ui->div->isChecked() && input == (firstIn / secondIn)) ui->results->addItem("Jó: " + QString::number(firstIn) + " / " + QString::number(secondIn) + " = " + QString::number(input));
        else if(ui->div->isChecked()) ui->results->addItem("Rossz: " + QString::number(firstIn) + " / " + QString::number(secondIn) + " = " + QString::number(input));
        connect(ui->generate, SIGNAL(clicked()), this, SLOT(generate()));
        disconnect(ui->equalNum, SIGNAL(returnPressed()), this, SLOT(evaluate()));
        disconnect(ui->generate, SIGNAL(clicked()), this, SLOT(evaluate()));
        ui->add->setDisabled(false);
        ui->mult->setDisabled(false);
        ui->sub->setDisabled(false);
        ui->div->setDisabled(false);
        ui->generate->setText("Generál");
    }
    else error();
}

void szamol::error()
{
    QMessageBox::warning(this, "Rossz bemenet!", "A megadott érték nem megfelelő formátumú! Próbáld újra");
}
szamol::~szamol()
{
    delete ui;
}


#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lcdTokyo->setTimeZone(7);
    ui->lcdLondon->setTimeZone(-1);
    ui->lcdNewYork->setTimeZone(-6);
}

Form::~Form()
{
    delete ui;
}

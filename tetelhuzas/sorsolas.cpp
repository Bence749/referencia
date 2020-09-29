#include "sorsolas.h"
#include "ui_sorsolas.h"
#include <QTimer>
#include <QMessageBox>

sorsolas::sorsolas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sorsolas)
{
    ui->setupUi(this);
    ui->settings->hide();
    ui->startButton->setCheckable(true);
    ui->settingsButton->setCheckable(true);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showRandom()));
    connect(ui->settingsButton, SIGNAL(clicked()), this, SLOT(showSetting()));
    timer->start(10);


}

void sorsolas::showRandom()
{
    if(ui->startButton->isChecked() && !ui->settingsButton->isChecked())
    {
        wasActive = true;
        ui->startButton->setText("STOP");
        int random;
        do
        {
            random = qrand() % maxTetel + 1;
        } while(huzott.contains(random));
        ui->numberBox->setText("<p align=center>" + QString::number(random) + "</p>");
    }
    else
    {
        if(wasActive)
        {
            huzott.push_back(ui->numberBox->toPlainText().toInt());
            wasActive = false;
            ++aktiv;
            if(aktiv > letszam)
                huzott.pop_front();
        }
        ui->startButton->setText("START");
    }
}

void sorsolas::showSetting()
{
    if(ui->settingsButton->isChecked() && !ui->startButton->isChecked())
    {
        ui->settings->show();
        ui->settingsButton->setText("Mehet");
        connect(ui->settingsButton, SIGNAL(clicked()), this, SLOT(setInput()));
    }
}

void sorsolas::setInput()
{
    bool siker1, siker2;
    maxTetel = ui->settingTetel->text().toInt(&siker1, 10);
    letszam = ui->settingLet->text().toInt(&siker2, 10);
    if (siker1 == true && siker2 == true && letszam < maxTetel)
    {
        ui->settings->hide();
        ui->settingsButton->setText("Beállítás");
        ui->settingLet->clear();
        ui->settingTetel->clear();
        huzott.clear();
        disconnect(ui->settingsButton, SIGNAL(clicked()), this, SLOT(setInput()));
    }
    else {
        ui->settingsButton->setChecked(true);
    }
}


sorsolas::~sorsolas()
{
    delete ui;
}


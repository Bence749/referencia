#include "quitwidget.h"
#include "ui_quitwidget.h"

QuitWidget::QuitWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QuitWidget)
{
    ui->setupUi(this);
    //connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quitButton_onClick()));
}

QuitWidget::~QuitWidget()
{
    delete ui;
}

/*void QuitWidget::quitButton_onClick()
{
    close();
}*/

void QuitWidget::on_quitButton_clicked()
{
    close();
}

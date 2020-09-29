#include "game.h"
#include "ui_game.h"
#include <QMessageBox>

game::game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);
    generateTable();
}

void game::generateTable()
{
    if(player == 1) ui->playerIndicator->setText("Fehér következik!");
    else ui->playerIndicator->setText("Fekete következik!");
    _playingTable.resize(8);
    for(int i = 0; i < 8; i++)
    {
        _playingTable[i].resize(8);
        for(int j = 0; j < 8; j++)
        {
            _playingTable[i][j] = new QPushButton(this);
            if(i < 2)
            {
                _playingTable[i][j]->setStyleSheet("background-color: white");
                _playingTable[i][j]->setAccessibleName("p1");
                connect(_playingTable[i][j], SIGNAL(clicked()), this, SLOT(fieldSelect()));
            }
            else if(i > 5)
            {
                _playingTable[i][j]->setStyleSheet("background-color: black");
                _playingTable[i][j]->setAccessibleName("p2");
                connect(_playingTable[i][j], SIGNAL(clicked()), this, SLOT(fieldSelect()));
            }
            else
                _playingTable[i][j]->setStyleSheet("background-color: blue");
            _playingTable[i][j]->setCheckable(true);
            _playingTable[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            ui->playArea->addWidget(_playingTable[i][j], i , j);
        }
    }
    deactivate();
}

void game::fieldSelect()
{
    QPushButton* selectedField = dynamic_cast<QPushButton*>(QObject::sender());
    int location = ui->playArea->indexOf(selectedField);
    selectedField->setDefault(true);
    selectedField->setChecked(false);
    detoggleOthers(location / 8, location % 8);
    switch(player)
    {
        case 1: if(selectedField->accessibleName() == "p1") possibleSteps(location/8, location % 8);
            break;
        case 2: if(selectedField->accessibleName() == "p2") possibleSteps(location/8, location % 8);
            break;
    };
}

void game::possibleSteps(int x, int y)
{
    if(player == 1)
    {
        for(int i = -1; i <= 1; i++)
        {
            if((y+i < 8 && y+i >= 0) && (((i == 0 && _playingTable[x+1][y+i]->accessibleName() != "p2"))
                || (i != 0)) && _playingTable[x+1][y+i]->accessibleName() != "p1")
            {
                _playingTable[x+1][y+i]->toggle();
                _playingTable[x+1][y+i]->setEnabled(true);
                disconnect(_playingTable[x+1][y+i], SIGNAL(clicked()), this, SLOT(fieldSelect()));
                connect(_playingTable[x+1][y+i], SIGNAL(clicked()), this, SLOT(step()));
            }
        }
    } else
    {
        for(int i = -1; i <= 1; i++)
        {
            if((y+i < 8 && y+i >= 0) && (((i == 0 && _playingTable[x-1][y+i]->accessibleName() != "p1"))
                || (i != 0)) && _playingTable[x-1][y+i]->accessibleName() != "p2")
            {
                _playingTable[x-1][y+i]->toggle();
                _playingTable[x-1][y+i]->setEnabled(true);
                disconnect(_playingTable[x-1][y+i], SIGNAL(clicked()), this, SLOT(fieldSelect()));
                connect(_playingTable[x-1][y+i], SIGNAL(clicked()), this, SLOT(step()));
            }
        }
    }
}

void game::step()
{
    QPushButton* selectedField = dynamic_cast<QPushButton*>(QObject::sender());
    int location = ui->playArea->indexOf(selectedField);
    if(player == 1)
    {
        for(int i = -1; i <= 1; i++)
            if(location % 8 + i >= 0 && location % 8 + i < 8 && _playingTable[location/8 - 1][location % 8 + i]->isDefault())
                swapButtons(_playingTable[location/8 - 1][location % 8 + i], selectedField);
        player = 2;
        ui->playerIndicator->setText("Fekete következik!");
    } else
    {
        for(int i = -1; i <= 1; i++)
            if(location % 8 + i >= 0 && location % 8 + i < 8 && _playingTable[location/8 + 1][location % 8 + i]->isDefault())
                swapButtons(_playingTable[location/8 + 1][location % 8 + i], selectedField);
        player = 1;
        ui->playerIndicator->setText("Fehér következik!");
    }
    deactivate();
    detoggleOthers();
    refreshArea();
    checkWin();
}

void game::detoggleOthers(int x, int y)
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(!(i == x && j == y)) _playingTable[i][j]->setChecked(false);
}

void game::detoggleOthers()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            _playingTable[i][j]->setChecked(false);
}

void game::deactivate()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if(_playingTable[i][j]->accessibleName() == "p1" && player == 1) _playingTable[i][j]->setEnabled(true);
            else if(_playingTable[i][j]->accessibleName() == "p2" && player == 2) _playingTable[i][j]->setEnabled(true);
            else _playingTable[i][j]->setEnabled(false);
            _playingTable[i][j]->setDefault(false);
            disconnect(_playingTable[i][j], SIGNAL(clicked()), this, SLOT(step()));
            connect(_playingTable[i][j], SIGNAL(clicked()), this, SLOT(fieldSelect()));
        }
}

void game::swapButtons(QPushButton* x, QPushButton* y)
{
    int locX = ui->playArea->indexOf(x);
    int locY = ui->playArea->indexOf(y);

    _playingTable[locX / 8][locX % 8] = y;
    _playingTable[locY / 8][locY % 8] = x;

    if(x->accessibleName() != "")
    {
        _playingTable[locX / 8][locX % 8]->setAccessibleName("");
        _playingTable[locX / 8][locX % 8]->setStyleSheet("background-color: blue");
    }
}

void game::refreshArea()
{

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            ui->playArea->addWidget(_playingTable[i][j], i, j);
}

void game::checkWin()
{
    for(int i = 0; i < 8; i++)
    {
        if(_playingTable[0][i]->accessibleName() == "p2")
        {
            QMessageBox::information(this, tr("Játék vége!"), tr("A fekete nyerte a játékot!"));
            newGame();
            player = 1;
        }
        if(_playingTable[7][i]->accessibleName() == "p1")
        {
            QMessageBox::information(this, tr("Játék vége!"), tr("A fehér nyerte a játékot!"));
            newGame();
            player = 2;
        }
    }
}

void game::newGame()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if(i < 2)
            {
                _playingTable[i][j]->setStyleSheet("background-color: white");
                _playingTable[i][j]->setAccessibleName("p1");
                connect(_playingTable[i][j], SIGNAL(clicked()), this, SLOT(fieldSelect()));
            }
            else if(i > 5)
            {
                _playingTable[i][j]->setStyleSheet("background-color: black");
                _playingTable[i][j]->setAccessibleName("p2");
                connect(_playingTable[i][j], SIGNAL(clicked()), this, SLOT(fieldSelect()));
            }
            else
                _playingTable[i][j]->setStyleSheet("background-color: blue");
            _playingTable[i][j]->setCheckable(true);
            _playingTable[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            ui->playArea->addWidget(_playingTable[i][j], i , j);
        }
    deactivate();
}

game::~game()
{
    delete ui;
}


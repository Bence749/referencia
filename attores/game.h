#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QWidget
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();

private:
    Ui::game *ui;
    QVector<QVector<QPushButton*>> _playingTable;
    int player = 1;
    void generateTable();
    void possibleSteps(int x, int y);
    void detoggleOthers(int x, int y);
    void detoggleOthers();
    void swapButtons(QPushButton* x, QPushButton* y);
    void connectAllField();
    void deactivate();
    void refreshArea();
    void checkWin();
    void newGame();

private slots:
    void fieldSelect();
    void step();
};
#endif // GAME_H

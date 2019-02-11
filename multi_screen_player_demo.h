#ifndef MULTI_SCREEN_PLAYER_DEMO_H
#define MULTI_SCREEN_PLAYER_DEMO_H

#include <QWidget>

namespace Ui {
class multi_screen_player_demo;
}

class multi_screen_player_demo : public QWidget
{
    Q_OBJECT

public:
    explicit multi_screen_player_demo(QWidget *parent = nullptr);
    ~multi_screen_player_demo();

private:
    Ui::multi_screen_player_demo *ui;
};

#endif // MULTI_SCREEN_PLAYER_DEMO_H

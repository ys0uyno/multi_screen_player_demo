#include "multi_screen_player_demo.h"
#include "ui_multi_screen_player_demo.h"

multi_screen_player_demo::multi_screen_player_demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multi_screen_player_demo)
{
    ui->setupUi(this);
}

multi_screen_player_demo::~multi_screen_player_demo()
{
    delete ui;
}

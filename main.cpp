#include "multi_screen_player_demo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    multi_screen_player_demo w;
    w.show();

    return a.exec();
}

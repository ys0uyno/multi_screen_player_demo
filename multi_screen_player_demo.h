#ifndef MULTI_SCREEN_PLAYER_DEMO_H
#define MULTI_SCREEN_PLAYER_DEMO_H

#include "media_player.h"
#include "grid_layout.h"
#include <QWidget>
#include <QtWidgets>

namespace Ui {
class multi_screen_player_demo;
}

class multi_screen_player_demo : public QWidget
{
    Q_OBJECT

public:
    explicit multi_screen_player_demo(QWidget *parent = nullptr);
    ~multi_screen_player_demo();

public slots:
    void openFiles();

private:
    Ui::multi_screen_player_demo *ui;
    grid_layout *gridLayout;
    video_widget *videoWidget;
    QVector<media_player *> mediaPlayerVec;
};

#endif // MULTI_SCREEN_PLAYER_DEMO_H

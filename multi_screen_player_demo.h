#ifndef MULTI_SCREEN_PLAYER_DEMO_H
#define MULTI_SCREEN_PLAYER_DEMO_H

#include "media_player.h"
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

public:
    void setUrl(const QUrl &url);

public slots:
    void openFiles();

private:
    Ui::multi_screen_player_demo *ui;
    media_player *mediaPlayer;
    QGridLayout *gridLayout;
    video_widget *videoWidget;
};

#endif // MULTI_SCREEN_PLAYER_DEMO_H

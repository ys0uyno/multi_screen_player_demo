#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include "video_widget.h"
#include <QMediaPlayer>

class media_player : public QMediaPlayer
{
public:
    media_player(QObject *parent = nullptr, Flags flags = Flags());
    ~media_player();

public:
    video_widget *getVideoWidget() const;

private:
    video_widget *videoWidget;
};

#endif // MEDIA_PLAYER_H

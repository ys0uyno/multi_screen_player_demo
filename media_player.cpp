#include "media_player.h"

media_player::media_player(QObject *parent, Flags flags)
    : QMediaPlayer(parent, flags)
{
    videoWidget = new video_widget;
    setVideoOutput(videoWidget);
}

media_player::~media_player()
{
    delete videoWidget;
}

video_widget *media_player::getVideoWidget() const
{
    return videoWidget;
}

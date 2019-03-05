#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include "video_widget.h"
#include "clickableslider.h"
#include <QMediaPlayer>

class media_player : public QMediaPlayer
{
    Q_OBJECT

public:
    media_player(QObject *parent = nullptr, Flags flags = Flags());
    ~media_player();

public:
    video_widget *getVideoWidget() const;
    QSlider *getSlider() const;
    void setUrlAndPlay(const QUrl &url);

public slots:
    void seek(int seconds);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

private:
    video_widget *videoWidget;
    QSlider *slider;
};

#endif // MEDIA_PLAYER_H

#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include "video_widget.h"
#include "clickableslider.h"
#include <QMediaPlayer>
#include <QLabel>
#include <QTime>

class media_player : public QMediaPlayer
{
    Q_OBJECT

public:
    media_player(QObject *parent = nullptr, Flags flags = Flags());
    ~media_player();

public:
    video_widget *getVideoWidget() const;
    QSlider *getSlider() const;
    QLabel *getLabel() const;
    void setUrlAndPlay(const QUrl &url);

public slots:
    void seek(qint64 milliseconds);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);
    void updateElapsedTime(qint64 elapsed);

private:
    video_widget *videoWidget;
    QSlider *slider;
    QLabel *label;
    qint64 totalMilliseconds;
};

#endif // MEDIA_PLAYER_H

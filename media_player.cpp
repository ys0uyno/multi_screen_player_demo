#include "media_player.h"

media_player::media_player(QObject *parent, Flags flags)
    : QMediaPlayer(parent, flags)
{
    videoWidget = new video_widget;
    setVideoOutput(videoWidget);

    slider = new ClickableSlider(Qt::Horizontal);
    slider->setRange(0, static_cast<int>(duration() / 1000));

    connect(slider, &ClickableSlider::sliderMoved, this, &media_player::seek);
    connect(slider, SIGNAL(sliderClicked(int)), this, SLOT(seek(int)));
    connect(this, &QMediaPlayer::durationChanged, this, &media_player::durationChanged);
    connect(this, &QMediaPlayer::positionChanged, this, &media_player::positionChanged);
}

media_player::~media_player()
{
    delete videoWidget;
}

video_widget *media_player::getVideoWidget() const
{
    return videoWidget;
}

QSlider *media_player::getSlider() const
{
    return slider;
}

void media_player::setUrlAndPlay(const QUrl &url)
{
    setMedia(url);
    play();
}

void media_player::seek(int seconds)
{
    qInfo("media_player::seek");
    setPosition(seconds * 1000);
}

void media_player::durationChanged(qint64 duration)
{
    slider->setMaximum(static_cast<int>(duration / 1000));
}

void media_player::positionChanged(qint64 progress)
{
    if (!slider->isSliderDown()) {
        slider->setValue(static_cast<int>(progress / 1000));
    }
}

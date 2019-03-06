#include "media_player.h"

media_player::media_player(QObject *parent, Flags flags)
    : QMediaPlayer(parent, flags)
{
    videoWidget = new video_widget;
    setVideoOutput(videoWidget);

    slider = new ClickableSlider(Qt::Horizontal);
    slider->setRange(0, static_cast<int>(duration()));

    connect(slider, &ClickableSlider::sliderMoved, this, &media_player::seek);
    connect(slider, SIGNAL(sliderClicked(qint64)), this, SLOT(seek(qint64)));
    connect(this, &QMediaPlayer::durationChanged, this, &media_player::durationChanged);
    connect(this, &QMediaPlayer::positionChanged, this, &media_player::positionChanged);
    connect(this, &QMediaPlayer::positionChanged, this, &media_player::updateElapsedTime);

    label = new QLabel();
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

QLabel *media_player::getLabel() const
{
    return label;
}

void media_player::setUrlAndPlay(const QUrl &url)
{
    setMedia(url);
    play();
}

void media_player::seek(qint64 milliseconds)
{
    setPosition(milliseconds);
}

void media_player::durationChanged(qint64 duration)
{
    totalMilliseconds = duration;
    slider->setMaximum(static_cast<int>(totalMilliseconds));
}

void media_player::positionChanged(qint64 progress)
{
    if (!slider->isSliderDown()) {
        slider->setValue(static_cast<int>(progress));
    }
}

void media_player::updateElapsedTime(qint64 elapsed)
{
    QTime elapsedTime(
                (elapsed / 1000 / 3600) % 60,
                (elapsed / 1000 / 60) % 60,
                (elapsed / 1000) % 60,
                static_cast<int>(elapsed / 1000)
                );
    QTime totalTime(
                (totalMilliseconds / 1000 / 3600) % 60,
                (totalMilliseconds / 1000 / 60) % 60,
                (totalMilliseconds / 1000) % 60,
                static_cast<int>(totalMilliseconds / 1000)
                );

    QString elapsedStr;
    elapsedStr = (totalMilliseconds / 1000 < 3600)
            ? (elapsedTime.toString(QString("mm:ss"))
               + "/"
               + totalTime.toString(QString("mm:ss")))
            : (elapsedTime.toString(QString("hh:mm:ss"))
               + "/"
               + totalTime.toString(QString("hh:mm:ss"))
               );

    label->setText(elapsedStr);
}

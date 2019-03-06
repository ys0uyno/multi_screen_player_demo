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

void media_player::seek(int seconds)
{
    qInfo("media_player::seek");
    setPosition(seconds * 1000);
}

void media_player::durationChanged(qint64 duration)
{
    totalSeconds = duration / 1000;
    slider->setMaximum(static_cast<int>(totalSeconds));
}

void media_player::positionChanged(qint64 progress)
{
    if (!slider->isSliderDown()) {
        slider->setValue(static_cast<int>(progress / 1000));
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
                (totalSeconds / 3600) % 60,
                (totalSeconds / 60) % 60,
                totalSeconds % 60,
                static_cast<int>(totalSeconds)
                );

    QString elapsedStr;
    elapsedStr = (totalSeconds < 3600)
            ? (elapsedTime.toString(QString("mm:ss"))
               + "/"
               + totalTime.toString(QString("mm:ss")))
            : (elapsedTime.toString(QString("hh:mm:ss"))
               + "/"
               + totalTime.toString(QString("hh:mm:ss"))
               );

    label->setText(elapsedStr);
}

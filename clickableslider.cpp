#include "clickableslider.h"

ClickableSlider::ClickableSlider(QWidget *parent)
    : QSlider(parent)
{
}

ClickableSlider::ClickableSlider(Qt::Orientation orientation, QWidget *parent)
    : QSlider(orientation, parent)
{
}

void ClickableSlider::mousePressEvent(QMouseEvent *ev)
{
    QSlider::mousePressEvent(ev);
    qInfo("pos().x(): %d, width(): %d, maximum(): %d, minimum(): %d",
          ev->pos().x(), width(), maximum(), minimum());
    float pos = static_cast<float>(ev->pos().x()) / width();
    int seconds = static_cast<int>(pos * maximum());
    qInfo("seconds: %d", seconds);
    setValue(seconds);
    emit sliderClicked(seconds);
}

#ifndef CLICKABLESLIDER_H
#define CLICKABLESLIDER_H

#include <QSlider>
#include <QMouseEvent>

class ClickableSlider : public QSlider
{
    Q_OBJECT

public:
    ClickableSlider(QWidget *parent = nullptr);
    ClickableSlider(Qt::Orientation orientation, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *ev);

signals:
    void sliderClicked(int);
};

#endif // CLICKABLESLIDER_H

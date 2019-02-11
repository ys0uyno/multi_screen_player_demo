#ifndef VIDEO_WIDGET_H
#define VIDEO_WIDGET_H

#include <QVideoWidget>

class video_widget : public QVideoWidget
{
public:
    explicit video_widget(QWidget *parent = nullptr);
};

#endif // VIDEO_WIDGET_H

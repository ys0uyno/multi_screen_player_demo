#ifndef GRID_LAYOUT_H
#define GRID_LAYOUT_H

#include <QGridLayout>
#include <QVector>
#include <QBoxLayout>

class grid_layout : public QGridLayout
{
public:
    grid_layout();

public:
    void add(QWidget *widget);
    void add(QWidget *wdiget, QWidget *slider);

public slots:
    void relayout();

private:
    QVector<QWidget *> widgetVec;
    QVector<QVBoxLayout *> verticalLayoutVec;
};

#endif // GRID_LAYOUT_H

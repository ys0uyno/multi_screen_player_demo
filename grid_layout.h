#ifndef GRID_LAYOUT_H
#define GRID_LAYOUT_H

#include <QGridLayout>
#include <QVector>

class grid_layout : public QGridLayout
{
public:
    grid_layout();

public:
    void add(QWidget *widget);

public slots:
    void relayout();

private:
    QVector<QWidget *> widgetVec;
};

#endif // GRID_LAYOUT_H

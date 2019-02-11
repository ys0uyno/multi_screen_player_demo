#ifndef GRID_LAYOUT_H
#define GRID_LAYOUT_H

#include <QGridLayout>

class grid_layout : public QGridLayout
{
public:
    grid_layout();

public:
    void add(QWidget *widget);
};

#endif // GRID_LAYOUT_H

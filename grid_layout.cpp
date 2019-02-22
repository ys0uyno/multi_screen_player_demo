#include "grid_layout.h"

grid_layout::grid_layout()
{

}

void grid_layout::add(QWidget *widget)
{
    addWidget(widget);
    widgetVec.push_back(widget);
    relayout();
}

void grid_layout::add(QWidget *widget, QWidget *slider)
{
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(widget);
    vlayout->addWidget(slider);
    verticalLayoutVec.push_back(vlayout);

    if (verticalLayoutVec.size() == 1) {
        qInfo("grid 1");
        addLayout(verticalLayoutVec.at(0), 0, 0);
    }
    else if (verticalLayoutVec.size() == 2) {
        qInfo("grid 2");
        addLayout(verticalLayoutVec.at(1), 0, 1);
    }
    else if (verticalLayoutVec.size() == 3) {
        qInfo("grid 3");
        addLayout(verticalLayoutVec.at(2), 1, 0);
    }
    else if (verticalLayoutVec.size() == 4) {
        qInfo("grid 4");
        addLayout(verticalLayoutVec.at(3), 1, 1);
    }
}

void grid_layout::relayout()
{
    int widgets_count = count();
    qInfo("current grid layout count: %d", widgets_count);
    if (!widgets_count) {
        return;
    }

    int max_row_count =
            static_cast<int>(ceil(sqrt(static_cast<double>(widgets_count))));

    for (int i = 0; i < widgets_count; ++i) {
        addWidget(widgetVec.at(i), i / max_row_count, i % max_row_count);
    }
}

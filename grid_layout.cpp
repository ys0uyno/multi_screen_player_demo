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

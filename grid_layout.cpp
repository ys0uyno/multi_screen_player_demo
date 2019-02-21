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

    int grid_count = verticalLayoutVec.size();
    int max_row_count =
            static_cast<int>(ceil(sqrt(static_cast<double>(grid_count))));

    for (int i = 0; i < max_row_count; ++i) {
        addLayout(verticalLayoutVec.at(i),
                  i / max_row_count,
                  i % max_row_count
                  );
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

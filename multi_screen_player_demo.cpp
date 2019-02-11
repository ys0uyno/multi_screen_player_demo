#include "multi_screen_player_demo.h"
#include "ui_multi_screen_player_demo.h"

multi_screen_player_demo::multi_screen_player_demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multi_screen_player_demo)
{
    ui->setupUi(this);

    gridLayout = new grid_layout;
    setLayout(gridLayout);

    QAction *openAction = new QAction("&Open", this);
    openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction,
            &QAction::triggered,
            this,
            &multi_screen_player_demo::openFiles
            );
    addAction(openAction);

    QAction *relayoutAction = new QAction("&Relayout", this);
    relayoutAction->setShortcut(tr("Ctrl+R"));
    connect(relayoutAction,
            &QAction::triggered,
            gridLayout,
            &grid_layout::relayout
            );
    addAction(relayoutAction);

    QAction *quitAction = new QAction("E&xit", this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction,
            SIGNAL(triggered()),
            qApp,
            SLOT(quit())
            );
    addAction(quitAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);
}

multi_screen_player_demo::~multi_screen_player_demo()
{
    delete ui;
}

void multi_screen_player_demo::openFiles()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Files"));
    fileDialog.setFileMode(QFileDialog::ExistingFiles);

    QStringList supportedMimeTypes = QMediaPlayer::supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty())
        fileDialog.setMimeTypeFilters(supportedMimeTypes);

    fileDialog.setDirectory(
                QStandardPaths::standardLocations(
                    QStandardPaths::MoviesLocation).value(
                    0,
                    QDir::homePath()
                    )
                );
    if (fileDialog.exec() == QDialog::Accepted) {
        QList<QUrl> files = fileDialog.selectedUrls();
        for (int i = 0; i < files.length(); ++i) {
            media_player *video =
                    new media_player(this, QMediaPlayer::VideoSurface);
            video->setUrlAndPlay(fileDialog.selectedUrls().at(i));
            gridLayout->add(video->getVideoWidget());
            mediaPlayerVec.push_back(video);
        }
    }
}

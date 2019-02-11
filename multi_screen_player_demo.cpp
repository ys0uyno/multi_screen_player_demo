#include "multi_screen_player_demo.h"
#include "ui_multi_screen_player_demo.h"

multi_screen_player_demo::multi_screen_player_demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multi_screen_player_demo)
{
    ui->setupUi(this);

    QAction *openAction = new QAction("&Open", this);
    openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction,
            &QAction::triggered,
            this,
            &multi_screen_player_demo::openFiles
            );
    addAction(openAction);

    QAction *quitAction = new QAction("E&xit", this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction,
            SIGNAL(triggered()),
            qApp,
            SLOT(quit())
            );
    addAction(quitAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    mediaPlayer = new media_player(this, QMediaPlayer::VideoSurface);
    gridLayout = new QGridLayout;

    gridLayout->addWidget(mediaPlayer->getVideoWidget());
    setLayout(gridLayout);
}

multi_screen_player_demo::~multi_screen_player_demo()
{
    delete ui;
}

void multi_screen_player_demo::setUrl(const QUrl &url)
{
    setWindowFilePath(url.isLocalFile() ? url.toLocalFile() : QString());
    mediaPlayer->setMedia(url);
    mediaPlayer->play();
}

void multi_screen_player_demo::openFiles()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Files"));
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    QStringList supportedMimeTypes = mediaPlayer->supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty())
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    fileDialog.setDirectory(
                QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(
                    0,
                    QDir::homePath()
                    ));
    if (fileDialog.exec() == QDialog::Accepted) {
        setUrl(fileDialog.selectedUrls().constFirst());
    }
}

//
// Created by insane on 11.07.20.
//

#include "MusicPlayer.h"
#ifdef MUSICPLAYER_LOADABLE
#include "ui_musicplayer.h"
#endif

// todo lst_albums populate; select and only load selected albums
// todo qpushbutton animation
// todo icons instead of words > no i18n needed

MusicPlayer::MusicPlayer(Logger *log, QWidget *parent): QWidget(parent),
#ifdef MUSICPLAYER_LOADABLE
ui(new Ui::MusicPlayer),
#endif
log(log)
{
#ifdef MUSICPLAYER_LOADABLE
    ui->setupUi(this);
#endif
    playerLayout = new QGridLayout(this);
    libraryLayout = new QGridLayout(this);
    player = new Player(log, this);
    library = new Library(log, player);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px; width: 150px;}");
    playerLayout->addWidget(player);
    libraryLayout->addWidget(library);
    ui->tab_player->setLayout(playerLayout);
    ui->tab_library->setLayout(libraryLayout);
}

MusicPlayer::~MusicPlayer()
{
    delete library;
    delete libraryLayout;
    delete player;
    delete playerLayout;
    delete ui;
}

#ifdef MUSICPLAYER_LOADABLE
extern "C" MUSICPLAYER_EXPORT QWidget* create(Logger *log) {
    return new MusicPlayer(log);
}

extern "C" MUSICPLAYER_EXPORT char* getName() {
    return (char*) "MusicPlayer";
}

extern "C" MUSICPLAYER_EXPORT int getDefaultIndex(){
    return 1;
}

extern "C" MUSICPLAYER_EXPORT QStringList getSettingsKeys(){
    return QStringList() << KEY_SETTINGS_VOLUME << KEY_SETTINGS_DEFAULT_ALBUM << KEY_SETTINGS_DIRECTORY
                         << KEY_SETTINGS_MUTE << KEY_SETTINGS_PLAY_ALBUM_ON_START << KEY_SETTINGS_SHUFFLE;
}

extern "C" MUSICPLAYER_EXPORT QStringList getDependencies(){
    return QStringList() << "Logger";
}
#endif
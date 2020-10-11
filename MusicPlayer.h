//
// Created by insane on 11.07.20.
//

#ifndef CARPI_QT_MUSICPLAYER_H
#define CARPI_QT_MUSICPLAYER_H

#ifdef MUSICPLAYER_LOADABLE
#include "MusicPlayer_global.h"
#endif

#include "Player/Player.h"
#include "Library/Library.h"
#include "Logger/Logger.h"

#include <QString>
#include <QWidget>
#include <QGridLayout>

#ifdef MUSICPLAYER_LOADABLE
QT_BEGIN_NAMESPACE
namespace Ui { class MusicPlayer; }
QT_END_NAMESPACE
#endif

class MusicPlayer : public QWidget
{
Q_OBJECT
private:
#ifdef MUSICPLAYER_LOADABLE
    Ui::MusicPlayer *ui;
#endif
    QGridLayout *playerLayout;
    QGridLayout *libraryLayout;

    Player *player;
    Library *library;
    QSettings *settings;
    Logger *log;

public:
    explicit MusicPlayer(Logger *log, QWidget *parent = nullptr);
    ~MusicPlayer() override;
};

#ifdef MUSICPLAYER_LOADABLE
extern "C" {
    MUSICPLAYER_EXPORT int getDefaultIndex();
    MUSICPLAYER_EXPORT char* getName();
    MUSICPLAYER_EXPORT QWidget* create(Logger *log);
    MUSICPLAYER_EXPORT QStringList getSettingsKeys();
    MUSICPLAYER_EXPORT QStringList getDependencies();
    MUSICPLAYER_EXPORT int getVersion();
};
#endif


#endif //CARPI_QT_MUSICPLAYER_H

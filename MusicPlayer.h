//
// Created by insane on 11.07.20.
//

#ifndef CARPI_QT_MUSICPLAYER_H
#define CARPI_QT_MUSICPLAYER_H

#include "MusicPlayer_global.h"

#include "Player/Player.h"
#include "Library/Library.h"
#include "Logger/Logger.h"

#include <QString>
#include <QWidget>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MusicPlayer; }
QT_END_NAMESPACE

class MusicPlayer : public QWidget
{
Q_OBJECT
private:
    Ui::MusicPlayer *ui;
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

extern "C" {
    MUSICPLAYER_EXPORT int getDefaultIndex();
    MUSICPLAYER_EXPORT char* getName();
    MUSICPLAYER_EXPORT QWidget* create(Logger *log);
    MUSICPLAYER_EXPORT QStringList getSettingsKeys();
    MUSICPLAYER_EXPORT QStringList getDependencies();
    MUSICPLAYER_EXPORT int getVersion();
};


#endif //CARPI_QT_MUSICPLAYER_H

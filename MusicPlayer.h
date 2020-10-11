//
// Created by insane on 11.07.20.
//

#ifndef CARPI_QT_MUSICPLAYER_H
#define CARPI_QT_MUSICPLAYER_H

#include "MusicPlayer_global.h"

#include "Player/Player.h"
#include "Library/Library.h"

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

public:
    explicit MusicPlayer(QSettings *settings, QWidget *parent = nullptr);
    ~MusicPlayer() override;
};

extern "C" {
    MUSICPLAYER_EXPORT int getDefaultIndex();
    MUSICPLAYER_EXPORT char* getName();
    MUSICPLAYER_EXPORT QWidget* create(QSettings *settings);
    MUSICPLAYER_EXPORT QStringList getSettingsKeys();
};


#endif //CARPI_QT_MUSICPLAYER_H

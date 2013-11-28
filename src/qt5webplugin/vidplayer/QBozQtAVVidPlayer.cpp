#include "QBozQtAVVidPlayer.h"
#include <QtAV/WidgetRenderer.h>
#include <QtAV/AVPlayer.h>

namespace BOZ {
    
QBozQtAVVidPlayer::QBozQtAVVidPlayer(QObject *parent) : 
    QBozAbstractVidPlayer(parent), 
    _play(0), _rec(0),
    _player(Q_NULLPTR), _renderer(Q_NULLPTR) {
    qDebug("%s", __PRETTY_FUNCTION__);
    memset(_filts, 0, nb_filters*sizeof(bool));
    
}

QBozQtAVVidPlayer::~QBozQtAVVidPlayer() {
    qDebug("%s", __PRETTY_FUNCTION__);

    
}

// void QBozQtAVVidPlayer::setURI(QString &uri) {
//     qDebug("%s", __PRETTY_FUNCTION__);
//     _uri = uri;
// }

QWidget* QBozQtAVVidPlayer::getWidget() {
    qDebug("%s", __PRETTY_FUNCTION__);
    _player = new QtAV::AVPlayer(this);
    _renderer = new QtAV::WidgetRenderer();
    if(_player) {
        connect(_player, SIGNAL(started()), this, SLOT(onPlay()));
        connect(_player, SIGNAL(paused(bool)), this, SLOT(onPause(bool)));
        connect(_player, SIGNAL(stopped()), this, SLOT(onStop()));
//        connect(_player, SIGNAL(recording(bool)), this, SLOT(onRecord(bool)));
        _player->setRenderer(_renderer);
    }
    return _renderer;
}

void QBozQtAVVidPlayer::play() {
    qDebug("%s", __PRETTY_FUNCTION__);
    if(_player) {
        _play=0;
        _player->play(_uri);
    }
}

void QBozQtAVVidPlayer::onPlay() {
    qDebug("%s", __PRETTY_FUNCTION__);
    _play=1;
    Q_EMIT started();
}

void QBozQtAVVidPlayer::pause() {
    qDebug("%s", __PRETTY_FUNCTION__);
    if(_player) {
        _player->pause(_play);
    }
}

void QBozQtAVVidPlayer::onPause(bool b) {
    qDebug("%s", __PRETTY_FUNCTION__);
    _play=0;
    Q_EMIT paused(b);
}

void QBozQtAVVidPlayer::onStop() {
    qDebug("%s", __PRETTY_FUNCTION__);
    _play=0;
    Q_EMIT stopped();
}

void QBozQtAVVidPlayer::capture() {
    qDebug("%s", __PRETTY_FUNCTION__);
}

void QBozQtAVVidPlayer::record() {
    qDebug("%s, state(%d)", __PRETTY_FUNCTION__, _rec);
    onRecord(!_rec);
}

void QBozQtAVVidPlayer::onRecord(bool b) {
    qDebug("%s, state(%d)", __PRETTY_FUNCTION__, b);
    _rec=b%2;
    Q_EMIT recording(_rec);
}

#define GENERATE_FILTER(x) \
void QBozQtAVVidPlayer::toggleFilter##x() {  \
    qint8 idx=x-1;  \
    _filts[idx]=!_filts[idx];  \
    qDebug("%s, filter%d, new value(%d)", __PRETTY_FUNCTION__, x, _filts[idx]);  \
    Q_EMIT onFilter##x(_filts[idx]);  \
}

GENERATE_FILTER(1)
GENERATE_FILTER(2)
GENERATE_FILTER(3)
GENERATE_FILTER(4)

} // NAMESPACE

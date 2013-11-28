#include "QBozQtAVVidPlayer.h"
#include <QtAV/WidgetRenderer.h>
#include <QtAV/AVPlayer.h>

namespace BOZ {
    
QBozQtAVVidPlayer::QBozQtAVVidPlayer(QObject *parent) : 
    QBozAbstractVidPlayer(parent), 
    _player(Q_NULLPTR), _renderer(Q_NULLPTR) {
    qDebug("%s", __PRETTY_FUNCTION__);
    
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
    if(_player)
        _player->play(_uri);
}

void QBozQtAVVidPlayer::onPlay() {
    qDebug("%s", __PRETTY_FUNCTION__);
    Q_EMIT started();
}

void QBozQtAVVidPlayer::pause() {
    qDebug("%s", __PRETTY_FUNCTION__);
    if(_player)
        _player->togglePause();
}

void QBozQtAVVidPlayer::onPause(bool b) {
    qDebug("%s", __PRETTY_FUNCTION__);
    Q_EMIT paused(b);
}

void QBozQtAVVidPlayer::onStop() {
    qDebug("%s", __PRETTY_FUNCTION__);
    Q_EMIT stopped();
}

void QBozQtAVVidPlayer::capture() {
    qDebug("%s", __PRETTY_FUNCTION__);
}

void QBozQtAVVidPlayer::record() {
    qDebug("%s", __PRETTY_FUNCTION__);
}

void QBozQtAVVidPlayer::onRecord(bool b) {
    qDebug("%s", __PRETTY_FUNCTION__);
    Q_EMIT recording(b);
}

void QBozQtAVVidPlayer::seek(qint64 time) {
    qDebug("%s, time(%lld)", __PRETTY_FUNCTION__, time);
}

void QBozQtAVVidPlayer::applyfilter(qint8 type, bool b) {
    qDebug("%s, type(%d), value(%d)", __PRETTY_FUNCTION__, type, b);
}

} // NAMESPACE

#include "QBozQtAVVidPlayer.h"

namespace BOZ {
    
QBozQtAVVidPlayer::QBozQtAVVidPlayer(QObject *parent) : 
    QBozAbstractVidPlayer(parent) {
    qDebug("%s", __FUNCTION__);
    
}

QBozQtAVVidPlayer::~QBozQtAVVidPlayer() {
    qDebug("%s", __FUNCTION__);

    
}

// void QBozQtAVVidPlayer::setURI(QString &uri) {
//     qDebug("%s", __FUNCTION__);
//     _uri = uri;
// }

QWidget* QBozQtAVVidPlayer::getWidget() {
    qDebug("%s", __FUNCTION__);
    QWidget *pw = new QWidget();
    pw->setStyleSheet("background-color: black;");
    return pw;
}

void QBozQtAVVidPlayer::play() {
    qDebug("%s", __FUNCTION__);
}

void QBozQtAVVidPlayer::pause() {
    qDebug("%s", __FUNCTION__);
}

void QBozQtAVVidPlayer::capture() {
    qDebug("%s", __FUNCTION__);
}

void QBozQtAVVidPlayer::record() {
    qDebug("%s", __FUNCTION__);
}

void QBozQtAVVidPlayer::seek(qint64 time) {
    qDebug("%s, time(%lld)", __FUNCTION__, time);
}

void QBozQtAVVidPlayer::applyfilter(qint8 type, bool b) {
    qDebug("%s, type(%d), value(%d)", __FUNCTION__, type, b);
}

} // NAMESPACE

#include "QBozAbstractVidPlayer.h"

namespace BOZ {
    
QBozAbstractVidPlayer::QBozAbstractVidPlayer(QObject *parent) : 
    QObject(parent), _uri() {
    qDebug("%s", __PRETTY_FUNCTION__);
    
}

QBozAbstractVidPlayer::~QBozAbstractVidPlayer() {
    qDebug("%s", __PRETTY_FUNCTION__);
}

void QBozAbstractVidPlayer::setURI(QString &uri) {
    qDebug("%s", __PRETTY_FUNCTION__);
    _uri = uri;
}

QWidget* QBozAbstractVidPlayer::getWidget() {
    qDebug("%s", __PRETTY_FUNCTION__);
    return NULL;;
}

} // NAMESPACE

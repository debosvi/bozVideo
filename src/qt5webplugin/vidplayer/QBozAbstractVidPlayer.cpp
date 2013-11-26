#include "QBozAbstractVidPlayer.h"

namespace BOZ {
    
QBozAbstractVidPlayer::QBozAbstractVidPlayer(QObject *parent) : 
    QObject(parent), _uri() {
    qDebug("%s", __FUNCTION__);
    
}

QBozAbstractVidPlayer::~QBozAbstractVidPlayer() {
    qDebug("%s", __FUNCTION__);
}

void QBozAbstractVidPlayer::setURI(QString &uri) {
    qDebug("%s", __FUNCTION__);
    _uri = uri;
}

QWidget* QBozAbstractVidPlayer::getWidget() {
    qDebug("%s", __FUNCTION__);
    return NULL;;
}

} // NAMESPACE

#ifndef _QBOZQTAVVIDPLAYER_H_
#define _QBOZQTAVVIDPLAYER_H_

#include "QBozAbstractVidPlayer.h"

namespace BOZ {

class QBozQtAVVidPlayer : public QBozAbstractVidPlayer {
    Q_OBJECT
    
public:
    QBozQtAVVidPlayer(QObject *parent=0);
    virtual ~QBozQtAVVidPlayer();
    QWidget* getWidget();

public Q_SLOTS:
    void play();
    void pause();
    void seek(qint64 time);
    void capture();
    void record();
    void applyfilter(qint8 type, bool b);
    
protected:
    
};

} // NAMESPACE

#endif // _QBOZQTAVVIDPLAYER_H_

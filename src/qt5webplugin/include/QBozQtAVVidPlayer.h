
#ifndef _QBOZQTAVVIDPLAYER_H_
#define _QBOZQTAVVIDPLAYER_H_

#include "QBozAbstractVidPlayer.h"

namespace QtAV {
    class AVPlayer;
    class WidgetRenderer;
}

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
    void capture();
    void record();
    void toggleFilter1();
    void toggleFilter2();
    void toggleFilter3();
    void toggleFilter4();

private Q_SLOTS:
    void onPlay();
    void onPause(bool b);
    void onStop();
    void onRecord(bool b);
    
private:
    bool _play, _rec;
    bool _filts[4];
    QtAV::AVPlayer* _player;
    QtAV::WidgetRenderer* _renderer; 
    const static qint8 nb_filters =4;
};

} // NAMESPACE

#endif // _QBOZQTAVVIDPLAYER_H_

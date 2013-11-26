
#ifndef _QBOZABSTRACTVIDPLAYER_H_
#define _QBOZABSTRACTVIDPLAYER_H_

#include <QWidget>

namespace BOZ {
    
class QBozAbstractVidPlayer : public QObject {
    Q_OBJECT

public:
    explicit QBozAbstractVidPlayer(QObject *parent=0);
    ~QBozAbstractVidPlayer();
    QWidget* getWidget();
    
public Q_SLOTS:
    void setURI(QString &uri);
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void seek(qint64 time) = 0;
    virtual void capture() = 0;
    virtual void record() = 0;
    virtual void applyfilter(qint8 type, bool b) = 0;

Q_SIGNALS:
    void started();
    void stopped();
    void paused(bool b);
    void recording(bool b);
    void onFilter(qint8 type, bool b);

protected:
    QString _uri;
};

} // NAMEPSACE

#endif // _QBOZABSTRACTVIDPLAYER_H_

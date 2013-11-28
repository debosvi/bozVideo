
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
    virtual void capture() = 0;
    virtual void record() = 0;
    virtual void toggleFilter1() = 0;
    virtual void toggleFilter2() = 0;
    virtual void toggleFilter3() = 0;
    virtual void toggleFilter4() = 0;

Q_SIGNALS:
    void started();
    void stopped();
    void paused(bool b);
    void recording(bool b);
    void onFilter1(bool b);
    void onFilter2(bool b);
    void onFilter3(bool b);
    void onFilter4(bool b);

protected:
    QString _uri;
};

} // NAMEPSACE

#endif // _QBOZABSTRACTVIDPLAYER_H_

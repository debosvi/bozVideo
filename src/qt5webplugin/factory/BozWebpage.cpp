/*
** Copyright (C) 2013 Renault-Trucks Defense.
*/

/**
 * \file BozWebpage.cpp
 * \author Vincent de RIBOU <vincent.de-ribou@external.renault-trucks.com>
 * \brief TBD
 * \version 1.0
 */

/**
 * @ingroup HMI
 * @defgroup QT_WEBPLUGIN
 * @{
 * \brief BOZ Webpage plugin factory
 */
 
#include <QWebFrame>
#include <QVBoxLayout>
#include <QPushButton>

#include "BozWebpage.h"
#include "QBozQtAVVidPlayer.h"

BozWebpage::BozWebpage(QUrl &url) : _view(0) {
    _view = new QWebView();
    _view->setPage(this);
    _view->page()->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    _view->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    _view->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    
    _view->load(url);
    //! allows to change window title on content title change
    connect(_view, SIGNAL(titleChanged(QString)), SLOT(adjustTitle(QString)));  
    
    _view->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    _view->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);

    _view->resize(1024,768);
    _view->show();
}

QObject* BozWebpage::createPlugin(const QString & classid, const QUrl & url, const QStringList & paramNames, const QStringList & paramValues) {
    int idx=paramNames.indexOf(QString("id"));
    QString idstr = paramValues[idx];

    Q_UNUSED(url)

    qDebug("create class %s", classid.toLatin1().data());

#if 0
    if(classid == "vplayer_test") {
        QWidget *w=new QWidget;
        w->setStyleSheet("background-color: red;");
        w->setLayout(new QVBoxLayout());
        w->layout()->addWidget(new QPushButton(idstr));
        _view->page()->mainFrame()->addToJavaScriptWindowObject(idstr, w);
        return w;
    }
#endif

    if(classid == "rtd_vplayer") {
        qDebug("URL to play: %s", url.url().toLatin1().data());
        BOZ::QBozQtAVVidPlayer *pw=new BOZ::QBozQtAVVidPlayer;
        QString uri=url.url();
        pw->setURI(uri);
        //! allows to access from javascript to HTML id set
        _view->page()->mainFrame()->addToJavaScriptWindowObject(idstr, pw);
        QWidget *wid = pw->getWidget();

        qDebug("player widget(%p)", wid);
        return wid;
    }
    
    return NULL;
}

void BozWebpage::adjustTitle(QString title )
{
    qDebug("%s", __FUNCTION__);
    _view->setWindowTitle(_view->title() + " : " + title);
}

/**
 * @}
 * End of group
 */

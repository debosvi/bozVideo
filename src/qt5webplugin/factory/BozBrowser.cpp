/*
** Copyright (C) 2013 Renault-Trucks Defense.
*/

/**
 * \file BozBrowser.cpp
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
 
#include "BozBrowser.h"

BozBrowser::BozBrowser(QObject *parent) :
    QObject(parent) {

}

QWebView* BozBrowser::addView(QUrl &url) {
    BozWebpage* lpage = new BozWebpage(url);
    if(!lpage) {
        qDebug("%s, unable to creaite new webpage", __FUNCTION__);
        return NULL;
    }

    qDebug("%s, page (%p)", __FUNCTION__, lpage);
    connect(lpage, SIGNAL(windowCloseRequested()), this, SLOT(onViewClose()));
    _pages << lpage;
    return lpage->view();
}

void BozBrowser::onViewClose() {
    BozWebpage* s = (BozWebpage*)sender();
    qDebug("%s, sender (%p)", __FUNCTION__, s);
}

/**
 * @}
 * End of group
 */

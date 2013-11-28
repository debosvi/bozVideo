/*
** Copyright (C) 2013 Renault-Trucks Defense.
*/

/**
 * \file BozBrowser.h
 * \author Vincent de RIBOU <belzo2005-dolphin@yahoo.fr>
 * \brief TBD
 * \version 1.0
 */

/**
 * @ingroup HMI
 * @defgroup QT_WEBPLUGIN
 * @{
 * \brief BOZ Browser plugin factory
 */
 
#ifndef _QBOZWEBBROWSER_H_
#define _QBOZWEBBROWSER_H_

#include "BozWebpage.h"
class QWebView;

/*!
 * \class BozBrowser 
 * \brief Class allowing to view html content and also bridge native Qt class to javascript
 */
class BozBrowser : public QObject {
    Q_OBJECT
    
public:
    /*!
     *  \brief Constructor
     *  \param url : URI to load
     */
     BozBrowser(QObject* parent=0);

    /*!
     *  \brief Add a new view
     *  \param url : URI to load
     */
     QWebView* addView(QUrl &url);

private Q_SLOTS:
     void onViewClose();

private:
    /*!
     *  \brief Specific viewer
     */
    QList<BozWebpage*> _pages;
};

#endif //  _QBOZWEBBROWSER_H_

/**
 * @}
 * End of group
 */

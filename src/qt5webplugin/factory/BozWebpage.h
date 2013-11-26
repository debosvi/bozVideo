/*
** Copyright (C) 2013 Renault-Trucks Defense.
*/

/**
 * \file BozWebpage.h
 * \author Vincent de RIBOU <belzo2005-dolphin@yahoo.fr>
 * \brief TBD
 * \version 1.0
 */

/**
 * @ingroup HMI
 * @defgroup QT_WEBPLUGIN
 * @{
 * \brief BOZ Webpage plugin factory
 */
 
#include <QWebPage>
#include <QWebView>

/*!
 * \class BozWebpage 
 * \brief Class allowing to view html content and also bridge native Qt class to javascript
 */
class BozWebpage : public QWebPage {
    Q_OBJECT
    
public:
    /*!
     *  \brief Constructor
     *  \param url : URI to load
     */
     BozWebpage(QUrl &url);

protected slots:
    /*!
     *  \brief Set specific title to view window
     *  \param title : title to set
     */
    void adjustTitle(QString title);
    
protected:
    /*!
     *  \brief Allows plugin bridge from Qt to/from Javscript
     *  \param classid : class identifier set by HTML object tag
     *  \param url : ??
     *  \param paramNames : HTML object tag parameters names list
     *  \param paramValues : HTML object tag parameters values list
     */
    QObject* createPlugin(const QString& classid, const QUrl& url, const QStringList& paramNames, const QStringList& paramValues);
    
private:
    /*!
     *  \brief Specific viewer
     */
    QWebView *_view;
};

/**
 * @}
 * End of group
 */

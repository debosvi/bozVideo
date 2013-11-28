#include <QApplication>

#include "BozBrowser.h"

int main(int ac, char **av) {
    QApplication a(ac, av);
    QUrl url;
    QUrl other = QUrl("http://localhost:8080/video1.html");

    if (ac > 1)
        url = QUrl::fromUserInput(av[1]);
    else
        url = QUrl("http://localhost:8080/empty.html");
    
    BozBrowser mb(&a);

    mb.addView(url);
    mb.addView(other);
    
    return a.exec();
}

#ifndef NAVBAR_H
#define NAVBAR_H
#include <QToolBar>
#include <QToolButton>

#include "CentralWidget.h"
class Achille;
class NavBar : public QToolBar {
    Q_OBJECT
public:
    NavBar();
    ~NavBar();
    void setBrowserWidget(Achille *b);
private:
    Achille *bWidget;
    QToolButton *goBack, *goUp, *refresh, *home;
private slots:
    void onGoUpClicked();
    void onGoBackClicked();
    void onRefreshClicked();
    void onHomeClicked();
    void onDirChanged(QString path);
    void onHistoryChanged();
};
#endif // NAVBAR_H

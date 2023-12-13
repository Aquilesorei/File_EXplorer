#ifndef MULTID_H
#define MULTID_H
#include <QDialog>
#include <QVariant>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QLabel>
#include <QWidget>

#include "../../components/CentralWidget.h"

class MultiD : public QDialog
{
public :
    explicit MultiD(CentralWidget *parent = nullptr);
    QVBoxLayout *layout;

private:
    int size=0;


};
#endif // MULTID_H

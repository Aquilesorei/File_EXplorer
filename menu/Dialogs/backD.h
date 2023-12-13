#ifndef BACKD_H
#define BACKD_H

#include <QDialog>
#include <QVariant>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QLabel>
#include <QProcess>
#include <QWidget>

#include "../../Achille.h"

class backD : public QDialog
{
    Q_OBJECT

public :


    explicit backD(Achille *parent = nullptr);
    QVBoxLayout *layout;
    QVariant store(unsigned long int value);
    qlonglong analysa();
    QProcess *process;
    void comm();
    QLabel *labelT1;
};

#endif // BACKD_H

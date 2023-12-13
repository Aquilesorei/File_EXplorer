#ifndef FOLDERD_H
#define FOLDERD_H
#include <QDialog>
#include <QVariant>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QLabel>
#include <QWidget>

#include "../../components/CentralWidget.h"

class FolderD : public QDialog
{
public :
    explicit FolderD(CentralWidget *parent = nullptr);
    QVBoxLayout *layout;
    QVariant store(unsigned long int value);



};

#endif // FOLDERD_H

#ifndef FOLDERD_H
#define FOLDERD_H
#include <QDialog>
#include <QVariant>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QLabel>
#include <QWidget>

#include "../../Achille.h"

class FolderD : public QDialog
{
public :
    explicit FolderD(Achille *parent = nullptr);
    QVBoxLayout *layout;
    QVariant store(unsigned long int value);



};

#endif // FOLDERD_H

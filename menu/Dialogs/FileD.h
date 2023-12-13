#ifndef FILED_H
#define FILED_H
#include <QDialog>
#include <QVariant>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QLabel>
#include <QWidget>
#include "../../components/CentralWidget.h"

class FileD : public QDialog
{
public :
    explicit FileD(CentralWidget *parent = nullptr);
    QVBoxLayout *layout;
    QWidget *widget;


};
#endif // FILED_H

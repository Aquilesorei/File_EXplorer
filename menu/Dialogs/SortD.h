#ifndef SORTD_H
#define SORTD_H
#include <QDialog>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QWidget>
#include <QtAlgorithms>

#include "../../components/CentralWidget.h"

class SortD : public QDialog
{
public :
    explicit SortD(CentralWidget *parent = nullptr);
    QVBoxLayout *layout;

private:


};
#endif // SORTD_H

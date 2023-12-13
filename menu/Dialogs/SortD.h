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

#include "../../Achille.h"

class SortD : public QDialog
{
public :
    explicit SortD(Achille *parent = nullptr);
    QVBoxLayout *layout;

private:


};
#endif // SORTD_H

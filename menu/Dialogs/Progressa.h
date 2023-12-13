#ifndef PROGRESSA_H
#define PROGRESSA_H
#include <QDialog>
#include <QVariant>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QLabel>
#include <QProgressBar>
#include <QWidget>
class Progressa : public QDialog
{
    Q_OBJECT
public :
    explicit Progressa(QWidget *parent= nullptr);
    QLabel *labelFromto,*labelAvance;
    QProgressBar *CurrentFileProgress,*AllFilesProgress;
};
#endif // PROGRESSA_H

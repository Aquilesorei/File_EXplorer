#ifndef ARCHIVA_H
#define ARCHIVA_H
#include <QWidget>
#include "../libs/quazip/quazip.h"
#include "../libs/quazip/quazipfileinfo.h"
class Archiva: public QWidget
{
    Q_OBJECT
public :
    Archiva();
    static bool archive(const QString & filePath, const QStringList & list, const QString & comment = QString(""));
    static void recurseAddDir(const QDir& d, QStringList & list);
};
#endif // ARCHIVA_H

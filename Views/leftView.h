#ifndef LEFTVIEW_H
#define LEFTVIEW_H
#include <QtWidgets>
#include <QSplitter>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStandardPaths>
class leftView: public QWidget
{
    Q_OBJECT
public :
    explicit leftView(QWidget *parent= 0);
    ~leftView();
   QItemSelectionModel *selection;

    //void mousePressEvent(QMouseEvent *event);
    //void keyPressEvent(QKeyEvent *event);
private slots :
     void ecrire();
signals:
//    void search(const QString& str);
    void on_folder_clicked();

private:
    QPushButton *home, *docs, *pics, *downloads,*Favourite,*compressed,*Recycle,
            *music, *videos, *templates, *trash,*Desktop,*Apps,*NewFile,*Cloud,*Acess,*Encrypted;


    void *_home();
    void *_docs();
    void *_pics();
    void *_downloads();
    void *_Favourite();
    void *_compressed();
    void *_Recycle();
    void *_music();
    void *_videos();
    void *_templates();
    void *_Desktop();
    void *_Apps();
    void *_NewFile();
    void *_Cloud();
    void *_Acess();
    void *_Encrypted();

};
#endif // LEFTVIEW_H

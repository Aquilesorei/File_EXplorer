#ifndef ACHILLE_H
#define ACHILLE_H

#include<QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QFileSystemModel>
#include <QTabWidget>
#include <QWidget>
#include <QFileSystemModel>
#include <QListView>
#include <QTableView>
#include <QObject>
#include <QWidget>
#include<QFileSystemWatcher>
#include <QItemSelectionModel>
#include <QItemSelection>
#include <QModelIndex>
#include <QSplitter>
#include <QFileIconProvider>
#include <QList>
#include <QVBoxLayout>
#include <QVariant>
#include <QMessageBox>
#include <QPushButton>
#include <QDesktopServices>
#include <QModelIndexList>

#include "Views/DirView.h"


#include <QListWidget>
#include <QSize>
#include <QString>
#include <QStringList>
#include <QListWidgetItem>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QFlags>
#include "searchbar.h"
class DirView;
class SearchBar;
class FileSystemWatcher;
class Achille : public QWidget
{
    Q_OBJECT
    friend class DirView;
    friend class SearchBar;
public :
    explicit Achille();

    ~Achille();

    /*friend void DisplayPict();
    friend bool containsPict();
    friend QStringList picture();
    bool loadOnlyPictures= false;*/
    DirView *view;
    QVBoxLayout *layout;
    QString currentPath;
    QString iPath;
    QItemSelectionModel *selectionmodel{};
    QModelIndex indexElementSelectionne;
     bool selected{};
     mutable int nbSelectedFiles{};
     int nbfiles{};
     void setIconView() const;
         void setListView();
         void loadDir(const QString& path, bool recordHistory, bool firstLoad);
         void loadDir(const QString& path, bool recordHistory);
         void loadDir(const QString& path);
         void loadDir();
         QStringList history();
         void reload();
         QString fsCurrentPath() const;
         QString currentDirName() const;
         void startRefresh();
         void stopRefresh();
         QString currentItemName();
         QStringList currentItemNames();
         void selectAll();
         QList<QString> list_video;
         QList<QString> list_audio;
         QList<QString> list_image;
         QList<QString> list_document;
         QList<QString> list_archive;
         QList<QString> list_window_executable;
         QList<QString> list_Android_executable;
         QList<QString> list_linux_executable;
         QList<QString> list_word;
         QList<QString> list_exel;
         QList<QString> list_powerpoint;
         QVector<QListWidgetItem *> AllItems;
          static bool veriff(const QList<QString>& liste,const QString& item);
          QStringList searchPatterns;
          SearchBar *searcha;
          bool AllSelected= false;





protected:
         // bool eventFilter(QObject *obj,QEvent *event);

public slots:

   //void item_double_clicked(const QModelIndex &index);
  // void folder_double_clicked();
   void onItemDoubleClicked(QListWidgetItem *item);
   void onItemClicked(QListWidgetItem *item);
private slots:
    void onEnterPressed();
    void onCloseClicked();





signals:
   void selectAllstatus(bool val);
   void SelectChange(int nb);
   void rename_bouton_clicked();
   void dirChanged(QString path);
   void historyChanged();
   void selectionState(bool anySelected);
private:
   QTabWidget *onglets{};
       //QListWidget *listWidget;
       QSize defaultGridSize;

       QStringList historyList;
       FileSystemWatcher *thread{};
       QString currentItemTxt;

};
class FileSystemWatcher : public QTimer {
    Q_OBJECT
public:
    FileSystemWatcher(Achille *widget);
private:
    Achille *bWidget;
private slots:
    void onRefresh();
};

#endif // ACHILLE_H

#ifndef WELCOME_H
#define WELCOME_H
#include<QtWidgets>
#include <QMouseEvent>
#include<QPushButton>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QList>
#include<QListView>
#include<QTableView>
#include <QVariant>
#include <QMenuBar>
#include <QScrollBar>

class Welcome : public QWidget
{

   Q_OBJECT
public:
    explicit Welcome(QWidget *parent = nullptr);
    QGridLayout *layout;
    QLineEdit *line{};
    QLabel *label{};

    //les boutons
    QPushButton *BoutonMAinStorage;
    QPushButton *Downloads;
    QPushButton *Download;
    QPushButton *images;
    QPushButton *Audio;
    QPushButton *Videos;
    QPushButton *Documents;
    QPushButton *Apps;
    QPushButton *NewFiles;
    QPushButton *NewFile;
    QPushButton *Cloud;
    QPushButton *Access;
    QPushButton *Compressed;
    QPushButton *Encrypted;
    QPushButton *Recycle;
    QPushButton *Recycles;
    QPushButton *Favourite;
    QPushButton *home;
    QPushButton *Secret;
    QPushButton *Desktop;

    // leurs sous menus de menuFichier
    QAction *ActionNouveau{};
    QAction *ActionOuvrir{};
    QAction *Actionview{};
    QAction *ActionSort{};
    QAction *ActionShare{};
    QAction *ActionDelete{};
    QAction *ActionFermer{};
    QAction *ActionRename{};
    QAction *ActionCopy{};
    QAction *ActionPaste{};
    QAction *ActionCut{};
    QAction *ActionFind{};
    QAction *ActionAnalyse{};
    QAction *ActionRefresh{};
    //les sous menu du menu window
    QAction *ActionClose{};
    QAction *ActionCompress{};
    QAction *ActionSetting{};
    QVBoxLayout *tayout{};
    QAction *ActionSecret{};
    QScrollArea *area{};



public slots:
   //void on_listView_clicked();
   //void home_buuton_pressed();



protected :


};


#endif // WELCOME_H

#ifndef OPENWITH_H
#define OPENWITH_H
#include <QDialog>
#include <QString>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QDir>
class openWith : public QDialog {
    Q_OBJECT
public:
    explicit openWith(QString currentFile);
    QString clair="/usr/share/applications";


    ~openWith();
private:
    QString currentFilePath;
    QVBoxLayout *layout;
    QTreeWidget *treeView;
    QDialogButtonBox *dialogButtons;
    QTreeWidgetItem *suggestedApps;
    QTreeWidgetItem *allApps;
    void loadAll(bool suggested);
    QStringList fileContent(QString file);
    QString secondHalf(QString line);
    void launchApp(QString exe);
    //void Analysa();
    QStringList files;

private slots:
    void onItemDoubleClicked(QTreeWidgetItem *item);
    void onCancelClicked();
    void onOkClicked();
};
#endif // OPENWITH_H

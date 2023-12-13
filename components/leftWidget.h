#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include "../Views/leftView.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTimer>
#include "../Views/leftView.h"
class DeviceList;
class leftView;
class leftWidget:public QDockWidget
{
    Q_OBJECT
public :
    explicit leftWidget();
    ~leftWidget() override;

private :
  QWidget *mainWidget;
  leftView *left;
  QVBoxLayout *layout;
  DeviceList *deviceslist;
};
class DeviceList : public QTreeWidget {
    Q_OBJECT
public:
    DeviceList();
    ~DeviceList();
    QList<QStorageInfo> usb;
signals :
    void usbr(QList<QStorageInfo> us);
private:
    QTimer *timer;
private slots:
    void loadDrives();
    void onItemClicked(QTreeWidgetItem *item);
};
#endif // LEFTWIDGET_H

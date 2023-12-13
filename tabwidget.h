#ifndef TABWIDGET_H
#define TABWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QVector>
#include <cstdio>
#include "Achille.h"
// libdisks
/*#ifndef NO_UDISKS

#endif*/
class Achille;
class tabWidget : public QWidget {
    Q_OBJECT
public:
    explicit tabWidget(QWidget *parent = nullptr);
    ~tabWidget() override;
    static QTabWidget *tabs;
    static void addNewTab(const QString& path);
    static void addNewTab();

    [[maybe_unused]] static void closeCurrentTab();
    static Achille *currentWidget();
    static void updateTabName();
    static QVector<Achille *> allWidgets();
    // libdisks
/*#ifndef NO_UDISKS
    void populateMedia();
    void handleMediaMountpointChanged(QString path, QString mountpoint);
    int mediaBookmarkExists(QString path);
    void handleMediaAdded(QString path);
    void handleMediaRemoved(QString path);
    void handleMediaChanged(QString path, bool present);
    void handleMediaUnmount();
    void handleMediaEject();
    void handleMediaError(QString path, QString error);
#endif
#ifndef NO_UDISKS
    QAction *mediaUnmountAct;
    QAction *mediaEjectAct;
#endif
    // libdisks
#ifndef NO_UDISKS
    Disks *disks;
#endif*/
private:
    //static NavBar *navigationBar;

    QVBoxLayout *layout;


private slots:
    void onTabsChanged();
    static void onTabClosed(int index);

};
//create a struct to detect usb masse storage
/*static struct udev_device*
get_child(struct udev* udev, struct udev_device* parent, const char* subsystem)
{
    struct udev_device* child = NULL;
    struct udev_enumerate *enumerate = udev_enumerate_new(udev);

    udev_enumerate_add_match_parent(enumerate, parent);
    udev_enumerate_add_match_subsystem(enumerate, subsystem);
    udev_enumerate_scan_devices(enumerate);

    struct udev_list_entry *devices = udev_enumerate_get_list_entry(enumerate);
    struct udev_list_entry *entry;

    udev_list_entry_foreach(entry, devices) {
        const char *path = udev_list_entry_get_name(entry);
        child = udev_device_new_from_syspath(udev, path);
        break;
    }

    udev_enumerate_unref(enumerate);
    return child;
}
static void enumerate_usb_mass_storage(struct udev* udev)
{
    struct udev_enumerate* enumerate = udev_enumerate_new(udev);

    udev_enumerate_add_match_subsystem(enumerate, "scsi");
    udev_enumerate_add_match_property(enumerate, "DEVTYPE", "scsi_device");
    udev_enumerate_scan_devices(enumerate);

    struct udev_list_entry *devices = udev_enumerate_get_list_entry(enumerate);
    struct udev_list_entry *entry;

    udev_list_entry_foreach(entry, devices) {
        const char* path = udev_list_entry_get_name(entry);
        struct udev_device* scsi = udev_device_new_from_syspath(udev, path);

        struct udev_device* block = get_child(udev, scsi, "block");
        struct udev_device* scsi_disk = get_child(udev, scsi, "scsi_disk");

        struct udev_device* usb
            = udev_device_get_parent_with_subsystem_devtype(scsi, "usb", "usb_device");

        if (block && scsi_disk && usb) {
            printf("block = %s, usb = %s:%s, scsi = %s\n",
                   udev_device_get_devnode(block),
                   udev_device_get_sysattr_value(usb, "idVendor"),
                   udev_device_get_sysattr_value(usb, "idProduct"),
                   udev_device_get_sysattr_value(scsi, "vendor"));
        }

        if (block) {
            udev_device_unref(block);
        }

        if (scsi_disk) {
            udev_device_unref(scsi_disk);
        }

        udev_device_unref(scsi);
    }

    udev_enumerate_unref(enumerate);
}

int main()
{
    struct udev* udev = udev_new();

    enumerate_usb_mass_storage(udev);

    udev_unref(udev);
    return 0;
}*/
#endif // TABWIDGET_H

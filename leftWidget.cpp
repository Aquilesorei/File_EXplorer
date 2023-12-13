#include <QStandardPaths>
#include <QIcon>
#include <QDir>
#include <QTreeWidgetItem>
#include <QStorageInfo>
#include <iostream>
#include "leftWidget.h"
#include "tabwidget.h"
#include <QDirIterator>
#include <QDockWidget>
leftWidget::leftWidget(): mainWidget(new QWidget),
    left(new leftView),
    layout(new QVBoxLayout),
    deviceslist(new DeviceList)
{
    this->setFeatures(QDockWidget::NoDockWidgetFeatures);
    this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    layout->setContentsMargins(0,0,0,0);
    mainWidget->setLayout(layout);
    this->setWidget(mainWidget);

    layout->addWidget(left);
    layout->addWidget(deviceslist);
}

leftWidget::~leftWidget()
{

    delete layout;
    delete left;
   delete deviceslist;
}
DeviceList::DeviceList() {
    this->setHeaderLabel("Devices");
    this->setColumnCount(1);

    loadDrives();

    timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&DeviceList::loadDrives);
    timer->start(1500);

    connect(this,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(onItemClicked(QTreeWidgetItem*)));
}

DeviceList::~DeviceList() {
    timer->stop();
    delete timer;
}

void DeviceList::loadDrives() {
    this->clear();
    auto list = QStorageInfo::mountedVolumes();
    foreach (QStorageInfo d, list) {
        if ((!d.rootPath().startsWith("/run"))&&(!d.rootPath().startsWith("/boot"))) {
            usb.append(d);
            auto item = new QTreeWidgetItem(this);

            QDir di(d.rootPath());
            QStringList searchPatterns;
            auto lisa =di.entryList(searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
            //check is it's a system root
            foreach(auto volumefolder,lisa)
            {
                if((volumefolder=="ProgramData" or volumefolder =="Program Files" or volumefolder =="Program Files (x86)" or volumefolder=="Windows"))
                {
                    //qDebug()<<"touché";
                    item->setText(0,"Windows volume");
                }
                else if(d.rootPath()=="/")
                {
                    item->setText(0,"Computer");
                }
                else
                {
                    item->setText(0,d.displayName());
                }
            }

            item->setText(1,d.rootPath());
            item->setToolTip(0,d.device());
            item->setIcon(0,QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/drive-removable-media.svg"));
        }
    }
    emit usbr(usb);
}


void DeviceList::onItemClicked(QTreeWidgetItem *item) {
    QString text = item->text(1);
    tabWidget::currentWidget()->loadDir(text);
}

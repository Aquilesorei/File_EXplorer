#include "searchbar.h"

SearchBar::SearchBar(QWidget *parent):QWidget(parent)
{
      layout=new QHBoxLayout(this);
      label=new QLabel("Search");
      entry=new QLineEdit;
      close=new QPushButton("Close");
    this->setLayout(layout);

    entry->setClearButtonEnabled(true);

    layout->addWidget(label);
    layout->addWidget(entry);
    layout->addWidget(close,0,Qt::AlignRight);

}

SearchBar::~SearchBar() {
    delete layout;
    delete entry;
    delete close;
}


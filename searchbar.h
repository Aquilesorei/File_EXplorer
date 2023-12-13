#ifndef SEARCHBAR_H
#define SEARCHBAR_H
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class QLineEdit;
class Achille;

class SearchBar : public QWidget {
    Q_OBJECT
public:
    explicit SearchBar(QWidget *parent = nullptr);
    QLineEdit *entry;
    QPushButton *close;
    ~SearchBar();
private:

    QHBoxLayout *layout;
    QLabel *label;


};
#endif // SEARCHBAR_H

#include<QApplication>
#include "MainWindow.h"
#include "components/Analysa.h"

int main(int argc, char *argv[])
{
 QApplication app(argc, argv);

MainWindow fenetre;
 fenetre.showMaximized();
 fenetre.show();

 return app.exec();
}

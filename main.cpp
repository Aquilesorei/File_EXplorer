#include<QApplication>
#include "FenPrincipale.h"
#include "components/Analysa.h"

int main(int argc, char *argv[])
{
 QApplication app(argc, argv);

FenPrincipale fenetre;
 fenetre.showMaximized();
 fenetre.show();

 return app.exec();
}

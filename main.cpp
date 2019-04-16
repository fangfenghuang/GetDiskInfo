#include "qtdiskinfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDiskInfo w;
    w.show();

    return a.exec();
}

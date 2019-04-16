#ifndef QTDISKINFO_H
#define QTDISKINFO_H

#include <QMainWindow>

#define MAX_DISK_DISPLAY 32

namespace Ui {
class QtDiskInfo;
}

class QtDiskInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtDiskInfo(QWidget *parent = 0);
    ~QtDiskInfo();

private slots:
    void on_pb_Get_clicked();

private:
    Ui::QtDiskInfo *ui;
};

#endif // QTDISKINFO_H

#include "qtdiskinfo.h"
#include "ui_qtdiskinfo.h"
#include "diskinfo_dll.h"
#include "diskinfo_dll_global.h"
#include <QMessageBox>





QtDiskInfo::QtDiskInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtDiskInfo)
{
    ui->setupUi(this);
}

QtDiskInfo::~QtDiskInfo()
{
    delete ui;
}

void QtDiskInfo::on_pb_Get_clicked()
{
    int m_nDiskNum;
    //DiskInfo_dll diskinfo;
    PhyDiskInfo m_phyDiskInfo[MAX_DISK_DISPLAY];

    int iSystemPhyNumber = GetSystemDiskPhysicalNumber();  //获取系统盘盘符

    memset(m_phyDiskInfo, 0xFF, sizeof(PhyDiskInfo)*MAX_DISK_DISPLAY);
    bool IsTrue = GetPhyDisk(true, m_nDiskNum, m_phyDiskInfo);  //获取物理磁盘数、磁盘号、容量等
    if (!IsTrue)
    {
         QMessageBox::about(NULL, "Error", "GetPhyDisk Fail!");
         return;
    }
     ui->te_Log->append("------Get Disk Info------");
     _IDENTIFY_INFO struDiskIdentifyInfo;
     _DEVICE_ATTR_DATA SmartBlock;
     _DEVICE_ATTR_THRESHOLD ThresholdBlock;

     for (int i = 0; i < m_nDiskNum; i++)
     {
        /**跳过系统盘***/

        if (i == iSystemPhyNumber)
        #if 0
            continue;
        #else
            ui->te_Log->append("（系统盘）");
        #endif
         int ret = GetDiskBasicInfo(m_phyDiskInfo[i].dwPhyNum, struDiskIdentifyInfo, SmartBlock, ThresholdBlock);  //获取identify和SMART信息
         if (ret == 0)
         {
             m_phyDiskInfo[i].isValid = true;
         }
         else
         {
             m_phyDiskInfo[i].isValid = false;
         }
         m_phyDiskInfo[i].identifyInfo = struDiskIdentifyInfo;
         //m_phyDiskInfo[i].SmartBlock = SmartBlock;
         //m_phyDiskInfo[i].ThresholdBlock = ThresholdBlock;

         if (m_phyDiskInfo[i].isValid)
         {
            DWORD phyNum = m_phyDiskInfo[i].dwPhyNum;
            QString strDiskInfo = tr(">>Phy Disk %1:").arg(phyNum);
            ui->te_Log->append(strDiskInfo);

            QString strModel = QString("%1").arg(m_phyDiskInfo[i].identifyInfo.StrModel);   //Model name
            ui->te_Log->append("MN: "+strModel);

            QString strCapacity = QString("%1").arg(m_phyDiskInfo[i].dbPhyDiskCapacity);  //Cap
            ui->te_Log->append("Cap: "+strCapacity+" GB");

            QString strSN = QString("%1").arg(m_phyDiskInfo[i].identifyInfo.StrSn);  //SN
            ui->te_Log->append("SN: "+strSN);

            QString StrWWN = QString("%1").arg(m_phyDiskInfo[i].identifyInfo.StrWWN);
            ui->te_Log->append("WWN: "+StrWWN);  //WWN

            QString strFWVersiopn = QString("%1").arg(m_phyDiskInfo[i].identifyInfo.StrFwVersion);  //FW Version
            ui->te_Log->append("FW Version: "+strFWVersiopn);

            //SATA几
            QString StrCurrSATAV;
            if (m_phyDiskInfo[i].identifyInfo.bCurrSATAV <= 0)
                StrCurrSATAV =  ">SATA Error";
            else
            {
                switch (m_phyDiskInfo[i].identifyInfo.bCurrSATAV) {
                    default: StrCurrSATAV =  ">6.0 Gb/s (7)";
                    case 6:  StrCurrSATAV =  ">6.0 Gb/s (6)";
                    case 5:  StrCurrSATAV =  ">6.0 Gb/s (5)";
                    case 4:  StrCurrSATAV =  ">6.0 Gb/s (4)";
                    case 3:  StrCurrSATAV =  "6.0 Gb/s";
                    case 2:  StrCurrSATAV =  "3.0 Gb/s";
                    case 1:  StrCurrSATAV =  "1.5 Gb/s";
                 }
            }
            ui->te_Log->append("SATA: "+ StrCurrSATAV);  //SATA几

            ui->te_Log->append("------------------------");
         }
     }
     if (m_nDiskNum == 0)
     {
         ui->te_Log->append("Get Disk Error!\r");
     }

}

#ifndef DISKINFO_DLL_H
#define DISKINFO_DLL_H

#include "diskinfo_dll_global.h"


/*
Model :
Description :
Author :
Version : 1.0.0
Date : 2017.5.17
*/
#include <QObject>
#include <QDebug>
#include <stdio.h>
#include <objbase.h>
#include <WinBase.h>
#include <SetupAPI.h>
#include <WinNT.h>
#include <windows.h>
#include <tchar.h>
#include <dbt.h>
#include <ntddscsi.h>
#include <QFile>
#include <QDebug>
#include"ntddstor.h"
#include<devguid.h>
#include<InitGuid.h>
#include <ActiveQt/QAxObject>
#include <QtCore/qglobal.h>
#define BusTypeSata 0x0B
#define NUM_OF_IDENTIFYA  (20)
#define NUM_OF_ATA_SMART  (25)
#define NUM_OF_SN  (20)
#define SN_START  (20)
#define NUM_OF_FW  (8)
#define FW_START  (46)
#define NUM_OF_MODEL  (40)
#define MODEL_START  (54)

#define NUM_OF_WWN (8)
#define WWN_START (108<<1)
#define CURRSATA_START (77<<1)

#define MAX_PHY_DISK 26
#define MAX_DISK_DISPLAY 32
#define MAX_PARTITION 26
#define MAX_LOGIC_DISK 26
#define TGMK_SIZE 1024
#define SMART_INFO_SIZE  (512)
#define NUM_OF_ATA_SMART  (25)


#define MAX_AttrID_CHAR_NUM 27
#define MAX_Value_CHAR_NUM  22

#define SPT_SENSE_LENGTH 512
#define SPTWB_DATA_LENGTH 512

//
// Command Descriptor Block constants.
#define CDB6GENERIC_LENGTH                   6
#define CDB10GENERIC_LENGTH                  10

#define SETBITON                             1
#define SETBITOFF                            0
//
// Mode Sense/Select page constants.
//

#define MODE_PAGE_ERROR_RECOVERY        0x01
#define MODE_PAGE_DISCONNECT            0x02
#define MODE_PAGE_FORMAT_DEVICE         0x03
#define MODE_PAGE_RIGID_GEOMETRY        0x04
#define MODE_PAGE_FLEXIBILE             0x05
#define MODE_PAGE_VERIFY_ERROR          0x07
#define MODE_PAGE_CACHING               0x08
#define MODE_PAGE_PERIPHERAL            0x09
#define MODE_PAGE_CONTROL               0x0A
#define MODE_PAGE_MEDIUM_TYPES          0x0B
#define MODE_PAGE_NOTCH_PARTITION       0x0C
#define MODE_SENSE_RETURN_ALL           0x3f
#define MODE_SENSE_CURRENT_VALUES       0x00
#define MODE_SENSE_CHANGEABLE_VALUES    0x40
#define MODE_SENSE_DEFAULT_VAULES       0x80
#define MODE_SENSE_SAVED_VALUES         0xc0
#define MODE_PAGE_DEVICE_CONFIG         0x10
#define MODE_PAGE_MEDIUM_PARTITION      0x11
#define MODE_PAGE_DATA_COMPRESS         0x0f

//
// SCSI CDB operation codes
//

#define SCSIOP_TEST_UNIT_READY     0x00
#define SCSIOP_REZERO_UNIT         0x01
#define SCSIOP_REWIND              0x01
#define SCSIOP_REQUEST_BLOCK_ADDR  0x02
#define SCSIOP_REQUEST_SENSE       0x03
#define SCSIOP_FORMAT_UNIT         0x04
#define SCSIOP_READ_BLOCK_LIMITS   0x05
#define SCSIOP_REASSIGN_BLOCKS     0x07
#define SCSIOP_READ6               0x08
#define SCSIOP_RECEIVE             0x08
#define SCSIOP_WRITE6              0x0A
#define SCSIOP_PRINT               0x0A
#define SCSIOP_SEND                0x0A
#define SCSIOP_SEEK6               0x0B
#define SCSIOP_TRACK_SELECT        0x0B
#define SCSIOP_SLEW_PRINT          0x0B
#define SCSIOP_SEEK_BLOCK          0x0C
#define SCSIOP_PARTITION           0x0D
#define SCSIOP_READ_REVERSE        0x0F
#define SCSIOP_WRITE_FILEMARKS     0x10
#define SCSIOP_FLUSH_BUFFER        0x10
#define SCSIOP_SPACE               0x11
#define SCSIOP_INQUIRY             0x12
#define SCSIOP_VERIFY6             0x13
#define SCSIOP_RECOVER_BUF_DATA    0x14
#define SCSIOP_MODE_SELECT         0x15
#define SCSIOP_RESERVE_UNIT        0x16
#define SCSIOP_RELEASE_UNIT        0x17
#define SCSIOP_COPY                0x18
#define SCSIOP_ERASE               0x19
#define SCSIOP_MODE_SENSE          0x1A
#define SCSIOP_START_STOP_UNIT     0x1B
#define SCSIOP_STOP_PRINT          0x1B
#define SCSIOP_LOAD_UNLOAD         0x1B
#define SCSIOP_RECEIVE_DIAGNOSTIC  0x1C
#define SCSIOP_SEND_DIAGNOSTIC     0x1D
#define SCSIOP_MEDIUM_REMOVAL      0x1E
#define SCSIOP_READ_CAPACITY       0x25
#define SCSIOP_READ                0x28
#define SCSIOP_WRITE               0x2A
#define SCSIOP_SEEK                0x2B
#define SCSIOP_LOCATE              0x2B
#define SCSIOP_WRITE_VERIFY        0x2E
#define SCSIOP_VERIFY              0x2F
#define SCSIOP_SEARCH_DATA_HIGH    0x30
#define SCSIOP_SEARCH_DATA_EQUAL   0x31
#define SCSIOP_SEARCH_DATA_LOW     0x32
#define SCSIOP_SET_LIMITS          0x33
#define SCSIOP_READ_POSITION       0x34
#define SCSIOP_SYNCHRONIZE_CACHE   0x35
#define SCSIOP_COMPARE             0x39
#define SCSIOP_COPY_COMPARE        0x3A
#define SCSIOP_WRITE_DATA_BUFF     0x3B
#define SCSIOP_READ_DATA_BUFF      0x3C
#define SCSIOP_CHANGE_DEFINITION   0x40
#define SCSIOP_READ_SUB_CHANNEL    0x42
#define SCSIOP_READ_TOC            0x43
#define SCSIOP_READ_HEADER         0x44
#define SCSIOP_PLAY_AUDIO          0x45
#define SCSIOP_PLAY_AUDIO_MSF      0x47
#define SCSIOP_PLAY_TRACK_INDEX    0x48
#define SCSIOP_PLAY_TRACK_RELATIVE 0x49
#define SCSIOP_PAUSE_RESUME        0x4B
#define SCSIOP_LOG_SELECT          0x4C
#define SCSIOP_LOG_SENSE           0x4D

#define SCSIOP_READ_SCSI_BUFF      0xA1

//******************************************************************************************************/

typedef struct _SCSI_PASS_THROUGH_WITH_BUFFERS {
    SCSI_PASS_THROUGH spt;
    ULONG             Filler;      // realign buffers to double word boundary
    UCHAR             ucSenseBuf[SPT_SENSE_LENGTH];
    UCHAR             ucDataBuf[SPTWB_DATA_LENGTH];
} SCSI_PASS_THROUGH_WITH_BUFFERS, *PSCSI_PASS_THROUGH_WITH_BUFFERS;

typedef struct _SCSI_PASS_THROUGH_DIRECT_WITH_BUFFER {
    SCSI_PASS_THROUGH_DIRECT sptd;
    ULONG             Filler;      // realign buffer to double word boundary
    UCHAR             ucSenseBuf[SPT_SENSE_LENGTH];
} SCSI_PASS_THROUGH_DIRECT_WITH_BUFFER, *PSCSI_PASS_THROUGH_DIRECT_WITH_BUFFER;

//*********************************************************************************************//
//ID Infomation
typedef struct
{
    char StrSn[MAX_PATH];
    char StrModel[MAX_PATH];
    char StrFwVersion[MAX_PATH];
    char StrWWN[MAX_PATH];
    byte bCurrSATAV;   //StrCurrentSATAVersion
}_IDENTIFY_INFO;
//SMART每个ID对应的信息 size = 12
typedef struct
{
    byte bAttrID;
    byte wStatusFlagL;
    byte wStatusFlagH;
    byte bAttrValue;
    byte bWorst;
    byte abRaw[6];
    byte bReserved;
} _IND_ATTR_DATA;

//SMART原始数据 512个字节
typedef struct
{
    WORD wRevisionNum;
    _IND_ATTR_DATA aIndAttrData[30];
    byte bOfflineCollectStatus;
    byte bSelftestExeStatus;
    WORD wOfflineCollectTotalTime;
    byte bVendor1;
    byte bOfflineCollectCapability;
    WORD wSmartCapability;
    byte bErrLogCapability;
    byte bVendor2;
    byte bShortPollingTime;
    byte bExtendedPollingTime;
    byte bConveyancePollingTime; //offs=374
    byte wExtendedPollingTimeLSB; //offs=375
    byte wExtendedPollingTimeMSB; //offs=376
} _DEVICE_ATTR_DATA; //packet to host!

//SMART每个ID对应的Threshold信息 size = 12
typedef struct
{
    byte bAttrID;
    byte bAttrThreshold;//磁盘的阈值 现在不怎么用到
    byte abRawThreshold[6];//技术维修参数放的阈值
    byte abReserved[4];
} _IND_ATTR_THRESHOLD;

//Threshold原生数据 512个字节
typedef struct
{
    WORD wRevisionNum;
    _IND_ATTR_THRESHOLD aIndAttrThreshold[30];
    byte abReserved[18];
    byte abVendor[131];
    byte bChecksum;
} _DEVICE_ATTR_THRESHOLD; //sz=512

//磁盘挂载状况
//typedef struct _VDS_VOLUME_PROP
//{
//	VDS_OBJECT_ID        id;
//	VDS_VOLUME_TYPE      type;
//	VDS_VOLUME_STATUS    status;
//	VDS_HEALTH           health;
//	VDS_TRANSITION_STATE TransitionState;
//	ULONGLONG            ullSize;
//	ULONG                ulFlags;
//	VDS_FILE_SYSTEM_TYPE RecommendedFileSystemType;
//	LPWSTR               pwszName;
//} VDS_VOLUME_PROP, *PVDS_VOLUME_PROP;
//typedef enum  {
//	VDS_VS_UNKNOWN = 0,
//	VDS_VS_ONLINE = 1,
//	VDS_VS_NO_MEDIA = 3,
//	VDS_VS_FAILED = 5,
//	VDS_VS_OFFLINE = 4
//} VDS_VOLUME_STATUS;


struct PhyDiskInfo
{
    //物理磁盘号
    DWORD  dwPhyNum;
    //物理磁盘容量
    double dbPhyDiskCapacity;
    //该物理磁盘共有的逻辑分区数
    BYTE byTotalLogicDiskNum;
    //该物理磁盘各个逻辑分区的盘符
    char szLogicName[MAX_PARTITION];
    //该物理磁盘各个逻辑分区的总容量
    double dbTotalDiskSize[MAX_PARTITION];
    //该物理磁盘各个逻辑分区的可用总容量
    double dbFreeDiskSize[MAX_PARTITION];
    //是否有效（除去USB 或者获取不到信息的磁盘等设备）
    bool isValid;
    //序列号、型号、固件版本、WWN、SATA接口状态
    _IDENTIFY_INFO identifyInfo;
    //SMart 数据
    _DEVICE_ATTR_DATA SmartBlock;
    //THRESHOLD数据
    _DEVICE_ATTR_THRESHOLD ThresholdBlock;
    //是否为系统盘
    bool isSysDisk;
};


    //获取系统盘符及对应物理盘号
    int GetSystemDiskPhysicalNumber(void);
    //通过卷号获取所属物理磁盘号 参数为系统逻辑盘卷符号
    int GetPhysicalDriveFromPartitionLetter(CHAR cLetter);
    //获取当前PC上所有物理盘及其对应信息
    bool GetPhyDisk(BOOL bIsSuprrotSysDisk,int& iPhyDiskNum ,PhyDiskInfo* struPhyDiskInfo);
    //获取当前PC上所有物理盘符所对应的逻辑磁盘信息，该函数必须在调用过GetPhyDisk函数之后使用，否则会有问题
    int GetLogicDisk(int iPhyDiskNum,PhyDiskInfo* struPhyDiskInfo);
    //根据磁盘号得到总线类型
    bool GetBusType(int nDiskIndex, STORAGE_BUS_TYPE &sp_bus_type);
    //删除分区
    int DestroyDisk(DWORD disk);
    //得到磁盘基本信息
    int GetDiskBasicInfo(int nDiskIndex, _IDENTIFY_INFO& identifyInfo,
                                    _DEVICE_ATTR_DATA& SmartBlock, _DEVICE_ATTR_THRESHOLD& ThresholdBlock);

    /************28bitATA命令发送**************/
    bool Send_ATACmd(char *deviceName, BYTE ATACmd[], BYTE buf[], int sectors, BYTE isRead);
    bool ReadIdentfy_ATA(char *deviceName,BYTE *buffer);//ATA读Identfy数据
    bool ReadSmart_ATA(char *deviceName,BYTE *buffer);//ATA读Smart数据
    bool ReadSmartThresholds_ATA(char *deviceName,BYTE* buffer);//ATA读Smart Threshold数据
    quint64 ReadMaxAddr_ATA(char *deviceName);//ATA读MAX ADDR
    bool SetLife_ATA(char *deviceName,BYTE *buffer,BYTE byLifePercent,BYTE bySectorCnt);//ATA设置LIFE ATA命令
    bool DownMicrocode_ATA(char *deviceName,BYTE ATACmd[],BYTE *buffer,int sectors);	//ATA DownMicrocode命令发送

    /*************48bitATA命令发送*************/
    bool Send_ATACmdEX(char *deviceName, BYTE ATACmd[], BYTE buf[], int sectors);
    bool SetMaxAddrEx_ATA(char *deviceName,BYTE *buffer,ULONGLONG MaxAddrSet);//ATA设置MAX ADDR
    ULONGLONG ReadMaxAddrEx_ATA(char *deviceName);//ATA读MAX ADDR

    /************SCSI命令发送**************/
    bool Send_ScsiCmd(CHAR *deviceName, UCHAR *g_cbd, BYTE *buf, int sectors, bool isread);
    bool ReadIdentfy_SCSI(CHAR *deviceName,BYTE *buffer);//SCSI读Identfy数据
    bool ReadSmart_SCSI(char *deviceName,BYTE *buffer);//SCSI读Smart数据
    bool ReadSmartThresholds_SCSI(char *deviceName,BYTE *buffer);//SCSI读Smart Threshold数据
    quint64 ReadMaxAddr_SCSI(char *deviceName);//SCSI读MAX ADDR
    bool DownMicrocode_SCSI(char *deviceName, BYTE ATACmd[], BYTE *buffer, int sectors);//SCSI DownMicrocode命令发送


#endif // DISKINFO_H


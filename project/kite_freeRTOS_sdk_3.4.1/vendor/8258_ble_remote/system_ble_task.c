/**********************************************************************************************************
 *
 * @file system_ble_task.c
 * 
 * @brief       ����Э��ջ�ӿ�Դ�ļ�
 * 
 * @author      Chenhao
 * @date        Created:    2019-07-08
 * 

**********************************************************************************************************/
#include "system_ble_task.h"
//#include "system_resource.h"
//#include "../Modules/Ble/ew_mod_ble.h"
#include "stack/ble/ble.h"

/**********************************************************************************************************
  Constants and macros
**********************************************************************************************************/

#define __BLE_DEBUG              ( 0 )
#if __BLE_DEBUG
#define ble_debug(...)           printf(__VA_ARGS__) 
#else
#define ble_debug(...)
#endif

/**********************************************************************************************************
  extern  function
**********************************************************************************************************/

/**********************************************************************************************************
  Private functions
**********************************************************************************************************/


/**********************************************************************************************************
  �����ӿ�: �¼�����
**********************************************************************************************************/

/**
 * @brief �Ͽ����� 
 */
void Ops_BleClose (void)   
{
	bls_ll_terminateConnection (HCI_ERR_REMOTE_USER_TERM_CONN);
}

/**
 * @brief ֹͣ�㲥 
 */
void Ops_BleAdvStop (void)   
{
	bls_ll_setAdvEnable(0);
}

/**
 * @brief �����㲥 
 */
void Ops_BleAdvStart (void)  
{
	bls_ll_setAdvEnable(1);
}

/**
 * @brief ����������Ӳ��� 
 * @param  connIntervalMin: Minimum connection interval.
 * @param  connIntervalMax: Maximum connection interval.
 * @param  connLatency: Connection latency.
 * @param  supTimeout: Supervision timeout.
 */
void Ops_BleUpdateConnParam (u16 connIntervalMin, u16 connIntervalMax, u16 connLatency, u16 supTimeout)
{
	bls_l2cap_requestConnParamUpdate (connIntervalMin, connIntervalMax, connLatency, supTimeout);
}

/**
 * @brief �������MTU 
 * @param  mtuReqSize:�����С
 */
void Ops_BleUpdateMtu (u16 mtuReqSize)
{
	blc_att_setRxMtuSize(mtuReqSize);
}

/**
 * @brief д����ֵ8002 
 */
void Ops_Ble8002CharacterSendData (u8 *pData, u16 Len)
{
	ble_sts_t bret = BLE_SUCCESS;
	u8 *	  pt = pData;
	while(Len)
	{
		if( Len > 20 ){
			bret = bls_att_pushIndicateData(27, pt, 20);
			Len -= 20;
			pt+=20;
		}
		else{
			bret = bls_att_pushIndicateData(27, pt, Len);
			Len = 0;
			pt = pt+Len;
			Cb_BleOn8002CharacterSendDataComplete();
		}
	}
	return;
}

/**
 * @brief д����ֵ8004 
 */
void Ops_Ble8004CharacterSendData (u8 *pData, u16 Len)
{
	ble_sts_t bret = BLE_SUCCESS;
	u8 *	  pt = pData;
	while(Len)
	{
		if( Len > 20 ){
			bret = bls_att_pushNotifyData(32, pt, 20);
			Len -= 20;
			pt+=20;
		}
		else{
			bret = bls_att_pushNotifyData(32, pt, Len);
			Len = 0;
			pt = pt+Len;
			Cb_BleOn8004CharacterSendDataComplete();
		}
	}
	return;
}

/**
 * @brief �ر�BLE
 */
void Ops_BleShutdown (void)  
{
	cpu_sleep_wakeup(DEEPSLEEP_MODE_RET_SRAM_LOW32K, PM_WAKEUP_PAD, 0);
}

/**
 * @brief ����BLE 
 */
void Ops_BleShutup (void)  
{

}

/**
 * @brief ANCS:��ȡ��һ��ancs
 */
void Ops_BleGetNextAncs (void)  
{

}

/**
 * @brief ANCS:���������ͨ :NOTIF_ACTION_ID_POSITIVE
 * @param  notificationUID:Ψһ��ʾ����Ϣ
 */
void Ops_BleAcceptIncomingCall (u32 notificationUID)
{
  

}

/**
 * @brief ANCS:��������Ҷ�: NOTIF_ACTION_ID_NEGATIVE
 * @param  notificationUID:Ψһ��ʾ����Ϣ
 */
void Ops_BleRejectIncomingCall (u32 notificationUID)
{

}

/**
 * @brief AMS: EU����
 */
void Ops_BleAmsEuSubscribe (void)  
{

}

/**
 * @brief AMS: ���ֿ��� 
 * @param  controlCmd: 0:Play 1:Pause 2:TogglePlayPause 3:NextTrack 4:PreviousTrack 5:VolumeUp 6:VolumeDown
 */
void Ops_BleAmsMusicControl (u8 controlCmd)
{

}

/**********************************************************************************************************
  �����ӿ�: �¼��ص�
**********************************************************************************************************/
/**
 * @brief ���������¼� 
 */
void Cb_BleOnConnect(void)                          
{

}

/**
 * @brief ���������¼�  
 * @param  reason: ����ԭ��
 */
void Cb_BleOnDisConnect(u8 reason)
{

}

/**
 * @brief ���������ֻ�ancs����ʧ�ܣ��˴����ӵ���Android����
 */
void Cb_BleOnAncsSvcDiscoverFailed(void)        
{

}

/**
 * @brief �����õ����Ӳ������Ľ�� 
 * @param  result: 0 ʧ�� 1�ɹ�
 * @param  connInterval: �������Ӽ�� (ms)
 * @param  connLatency: ����Latency
 */
void Cb_BleOnUpdateConnParamsResult(u8 result, u16 connInterval, u16 connLatency)
{

}

/**
 * @brief ��ȡ�������ӵ�mtuֵ��С
 * @param  mtuSize: ��С
 */
void Cb_BleOnGetMtuSize (u16 mtuSize)
{

}

/**
 * @brief ��ȡ������ֵ8001������
 */
void Cb_BleOn8001CharacterGetData (u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ������ֵ8003������
 */
void Cb_BleOn8003CharacterGetData (u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ������ֵ8002д�������
 */
void Cb_BleOn8002CharacterSendDataComplete (void)   
{

}

/**
 * @brief ��ȡ������ֵ8004д�������
 */
void Cb_BleOn8004CharacterSendDataComplete (void)  
{

}

/**
 * @brief ��ȡ������ֵ8002��Ntf�ܵ��ֻ��˵Ĳ���
 * @param  isEnable: 0 ���� 1 ʹ��
 */
void Cb_BleOn8002CharacterNtf (bool isEnable)
{

}

/**
 * @brief ��ȡ������ֵ8004��Ntf�ܵ��ֻ��˵Ĳ���
 * @param  isEnable: 0 ���� 1 ʹ��
 */
void Cb_BleOn8004CharacterNtf (bool isEnable)  
{

}


/**
 * @brief ��ȡ��Ancsͷ��Ϣ
 * @param  notificationUID: Ψһ��ʾ����Ϣ
 * @param  eventID: ��ʾ��Added����Modified����Removed
 * @param  eventFlags: ��ancsЭ��
 * @param  categoryID: ��Ϣ����
 * @param  categoryCount: ���������л�Ծ��֪ͨ������
 * @param  appIdentifier: App ID������ַ�������ʹ��NULL��β
 */
void Cb_BleOnAncsGetHeadInfo (u32 notificationUID,u8 eventID,u8 eventFlags,u8 categoryID,u8 categoryCount, u8* appIdentifier)
{

}

/**
 * @brief ��ȡ��Ancs���� Title 
 */
void Cb_BleOnAncsGetTitle(u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ��Ancs����Message 
 */
void Cb_BleOnAncsGetMessage(u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ��Ancsʱ�� Date
 */
void Cb_BleOnAncsGetDate(u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_PLAYER�� �� AMS_PLAYATTRIBUTE_ID_PLAYBACK_INFO 
        (PlaybackStatePaused=0 PlaybackStatePlaying=1 PlaybackStateRewinding=2 PlaybackStateFastForwarding=3)
 */
void Cb_BleOnAmsGetPlayState(u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_PLAYER�� ��  ��AMS_PLAYATTRIBUTE_ID_VOLUME      
 */
void Cb_BleOnAmsGetVolume(u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_TRACK�� ��  ��AMS_TRACK_ATTRIBUTE_ID_ARTIST     
 */
void Cb_BleOnAmsGetArtist(u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_TRACK�� ��  ��AMS_TRACK_ATTRIBUTE_ID_TITLE   
 */
void Cb_BleOnAmsGetTitle(u8 *pData, u16 Len)
{

}

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_TRACK�� ��  ��AMS_TRACK_ATTRIBUTE_ID_DURATION   
 */
void Cb_BleOnAmsGetDuration(u8 *pData, u16 Len)
{

}

/**********************************************************************************************************
  Local variables
**********************************************************************************************************/

/**********************************************************************************************************
  Functions
**********************************************************************************************************/

/**
* @brief (resource) ִ�����������¼�
* @return  false:û���û�����OPS�ӿ�;            true:���û�����OPS�ӿ�.
*/
bool System_Ble_Task_OpsDispatcher (void)
{

    return false;
}

/**
* @brief (resource) ����Ble Taskִ�� 
*/
void System_Ble_Task_WakeUp (void)
{

}

/**********************************************************************************************************
  END FILE
**********************************************************************************************************/

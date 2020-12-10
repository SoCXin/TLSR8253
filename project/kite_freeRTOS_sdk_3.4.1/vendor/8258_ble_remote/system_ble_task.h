/**********************************************************************************************************
 *
 * @file system_ble_task.h
 * 
 * @brief       ����Э��ջ�ӿ�Դ�ļ�
 * 
 * @author      Chenhao
 * @date        Created:    2019-07-08
 * 
**********************************************************************************************************/
#ifndef __SYSTEM_BLE_TASK_H
#define __SYSTEM_BLE_TASK_H

/**********************************************************************************************************
  Includes
**********************************************************************************************************/
#include "tl_common.h"

/**********************************************************************************************************
  Defines
**********************************************************************************************************/

/**********************************************************************************************************
  Typedefs
**********************************************************************************************************/

/**********************************************************************************************************
  Extern
**********************************************************************************************************/


/**********************************************************************************************************
  Functions 
**********************************************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief ���������¼� 
 */
void Cb_BleOnConnect(void);                          

/**
 * @brief ���������¼�  
 * @param  reason: ����ԭ��
 */
void Cb_BleOnDisConnect(u8 reason);

/**
 * @brief ���������ֻ�ancs����ʧ�ܣ��˴����ӵ���Android����
 */
void Cb_BleOnAncsSvcDiscoverFailed(void);        

/**
 * @brief �����õ����Ӳ������Ľ�� 
 * @param  result: 0 ʧ�� 1�ɹ�
 * @param  connInterval: �������Ӽ�� (ms)
 * @param  connLatency: ����Latency
 */
void Cb_BleOnUpdateConnParamsResult(u8 result, u16 connInterval, u16 connLatency);

/**
 * @brief ��ȡ�������ӵ�mtuֵ��С
 * @param  mtuSize: ��С
 */
void Cb_BleOnGetMtuSize (u16 mtuSize);

/**
 * @brief ��ȡ������ֵ8001������
 */
void Cb_BleOn8001CharacterGetData (u8 *pData, u16 Len);

/**
 * @brief ��ȡ������ֵ8003������
 */
void Cb_BleOn8003CharacterGetData (u8 *pData, u16 Len);

/**
 * @brief ��ȡ������ֵ8002д�������
 */
void Cb_BleOn8002CharacterSendDataComplete (void);   

/**
 * @brief ��ȡ������ֵ8004д�������
 */
void Cb_BleOn8004CharacterSendDataComplete (void);  

/**
 * @brief ��ȡ������ֵ8002��Ntf�ܵ��ֻ��˵Ĳ���
 * @param  isEnable: 0 ���� 1 ʹ��
 */
void Cb_BleOn8002CharacterNtf (bool isEnable);

/**
 * @brief ��ȡ������ֵ8004��Ntf�ܵ��ֻ��˵Ĳ���
 * @param  isEnable: 0 ���� 1 ʹ��
 */
void Cb_BleOn8004CharacterNtf (bool isEnable);  

/**
 * @brief ��ȡ��Ancsͷ��Ϣ
 * @param  notificationUID: Ψһ��ʾ����Ϣ
 * @param  eventID: ��ʾ��Added����Modified����Removed
 * @param  eventFlags: ��ancsЭ��
 * @param  categoryID: ��Ϣ����
 * @param  categoryCount: ���������л�Ծ��֪ͨ������
 * @param  appIdentifier: App ID������ַ�������ʹ��NULL��β
 */
void Cb_BleOnAncsGetHeadInfo (u32 notificationUID,u8 eventID,u8 eventFlags,u8 categoryID,u8 categoryCount, u8* appIdentifier);

/**
 * @brief ��ȡ��Ancs���� Title 
 */
void Cb_BleOnAncsGetTitle(u8 *pData, u16 Len);

/**
 * @brief ��ȡ��Ancs����Message 
 */
void Cb_BleOnAncsGetMessage(u8 *pData, u16 Len);

/**
 * @brief ��ȡ��Ancsʱ�� Date
 */
void Cb_BleOnAncsGetDate(u8 *pData, u16 Len);

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_PLAYER�� �� AMS_PLAYATTRIBUTE_ID_PLAYBACK_INFO 
        (PlaybackStatePaused=0 PlaybackStatePlaying=1 PlaybackStateRewinding=2 PlaybackStateFastForwarding=3)
 */
void Cb_BleOnAmsGetPlayState(u8 *pData, u16 Len);

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_PLAYER�� ��  ��AMS_PLAYATTRIBUTE_ID_VOLUME      
 */
void Cb_BleOnAmsGetVolume(u8 *pData, u16 Len);

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_TRACK�� ��  ��AMS_TRACK_ATTRIBUTE_ID_ARTIST     
 */
void Cb_BleOnAmsGetArtist(u8 *pData, u16 Len);

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_TRACK�� ��  ��AMS_TRACK_ATTRIBUTE_ID_TITLE   
 */
void Cb_BleOnAmsGetTitle(u8 *pData, u16 Len);

/**
 * @brief ��ȡ��Ams��AMS_ENTITY_ID_TRACK�� ��  ��AMS_TRACK_ATTRIBUTE_ID_DURATION   
 */
void Cb_BleOnAmsGetDuration(u8 *pData, u16 Len);

/**
* @brief (resource) ִ�����������¼�
* @return  false:û���û�����OPS�ӿ�;            true:���û�����OPS�ӿ�.
*/
bool System_Ble_Task_OpsDispatcher (void);

/**
* @brief (resource) ����Ble Taskִ�� 
*/
void System_Ble_Task_WakeUp (void);


#ifdef __cplusplus
}
#endif

#endif                                                                  
/**********************************************************************************************************
  END FILE
**********************************************************************************************************/

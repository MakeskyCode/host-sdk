#pragma once
#include "SDKProtocol.h"
namespace NaviPackSdk_Cpp {
	class NaviPackSdk
	{
	public:
		NaviPackSdk();
		~NaviPackSdk();


		/// ��õ�ǰSDK�İ汾��
		/// @return ����NaviPack�����ID
		/// @note ����ֵ��3���������: ���汾��(Bits 24 ~31), �Ӱ汾��(Bits 16 ~ 23), �����(Bits 0 ~ 15)
		 int  GetSDKVersion();

		/// ��õ�ǰNaviPack�İ汾��
		/// @return ����NaviPack�����ID
		/// @note ����ֵ��3���������: ���汾��(Bits 24 ~31), �Ӱ汾��(Bits 16 ~ 23), �����(Bits 0 ~ 15)
		 int  SetGetNaviPackVersion(int id);

		/// ����һ��NaviPack����
		/// @return ����NaviPack�����ID >=0Ϊ�����ɹ�
		 int  Create(ConnectType conType);

		/// ����NaviPack����
		/// @param id ������NaviPack�����ID
		 void  Destroy(int id);

		/// ��NaviPack���󣬸ú��������ݲ�ͬ�Ĳ������������򿪲�ͬ���豸
		/// @param[in] id NaviPack����ID
		/// @param[in] name �ӿ����ƣ������TCP/UDPЭ�飬����д�Է���IP��ַ������Ǵ��ڣ�����д�����豸����, Windows��Ϊ��////.//COM?, Linux��Ϊ/dev/ttyACM?
		/// @param[in] param �ӿڲ����������TCP/UDPЭ�飬����д�Է��Ķ˿ڡ������COM������д�ӿڵĲ����ʡ�
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int  Open(int id, const char* name, int param);

		/// ���´�֮ǰ���رյ�NaviPack�ӿ�
		/// @param[in] id NaviPack����ID
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int  Reopen(int id);

		/// �ر�NaviPack�ӿ�
		/// @param[in] id NaviPack����ID
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int  Close(int id);


		/// ���ôӷ���˴�����Ϣ���ݵĻص�
		/// @param[in] id NaviPack ����ID
		/// @param[in] deviceMsgCb �豸��Ϣ�ص�
		/// @param[in] errMsgCb	   �豸������Ϣ�ص�
		/// @param[in] lidarPackCb �״�ԭʼ���ݻص�
		/// @return  ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int  SetCallback(int id, DeviceMsgCallBack deviceMsgCb, ErrorMsgCallBack errMsgCb, MapPackageCallBack mapPackCb, LidarPackageCallBack lidarPackCb);

		/// ��ȡ����Ĳ���
		/// @param[in] id NaviPack����ID
		/// @param[out] param ����ָ��
		/// @note CarrierParam ������NaviPack�������������˶��ٶȣ�������󳤿�NaviPack��װλ�ã�NaviPack��װ������Ϣ��
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int  GetCarrierParam(int id, CarrierParam *param);

		/// ��������Ĳ���
		/// @param[in] id NaviPack����ID
		/// @param[in] param ����ָ��
		/// @note CarrierParam ������NaviPack�������������˶��ٶȣ�������󳤿�NaviPack��װλ�ã�NaviPack��װ������Ϣ��
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int  SetCarrierParam(int id, CarrierParam *param);

		/// ��ȡNaviPack�Ĳ���
		/// @param[in] id NaviPack����ID
		/// @param[out] param ����ָ��
		/// @note NaviPackParam ������NaviPackϵͳ��һЩ������Ϣ�������Ƿ��Զ����µ�ͼ��դ���С��һЩ������
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int  GetNaviPackParam(int id, NaviPackParam *param);

		/// ��������Ĳ���
		/// @param[in] id NaviPack����ID
		/// @param[in] param ����ָ��
		/// @note NaviPackParam ������NaviPackϵͳ��һЩ������Ϣ�������Ƿ��Զ����µ�ͼ��դ���С��һЩ������
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SetNaviPackParam(int id, NaviPackParam *param);

		/// ����Ŀ����б� ����һ�����ö��Ŀ��㣬������ɺ�NaviPack�������Զ�����״̬��
		/// ���𲽱����û����õĵ����㡣���˶������У�NaviPack���Զ���ɶ�̬·���滮�ͱ��Ϲ�����
		/// @param[in] id NaviPack����ID
		/// @param[in] position_x ·����X���껺���� ��λmm
		/// @param[in] position_y ·����Y���껺���� ��λmm
		/// @param[in] num ·��������				
		/// @param[in] phi �������һ����ĽǶ�		��λ����
		/// @note SetTargets������ֻ����NaviPack��ɶ�λ���������ͼ�󣬲Ż���Ч���ú����Ĳ���λ�ã���ָ��������ϵ�µ�λ����Ϣ��
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SetTargets(int id, int position_x[], int position_y[], int num, int phi);

		/// ��ȡ��ǰ�Ѿ����õ�·����
		/// @param[in] id NaviPack����ID
		/// @param[out] position_x ·����X���껺����
		/// @param[out] position_y ·����Y���껺����
		/// @param[out] num ·��������
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   GetCurrentPath(int id, int position_x[], int position_y[], int* num);

		/// ������������������֮���ת��
		/// @param[in] id NaviPack����ID
		/// @param[in] pixel_y ·����X���껺����
		/// @param[in] pixel_y ·����Y���껺����
		/// @param[out] position_x ·��������
		/// @param[out] position_y ·��������
		/// @note �ú������ڽ���ͼ���������꣬ת��Ϊ��������ϵ����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   PixelToPosition(int id, int pixel_x, int pixel_y, int *position_x, int *position_y);

		/// ������������������֮���ת��
		/// @param[in] id NaviPack����ID
		/// @param[out] pixel_y ·����X���껺����
		/// @param[out] pixel_y ·����Y���껺����
		/// @param[in] position_x ·��������
		/// @param[in] position_y ·��������
		/// @note �ú������ڽ���ͼ���������꣬ת��Ϊ��������ϵ����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   PositionToPixel(int id, int position_x, int position_y, int *pixel_x, int *pixel_y);

		/// �����豸�������ٶ�v�����ٶ�w�˶���
		/// @param[in] id NaviPack����ID
		/// @param[in] v Ŀ�����ٶ�
		/// @param[in] w Ŀ����ٶ�
		/// @note �ú���������ֱ�ӿ����豸���˶�������豸��ǰ���ڴ����Զ�����״̬������˳��Զ�����״̬������������ֶ�ң�ء�
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SetSpeed(int id, int v, int w);

		/// ����NaviPack�����Զ��س�״̬
		/// @param[in] id NaviPack����ID
		/// @note �豸�յ�������󣬽��Զ�����س�״̬��NaviPack�����������Զ��˶������׮λ�ã�
		/// ����׼�豸�Ӵ���硣�ú���Ҫ��������λ���Ѿ�ͨ�� SetChargerPosition ���ã����������������й���磨���ʱ�����׮��λ�ã������Զ�����¼��
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		/// @see SetChargerPosition
		 int   AutoCharge(int id);

		/// ���ó��׮��λ��
		/// @param[in] id NaviPack����ID
		/// @param[in] param ����ָ��
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SetChargerPosition(int id, int position_x, int position_y);

		/// ���뽨ͼģʽ
		/// @param[in] id NaviPack����ID
		/// @param[in] mappingMode ��ͼģʽ��0 ��ʾ �ֶ���ͼ��1 ��ʾ�Զ���ͼ
		/// @note �ú������ڶԻ������н�ͼ����ѡ���ֶ���ͼʱ����������˶�������λ����������ѡ���Զ���ͼʱ��
		/// ������˶�����NaviPack�Զ����ƣ�NaviPack���Զ����������������������
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   StartMapping(int id, int mappingMode = 0);

		/// �˳���ͼģʽ
		/// @param[in] id NaviPack����ID
		/// @param[in] save_flag �Ƿ񱣴��ͼ
		/// :-1,�����棬֧��0~7��ͼ�ļ��б�ţ�Ĭ�ϵ�ͼ������0�ŵ�ͼ�ļ�����
		/// @note �˳���ͼģʽ��ϵͳ����IDLE״̬���ú����Ľ�ֹͣ��ͼ��������save_flag��ֵ���������Ƿ񽫵�ǰ����֮��ͼ��
		/// ����������ϵͳ�У�����ܹ��洢8����ͼ�������Ĳ��֣����ᱻ�µĵ�ͼ���ǡ�
		/// @return ����ֵС��0����ʾʧ�ܣ����ڵ����㣬��ʾ��ͼ�ɹ�������ֵ����ʾ��ǰ�ĵ�ͼ����ID����δ���棬�ҳɹ����򷵻�0��
		 int   StopMapping(int id, int save_flag = 0);

		/// ��ȡNaviPack�еĵ�ͼ�б�
		/// @param[in] id NaviPack����ID
		/// @param[out] id_buffer ���ڴ�ŵ�ͼID�Ļ��������û��������Ϊ8����
		/// @note �ú�������ȡϵͳ�б�������еĵ�ͼID��
		/// @return ����ֵС��0����ʾʧ�ܣ����ڻ�����㣬��ʾ��ǰϵͳ�еĵ�ͼ������
		 int   GetMapList(int id, int *id_buffer);

		/// ����NaviPack����ʹ�õĵ�ͼ��NaviPack�ĵ�ͼ�б���
		/// @param[in] id NaviPack����ID
		/// @param[out] mapId �����ڵ�ͼ�б��ص�ID
		/// @return ����ֵС��0����ʾʧ��
		 int   SaveCurrentMapToList(int id, int mapId);

		/// ָ��NaviPack����ָ���ĵ�ͼ
		/// @param[in] id NaviPack����ID
		/// @param[in] map_id ָ����ͼ��ID��0~7
		/// @note �󲿷����ͼ��صĺ�������Ҫ�����ͼ�󣬲ſ��Թ�����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   LoadMap(int id, int map_id);

		/// ���û�ȡ��ǰʹ�õĵ�ͼ
		/// @param[in] id NaviPack����ID
		/// @note �����ӳɹ�������Ҫ���±�����ͼʱ�����Ե��øú�����֪ͨNaviPack���ϴ���ͼ
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SetGetCurrentMap(int id);

		/// ���뱾�صĵ�ͼ�ļ���NaviPack
		/// @param[in] id NaviPack����ID
		/// @param[in] local_map_path ���ص�ͼ�ļ�·��
		/// @param[in] map_id ���ñ��ص�ͼ��Ӧ��NaviPack�ϵ�ͼ��ID
		/// @note �ú�������������λ�����صĵ�ͼ�ļ���NaviPack����������NaviPack����ĵ�ͼID��
		/// ���ó�map_idֵ���󲿷����ͼ��صĺ�������Ҫ�����ͼ�󣬲ſ��Թ�����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   LoadLocalMap(int id, const char* local_map_path, int map_id);

		/// ���浱ǰ��NaviPack�����еĵ�ͼ����λ������
		/// @param[in] id NaviPack����ID
		/// @param[in] local_map_path ���ص�ͼ�ļ�·��
		/// @param[in] picture_flag �����ڱ����ͼ�ļ���ͬʱ���Ƿ񽫲�ͬͼ������ݣ�תΪ��Ӧ��bmpͼƬ�ļ���1 ��ʾ���棬0��ʾ������
		/// @note �ú�������ǰNaviPack�����еĵ�ͼ�����浽��λ�����أ��ļ���չ��Ϊ.npmap��ͬʱ�����picture_flag����Ϊ1��
		/// �佫����⽫�����״�����ͼ���Լ�����������ͼ�㱣��Ϊbmp��ʽ��ͼƬ�������û��鿴��
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SaveMapToLocal(int id, const char * local_map_path, int picture_flag);

		/// ��ȡNaviPack������ͼ��ͼ������
		/// @param[in] id NaviPack����ID
		/// @param[out] map_data MapData�ṹ�壬���ڱ����ͼ����
		/// @param[in] map_type ��ͬ�ĵ�ͼ���͡������Ǽ����״�ͼ�㡢������ͼ�㡢��ײͼ��ȣ��Զ���ͼ�㣬���ͼ���
		/// @note ��ͼ���ݣ��ڴ�������н�������ݽ���ѹ����������ѡ��ͬ��map_type�����ز�ͬ�ĵ�ͼ
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   GetMapLayer(int id, AlgMapData *map_data, int map_type);

		/// ����NaviPack��ʹ�õĵ�ͼͼ��
		/// @param[in] id NaviPack����ID
		/// @param[in] map_data MapData�ṹ�壬���ڱ����ͼ����
		/// @param[in] map_type ��ͬ�ĵ�ͼ���͡������Ǽ����״�ͼ�㡢������ͼ�㡢��ײͼ��ȣ��Զ���ͼ�㣬���ͼ���
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SetMapLayer(int id, AlgMapData *map_data, int map_type);

		/// λͼ����ת��ͼͼ��
		/// @param[in] bitmap 8bit �Ҷ�λͼ���ݻ��������䲢��һ����ɵ�bmpͼƬ�ļ�������ͼ���ļ���ʵ�ʵ�ͼ�����ݡ�
		/// @param[in] w λͼ���ݿ��
		/// @param[in] h λͼ���ݸ߶�
		/// @param[out] map ���ɵ�ͼ������
		/// @note Bitmap����Ϊ8λ�Ҷȵ�ͼ���ݣ�128��ʾδ֪��0����ʾ�ϰ��255 ��ʾ�յء��ú����������µ��ڴ棬
		/// ���������󷵻ظ��û����û�ʹ����ɺ���Ҫʹ�������ͷ��ڴ档
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   BitmapToMapLayer(unsigned char *bitmap, AlgMapData **map);

		/// λͼ�ļ�ת��ͼͼ��
		/// @param[in] file_path ���ɵ� 8bit �Ҷ�λͼbmp�ļ�����·����
		/// @param[out] map ͼ�����ݻ�����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   BmpFileToMapLayer(const char * file_path, AlgMapData **map);

		/// ��ͼͼ��תλͼ�ļ�
		/// @param[in] id NaviPack����ID
		/// @param[in] map ͼ�����ݻ�����
		/// @param[in] file_path ���ɵ� 8bit �Ҷ�λͼbmp�ļ�����·����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   MapLayerToBmpFile(AlgMapData *map, char * file_path);

		///��ȡ���ش洢�ĵ�ͼͼ������
		/// @param[in] fileName ͼ�������ļ�
		/// @param[out] map ���ɵ�ͼ������
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   ReadLocalMaplayer(const char* fileName, AlgMapData **map);

		/// ��ȡ������ʵʱ����
		/// @param[in] id NaviPack����ID
		/// @param[in] sensorType ����������
		/// correlative enum sensorType
		/// @param[out] sensor_data SensorData �ṹ�壬���ڴ洢��������������������ݼ�����ȫ��λ��̬
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   GetSensorData(int id, AlgSensorData *sensor_data, int sensorType);

		/// ��ȡϵͳ״̬��Ϣ
		/// @param[in] id NaviPack����ID
		/// @param[out] status StatusRegister �ṹ�壬���ڴ洢����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   GetStatus(int id, AlgStatusRegister *status);

		/// ǿ��NaviPack���½��г�ʼ��λ
		/// @param[in] id NaviPack����ID
		/// @param[out] status StatusRegister �ṹ�壬���ڴ洢����
		/// @note �ù�����ȷִ�е�ǰ���ǣ���ͼ�Ѿ�����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   InitLocation(int id);

		/// ����WIFI����
		/// @param[in] id NaviPack����ID
		/// @param[in] ssid WIFI SSID
		/// @param[in] password WIFI ����
		/// @note ������SSID��WIFI֮��ϵͳ����������TCP/UDP�����������е�Ӳ����Ҫ����USB WIFI �����ſ���ʹ��WIFI���ӣ���
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�
		 int   SetWiFiParam(int id, const char * ssid, const char * password);

		/// ���������е��豸
		/// @param[in] id NaviPack����ID
		/// @param[out] device_list �豸�����б����ڱ����豸�������ƺͲ�����������������ӣ������Ƹ�ʽΪip:port,��192.168.0.2:7896������Ǵ��ڣ���Ϊport:bandrate���� /dev/ttyACM0:115200�����豸����֮�䣬����;������
		/// @param[in] timeout ��ʱֵ
		/// @note device_list���ڴ����û����𴴽������٣�����ڴ��СΪ256�������������ӵ��豸��˵�������ܣ���ͨ������UDP�㲥��ʵ�ֵģ���ˣ���Ҫ���������豸�������豸��ͬһ�����Ρ����ڴ������ӵ��豸��˵����Android/linuxϵͳ���棬������/dev/ttyACM��ͷ�������豸�����������Ӻ�ͨѶ����windowsϵͳ���棬��������������ϵͳ���ڣ����������Ӻ�ͨѶ��
		/// @return ����ֵС��0����ʾʧ�ܣ����ڵ����㣬��ʾ�������ĵ�NaviPack�豸��������
		 int   SearchDevice(int id, char *device_list, int timeout);

		/// ���ͨѶ�Ƿ�����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int   CheckConnection();

		/// ����NaviPack����
		/// @param[in] id NaviPack����ID
		/// @param[in] fileName Ҫ������ļ���
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int   UpdateNaviPackFile(int id, const char* fileName);

		/// �����ɿ����������Զ����Э������
		/// @param[in] id NaviPack����ID
		/// @param[in] fileName Ҫ��������ݻ�����
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int   SetSelfStream(int id, char* buf, int bufLen);

		/// ����NaviPack�����ǰ�ĵ�ͼ�����͵����ر���
		/// @param[in] id NaviPack����ID
		/// @param[in] id filePath Ҫ������ļ���·��
		/// @param[in] id fileName Ҫ������ļ�������
		/// @return ����ֵС��0./N����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int   SetSaveMap(int id, const char* filePath, const char* fileName);

		/// ���ͱ��ص��ļ���NaviPack
		/// @param[in] id		NaviPack����ID
		/// @param[in] type		���͵��ļ�����
		/// @param[in] filePath Ҫ���͵��ļ���·��
		/// @param[in] fileName Ҫ���͵��ļ�������
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int   SendFile(int id, int type, const char* filePath, const char* fileName);

		/// ����NaviPack�׼�������ģʽ
		/// @param[in] id		NaviPack����ID
		/// @param[in] mode		����ģʽ 0 ��ʾĬ��ģʽҲ�ǵ���ģʽ 1 ��ʾ�״�����ת�ķ�ģʽ
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int   SetChangeNaviPackMode(int id, int mode);

		 /// �ֶ�����IMU�Ľ���
		 /// @param[in] id		NaviPack����ID
		 /// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int ImuCalibrate(int id);

		 /// �����Լ��Ĵ��������ݵ�NaviPack
		 /// @param[in] id				NaviPack����ID
		 /// @param[in] sensorData		���������ݵ�ͳһ��ʽ
		 /// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�
		 int SendUnifiedSensorInfo(int id, UnifiedSensorInfo sensorData);
		private:
			void Init();
	};



}

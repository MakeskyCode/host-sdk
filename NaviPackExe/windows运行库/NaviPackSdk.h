#pragma once
#include "SDKProtocol.h"
namespace NaviPackSdk_Cpp {
	class NaviPackSdk
	{
	public:
		NaviPackSdk();
		~NaviPackSdk();


		/// ��õ�ǰSDK�İ汾��    Get the current SDK version number
		/// @return ����NaviPack�����ID    Return the ID of the NaviPack object
		/// @note ����ֵ��3���������: ���汾��(Bits 24 ~31), �Ӱ汾��(Bits 16 ~ 23), �����(Bits 0 ~ 15)    The attribute value consists of three parts: the major version number (Bits 24 ~ 31), the minor version number (Bits 16 ~ 23), the compiled number (Bits 0 ~ 15)
		int  GetSDKVersion();

		/// ��õ�ǰNaviPack�İ汾��    Get the current NaviPack version number
		/// @return ����NaviPack�����ID    Return the ID of the NaviPack object
		/// @note ����ֵ��3���������: ���汾��(Bits 24 ~31), �Ӱ汾��(Bits 16 ~ 23), �����(Bits 0 ~ 15)    The attribute value consists of three parts: the major version number (Bits 24 ~ 31), the minor version number (Bits 16 ~ 23), the compiled number (Bits 0 ~ 15)
		int  SetGetNaviPackVersion(int id);

		/// ����һ��NaviPack����    Create a NaviPack object
		/// @return ����NaviPack�����ID >=0Ϊ�����ɹ�    If return the ID of the NaviPack object is greater than or equal to 0��the creation succeeded 
		int  Create(ConnectType conType);

		/// ����NaviPack����    Destroy the NaviPack object
		/// @param id ������NaviPack�����ID    The ID of the NaviPack object to be destroyed
		void  Destroy(int id);

		/// ��NaviPack���󣬸ú��������ݲ�ͬ�Ĳ������������򿪲�ͬ���豸    Open the NaviPack object, the function will be based on different parameters to decide to open a different device
		/// @param[in] id NaviPack����ID   The ID of the NaviPack object
		/// @param[in] name �ӿ����ƣ������TCP/UDPЭ�飬����д�Է���IP��ַ������Ǵ��ڣ�����д�����豸����, Windows��Ϊ��////.//COM?, Linux��Ϊ/dev/ttyACM?    Interface name, if it is TCP/UDP protocol, then fill in its IP address, if it is serial port, then fill in the serial device name,the serial port in Windows environment is : ////.//COM?, in Linux environment is: /dev/ttyACM?
		/// @param[in] param �ӿڲ����������TCP/UDPЭ�飬����д�Է��Ķ˿ڡ������COM������д�ӿڵĲ����ʡ�    Interface parameters. If it is TCP / UDP protocol, then fill in the its port. If COM, then fill in the interface baud rate.�ر��������ǣ���linuxϵͳ��,ʹ�õĲ�����Ӧ����B115200֮������ͣ���ͷ�ļ�termios.h��
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�   If the return value is less than 0, it means failure,equal to 0 means that success
		int  Open(int id, const char* name, int param);

		/// ���´�֮ǰ���رյ�NaviPack�ӿ�    Reopen the NaviPack interface that was previously closed
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int  Reopen(int id);

		/// �ر�NaviPack�ӿ�    Close the NaviPack interface
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int  Close(int id);


		/// ���ôӷ���˴�����Ϣ���ݵĻص�    Set the Callback for the message data from the server
		/// @param[in] id NaviPack ����ID    The ID of the NaviPack object
		/// @param[in] deviceMsgCb �豸��Ϣ�ص�    Device Nomal message callback
		/// @param[in] errMsgCb	   �豸������Ϣ�ص�    Device error message callback
		/// @param[in] lidarPackCb �״�ԭʼ���ݻص�    The lidar raw data callback
		/// @return  ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int  SetCallback(int id, DeviceMsgCallBack deviceMsgCb, ErrorMsgCallBack errMsgCb, MapPackageCallBack mapPackCb, LidarPackageCallBack lidarPackCb);

		
		/// ��ȡ����Ĳ���    Get the parameters of the carrier (NOT USE)
		/// @param[in] id NaviPack����ID     The ID of the NaviPack object
		/// @param[out] param ����ָ��    Parameter pointer
		/// @note CarrierParam ������NaviPack�������������˶��ٶȣ�������󳤿�NaviPack��װλ�ã�NaviPack��װ������Ϣ��
		///////CarrierParam contains the maximum speed of the carrier, the maximum length of the carrier, the NaviPack install location, NaviPack install orientation.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�   If the return value is less than 0, it means failure,equal to 0 means that success
		int  GetCarrierParam(int id, CarrierParam *param);

		/// ��������Ĳ���    Set the parameters of the carrier
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] param ����ָ��    Parameter pointer
		/// @note CarrierParam ������NaviPack�������������˶��ٶȣ�������󳤿�NaviPack��װλ�ã�NaviPack��װ������Ϣ��
		///////CarrierParam contains the maximum speed of the carrier, the maximum length of the carrier, the NaviPack install location, NaviPack install orientation.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int  SetCarrierParam(int id, CarrierParam *param);

		/// ��ȡNaviPack�Ĳ���    Get the parameters of the NaviPack (NOT USE)
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] param ����ָ��    Parameter pointer
		/// @note NaviPackParam ������NaviPackϵͳ��һЩ������Ϣ�������Ƿ��Զ����µ�ͼ��դ���С��һЩ������
		//////NaviPackParam contains some parameters of the NaviPack system, including whether to automatically update the map, raster size and other parameters
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int  GetNaviPackParam(int id, NaviPackParam *param);

		/// ��������Ĳ���    Set the parameters of the NaviPack (NOT USE)
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] param ����ָ��    Parameter pointer
		/// @note NaviPackParam ������NaviPackϵͳ��һЩ������Ϣ�������Ƿ��Զ����µ�ͼ��դ���С��һЩ������
		//////NaviPackParam contains some parameters of the NaviPack system, including whether to automatically update the map, raster size and other parameters
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetNaviPackParam(int id, NaviPackParam *param); 

		/// ����Ŀ����б� ����һ�����ö��Ŀ��㣬������ɺ�NaviPack�������Զ�����״̬��
		//////Set the target point list,you can set more than one target point.If set is complete, NaviPack will enter the automatic navigation state
		/// ���𲽱����û����õĵ����㡣���˶������У�NaviPack���Զ���ɶ�̬·���滮�ͱ��Ϲ�����
		//////Then step through the navigation points that user set. During the process, the NaviPack will automatically complete the dynamic path planning and barrier work.
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] position_x ·����X���껺���� ��λmm    The path point X coordinate buffer; unit: mm
		/// @param[in] position_y ·����Y���껺���� ��λmm    The path point Y coordinate buffer; unit: mm
		/// @param[in] num ·��������   	Number of the path points			
		/// @param[in] phi �������һ����ĽǶ�		��λ����    The angle to the last point; unit : m arc
		/// @note SetTargets������ֻ����NaviPack��ɶ�λ���������ͼ�󣬲Ż���Ч���ú����Ĳ���λ�ã���ָ��������ϵ�µ�λ����Ϣ��
		//////This function is valid only after the NaviPack has finished locating and loading the map. The function of the parameter position, refers to the world coordinate system under the location information.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetTargets(int id, int position_x[], int position_y[], int num, int phi);

		/// ��ȡ��ǰ�Ѿ����õ�·����    Gets the currently path point that set
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] position_x ·����X���껺����    The path point X coordinate buffer
		/// @param[out] position_y ·����Y���껺����    The path point Y coordinate buffer
		/// @param[out] num ·��������    Number of the path points
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   GetCurrentPath(int id, int position_x[], int position_y[], int* num);

		/// ������������������֮���ת��    The conversion from pixel coordinates to world coordinates (NOT USE)
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] pixel_y ·����X���껺����    The path point X coordinate buffer
		/// @param[in] pixel_y ·����Y���껺����    The path point Y coordinate buffer
		/// @param[out] position_x ·��������    Number of the path points X
		/// @param[out] position_y ·��������    Number of the path points Y
		/// @note �ú������ڽ���ͼ���������꣬ת��Ϊ��������ϵ����    This function is used to convert the pixel coordinates of the map to world coordinate 
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int PixelToPosition(int id, int pixel_x, int pixel_y, int *position_x, int *position_y);

		/// ������������������֮���ת��    The conversion from world coordinates to pixel coordinates (NOT USE)
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] pixel_y ·����X���껺����    The path point X coordinate buffer
		/// @param[out] pixel_y ·����Y���껺����    The path point Y coordinate buffer
		/// @param[in] position_x ·��������    Number of the path points X
		/// @param[in] position_y ·��������    Number of the path points Y
		/// @note �ú������ڽ���ͼ���������꣬ת��Ϊ��������ϵ����    This function is used to convert the world coordinates of the map to pixel coordinate
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   PositionToPixel(int id, int position_x, int position_y, int *pixel_x, int *pixel_y);

		/// �����豸�������ٶ�v�����ٶ�w�˶���    control device move; linear speed: v; angular speed: w 
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] v Ŀ�����ٶ�    Target linear speed
		/// @param[in] w Ŀ����ٶ�    Target angular speed
		/// @note �ú���������ֱ�ӿ����豸���˶�������豸��ǰ���ڴ����Զ�����״̬������˳��Զ�����״̬������������ֶ�ң�ء�
		//////This function will directly control the movement of the device. If the device is currently in an auto-navigation state, the auto-navigation state is exited. It can be used for manual remote control.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetSpeed(int id, int v, int w);

		/// ����NaviPack�����Զ��س�״̬    Controls the NaviPack to enter the auto-recharge state
		/// @param[in] id NaviPack����ID     The ID of the NaviPack object
		/// @note �豸�յ�������󣬽��Զ�����س�״̬��NaviPack�����������Զ��˶������׮λ�ã�
		//////After the device receives the command, it will enter the auto-recharge state, NaviPack will control the carrier automatically moves to the charging pile position,
		/// ����׼�豸�Ӵ���硣�ú���Ҫ��������λ���Ѿ�ͨ�� SetChargerPosition ���ã����������������й���磨���ʱ�����׮��λ�ã������Զ�����¼��
		//////And align the device and then contact and charge. This function requires that the location of the cradle has been set by the function SetChargerPosition, or that the carrier has been charged (the position of the charging pile will be automatically recorded when charging)
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		/// @see SetChargerPosition
		int   AutoCharge(int id);

		/// ���ó��׮��λ��    Set the position of the charging pile  (NOT USE)
		/// @param[in] id NaviPack����ID   The ID of the NaviPack object
		/// @param[in] param ����ָ��    Parameter pointer
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetChargerPosition(int id, int position_x, int position_y);

		/// ���뽨ͼģʽ    Start the mapping mode
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] mappingMode ��ͼģʽ��0 ��ʾ �ֶ���ͼ��1 ��ʾ�Զ���ͼ    Mapping mode, 0 for manual mapping, 1 for automatic mapping
		/// @note �ú������ڶԻ������н�ͼ����ѡ���ֶ���ͼʱ����������˶�������λ����������ѡ���Զ���ͼʱ��
		//////This function is used to map the environment. When you choose to manually mapping, the carrier will be controlled by the host computer.
		/// ������˶�����NaviPack�Զ����ƣ�NaviPack���Զ����������������������
		//////When you choose to automatically map, the carrier will automatic control by the NaviPack, NaviPack will automatically control the carrier traverses the whole environment.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   StartMapping(int id, int mappingMode = 0);

		/// �˳���ͼģʽ    Exit the mapping mode
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] save_flag �Ƿ񱣴��ͼ    Whether to save the map
		/// :-1,�����棬֧��0~7��ͼ�ļ��б�ţ�Ĭ�ϵ�ͼ������0�ŵ�ͼ�ļ�����    
		//////-1, not saved, support map folder number 0 ~ 7, the default map stored in the map folder 0
		/// @note �˳���ͼģʽ��ϵͳ����IDLE״̬���ú����Ľ�ֹͣ��ͼ��������save_flag��ֵ���������Ƿ񽫵�ǰ����֮��ͼ��
		//////After exiting the mapping mode, the system enters the IDLE state. The function will stop mapping, and according to the value of save_flag to decide whether to save the current mapthat built,
		/// ����������ϵͳ�У�����ܹ��洢8����ͼ�������Ĳ��֣����ᱻ�µĵ�ͼ���ǡ�
		//////The system will store up to 8 maps, and the overriding portion will be overwritten by the new map
		/// @return ����ֵС��0����ʾʧ�ܣ����ڵ����㣬��ʾ��ͼ�ɹ�������ֵ����ʾ��ǰ�ĵ�ͼ����ID����δ���棬�ҳɹ����򷵻�0��
		//////If the return value is less than 0, it means failure. If it is greater than or equal to 0, it means that the mapping is successful. The return value means the ID of the current saving map . If it is not saved and successful, it returnes 0.
		int   StopMapping(int id, int save_flag = 0);

		/// ��ȡNaviPack�еĵ�ͼ�б�    Get the list of maps in the NaviPack (NOT USE)
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] id_buffer ���ڴ�ŵ�ͼID�Ļ��������û��������Ϊ8����    The buffer used to hold the map ID. The maximum number of buffers is eight.
		/// @note �ú�������ȡϵͳ�б�������еĵ�ͼID��    This function will get the ID of all saved maps in the system
		/// @return ����ֵС��0����ʾʧ�ܣ����ڻ�����㣬��ʾ��ǰϵͳ�еĵ�ͼ������    
		//////If the return value is less than 0, it means failure, if it is greater than or equal to zero, it means the current number of maps in the system.
		int   GetMapList(int id, int *id_buffer);

		/// ����NaviPack����ʹ�õĵ�ͼ��NaviPack�ĵ�ͼ�б���    Save the map that are using to the NaviPack map list
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] mapId �����ڵ�ͼ�б��ص�ID    The ID that is saved in the map list 
		/// @return ����ֵС��0����ʾʧ��    If the return value is less than 0, it means failure
		int   SaveCurrentMapToList(int id, int mapId); (NOT USE)

		/// ָ��NaviPack����ָ���ĵ�ͼ    Load the specified map (NOT USE)
		/// @param[in] id NaviPack����ID     The ID of the NaviPack object
		/// @param[in] map_id ָ����ͼ��ID��0~7    The ID of the specified map: 0~7
		/// @note �󲿷����ͼ��صĺ�������Ҫ�����ͼ�󣬲ſ��Թ�����    Most of the map-related functions need to load the map before they can work
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�     If the return value is less than 0, it means failure,equal to 0 means that success
		int   LoadMap(int id, int map_id);

		/// ���û�ȡ��ǰʹ�õĵ�ͼ    Set to get the current map
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @note �����ӳɹ�������Ҫ���±�����ͼʱ�����Ե��øú�����֪ͨNaviPack���ϴ���ͼ
		//////when connect succeed or when you want to update the native map,you can calle this function to notify the NaviPack to upload a map 
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetGetCurrentMap(int id);

		/// ���뱾�صĵ�ͼ�ļ���NaviPack    Load the local map file to the NaviPack
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] local_map_path ���ص�ͼ�ļ�·��    The local map file path
		/// @param[in] map_id ���ñ��ص�ͼ��Ӧ��NaviPack�ϵ�ͼ��ID   Sets the ID of the map on the NaviPack that corresponds to the local map 
		/// @note �ú�������������λ�����صĵ�ͼ�ļ���NaviPack����������NaviPack����ĵ�ͼID��
		//////This function is used to download the local host computer's  map file to the NaviPack and set its map ID in the NaviPack to the map_id value.
		/// ���ó�map_idֵ���󲿷����ͼ��صĺ�������Ҫ�����ͼ�󣬲ſ��Թ�����
		//////Most of the map-related functions need to load the map before they can work
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�     If the return value is less than 0, it means failure,equal to 0 means that success
		int   LoadLocalMap(int id, const char* local_map_path, int map_id);

		/// ���浱ǰ��NaviPack�����еĵ�ͼ����λ������    Save the map that the NaviPack running to the local host computer (NOT USE)
		/// @param[in] id NaviPack����ID     The ID of the NaviPack object
		/// @param[in] local_map_path ���ص�ͼ�ļ�·��    The local map file path
		/// @param[in] picture_flag �����ڱ����ͼ�ļ���ͬʱ���Ƿ񽫲�ͬͼ������ݣ�תΪ��Ӧ��bmpͼƬ�ļ���1 ��ʾ���棬0��ʾ������
		//////Decide whether to save the data of different layers into the corresponding bmp picture file when saving the map file. 1 for saving, 0 for not saving
		/// @note �ú�������ǰNaviPack�����еĵ�ͼ�����浽��λ�����أ��ļ���չ��Ϊ.npmap��ͬʱ�����picture_flag����Ϊ1��
		//////This function will save NaviPack's currently running map to local host computer with file extension .npmap. At the same time, if the picture_flag is 
		/// �佫����⽫�����״�����ͼ���Լ�����������ͼ�㱣��Ϊbmp��ʽ��ͼƬ�������û��鿴��
		//////set to 1, it will save the lidar data layer and the ultrasonic data layer as pictures in bmp format for users to view.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SaveMapToLocal(int id, const char * local_map_path, int picture_flag);

		/// ��ȡNaviPack������ͼ��ͼ������    Get the NaviPack map data
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] map_data MapData�ṹ�壬���ڱ����ͼ����    MapData structure, used to save the map data
		/// @param[in] map_type ��ͬ�ĵ�ͼ���͡������Ǽ����״�ͼ�㡢������ͼ�㡢��ײͼ��ȣ��Զ���ͼ�㣬���ͼ���
		//////Different map types. It can be a lidar layer, an ultrasonic layer, a collision layer, a custom layer, a combination layer, etc.
		/// @note ��ͼ���ݣ��ڴ�������н�������ݽ���ѹ����������ѡ��ͬ��map_type�����ز�ͬ�ĵ�ͼ
		//////Map data will be compressed during the transfer, you can choose a different map_type, return to a different map
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   GetMapLayer(int id, AlgMapData *map_data, int map_type);

		/// ����NaviPack��ʹ�õĵ�ͼͼ��    Update the map layer used by NaviPack
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] map_data MapData�ṹ�壬���ڱ����ͼ����    MapData structure, used to save the map data
		/// @param[in] map_type ��ͬ�ĵ�ͼ���͡������Ǽ����״�ͼ�㡢������ͼ�㡢��ײͼ��ȣ��Զ���ͼ�㣬���ͼ���
		////////////Different map types. It can be a lidar layer, an ultrasonic layer, a collision layer, a custom layer, a combination layer, etc.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetMapLayer(int id, AlgMapData *map_data, int map_type);

		/// λͼ����ת��ͼͼ��    Bitmap data to map layer (NOT USE)
		/// @param[in] bitmap 8bit �Ҷ�λͼ���ݻ��������䲢��һ����ɵ�bmpͼƬ�ļ�������ͼ���ļ���ʵ�ʵ�ͼ�����ݡ�
		//////8bit grayscale bitmap data buffer, which is not a complete bmp picture file, but the actual image file image data
		/// @param[in] w λͼ���ݿ��   The bitmap data width
		/// @param[in] h λͼ���ݸ߶�   The bitmap data height 
		/// @param[out] map ���ɵ�ͼ������    The generated layer data
		/// @note Bitmap����Ϊ8λ�Ҷȵ�ͼ���ݣ�128��ʾδ֪��0����ʾ�ϰ��255 ��ʾ�յء��ú����������µ��ڴ棬
		/////Bitmap data is 8-bit grayscale map data, 128 is unknown, 0 is an obstacle, and 255 is open space.The function apply for new memory, 
		/// ���������󷵻ظ��û����û�ʹ����ɺ���Ҫʹ�������ͷ��ڴ档
		//////and fill it back to the user, the user is finished, you need to use the active release memory.
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   BitmapToMapLayer(unsigned char *bitmap, AlgMapData **map);

		/// λͼ�ļ�ת��ͼͼ��    Bitmap file to map layer (NOT USE)
		/// @param[in] file_path ���ɵ� 8bit �Ҷ�λͼbmp�ļ�����·����   The resulting 8bit bitmap file path
		/// @param[out] map ͼ�����ݻ�����    Layer data buffer
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   BmpFileToMapLayer(const char * file_path, AlgMapData **map);

		/// ��ͼͼ��תλͼ�ļ�    Map layer to the map file (NOT USE)
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] map ͼ�����ݻ�����    Layer data buffer
		/// @param[in] file_path ���ɵ� 8bit �Ҷ�λͼbmp�ļ�����·����    The resulting 8bit bitmap file path
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   MapLayerToBmpFile(AlgMapData *map, char * file_path);

		///��ȡ���ش洢�ĵ�ͼͼ������    Read the local map layer data   (NOT USE)
		/// @param[in] fileName ͼ�������ļ�    The layer data file
		/// @param[out] map ���ɵ�ͼ������    The generated layer data
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   ReadLocalMaplayer(const char* fileName, AlgMapData **map);

		/// ��ȡ������ʵʱ����    Get sensor real-time data
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] sensorType ����������    the sensor type
		/// correlative enum sensorType
		/// @param[out] sensor_data SensorData �ṹ�壬���ڴ洢��������������������ݼ�����ȫ��λ��̬
		//////SensorData structure, used to store the sensor relative to the carrier coordinate data and carrier global position pose
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   GetSensorData(int id, AlgSensorData *sensor_data, int sensorType);

		/// ��ȡϵͳ״̬��Ϣ    Get the system status
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] status StatusRegister �ṹ�壬���ڴ洢����    StatusRegister structure,used to store data
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   GetStatus(int id, AlgStatusRegister *status);

		/// ǿ��NaviPack���½��г�ʼ��λ    Force NaviPack to re-initialize
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] status StatusRegister �ṹ�壬���ڴ洢����    StatusRegister structure,used to store data
		/// @note �ù�����ȷִ�е�ǰ���ǣ���ͼ�Ѿ�����    This function works correctly if the map is already loaded
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   InitLocation(int id);

		/// ����WIFI����     Set the WIFI parameter 
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] ssid WIFI SSID    
		/// @param[in] password WIFI ����   WIFI password
		/// @note ������SSID��WIFI֮��ϵͳ����������TCP/UDP�����������е�Ӳ����Ҫ����USB WIFI �����ſ���ʹ��WIFI���ӣ���
		//////After set the SSID and WIFI, the system will automatically establish a TCP/UDP server (the existing hardware need to insert a USB WIFI card)
		/// @return ����ֵС��0����ʾʧ�ܣ�����0 ��ʾ�ɹ�   If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetWiFiParam(int id, const char * ssid, const char * password);

		/// ���������е��豸    Search the devices on the network
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[out] device_list �豸�����б����ڱ����豸�������ƺͲ�����������������ӣ������Ƹ�ʽΪip:port,��192.168.0.2:7896������Ǵ��ڣ���Ϊport:bandrate���� /dev/ttyACM0:115200�����豸����֮�䣬����;������
		//////Device name list,it used to save the device connection name and parameters, if the network connection, the name format is ip: port, such as 192.168.0.2:7896, if it is a serial port, the port: bandrate, such as /dev/ttyACM0:115200 . Between the device names, use;separated.
		/// @param[in] timeout ��ʱֵ   
		/// @note device_list���ڴ����û����𴴽������٣�����ڴ��СΪ256�������������ӵ��豸��˵�������ܣ���ͨ������UDP�㲥��ʵ�ֵģ���ˣ���Ҫ���������豸�������豸��ͬһ�����Ρ����ڴ������ӵ��豸��˵����Android/linuxϵͳ���棬������/dev/ttyACM��ͷ�������豸�����������Ӻ�ͨѶ����windowsϵͳ���棬��������������ϵͳ���ڣ����������Ӻ�ͨѶ��
		//////The memory for device_list is created and destroyed by the user, with a maximum memory size of 256. For a network-connected device, this function is achieved by sending UDP broadcasts. Therefore, the device to be searched and the search device need to be in the same network segment.
		//////For the device connected to the serial port, in the Android / linux system, which will search /dev/ttyACM at the beginning of all the equipment and try to connect and communicate. In the windows system it will automatically search all system serial port and try to connect and communicate. 
		/// @return ����ֵС��0����ʾʧ�ܣ����ڵ����㣬��ʾ�������ĵ�NaviPack�豸��������     If the return value is less than 0, it means failure,If it is greater than or equal to 0, it means the number of NaviPack devices searched.
		int   SearchDevice(int id, char *device_list, int timeout);

		/// ���ͨѶ�Ƿ�����    Check the connection (NOT USE)
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   CheckConnection();

		/// ����NaviPack����    Upgrade the NaviPack program
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] fileName Ҫ������ļ���    The name of the file to transfer
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�     If the return value is less than 0, it means failure,equal to 0 means that success
		int   UpdateNaviPackFile(int id, const char* fileName);

		/// �����ɿ����������Զ����Э������    Set the self protocol data  by the controller manufacturer
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] fileName Ҫ��������ݻ�����    The data buffer to transfer
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�    If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetSelfStream(int id, char* buf, int bufLen);

		/// ����NaviPack�����ǰ�ĵ�ͼ�����͵����ر���    Set the NaviPack to save the current map and send it to the local
		/// @param[in] id NaviPack����ID    The ID of the NaviPack object
		/// @param[in] id filePath Ҫ������ļ���·��    The path to the file to be saved
		/// @param[in] id fileName Ҫ������ļ�������    The name of the file to be saved
		/// @return ����ֵС��0./N����ʾʧ�ܣ�����0��ʾ�ɹ�     If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetSaveMap(int id, const char* filePath, const char* fileName);

		/// ���ͱ��ص��ļ���NaviPack    Send local files to NaviPack
		/// @param[in] id		NaviPack����ID    The ID of the NaviPack object
		/// @param[in] type		���͵��ļ�����    Send the file type
		/// @param[in] filePath Ҫ���͵��ļ���·��   The path to the file to send
		/// @param[in] fileName Ҫ���͵��ļ�������   The name of the file to send
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�     If the return value is less than 0, it means failure,equal to 0 means that success
		int   SendFile(int id, int type, const char* filePath, const char* fileName);

		/// ����NaviPack�׼�������ģʽ    Change the operating mode of the NaviPack 
		/// @param[in] id		NaviPack����ID    The ID of the NaviPack object
		/// @param[in] mode		����ģʽ 0 ��ʾĬ��ģʽҲ�ǵ���ģʽ 1 ��ʾ�״�����ת�ķ�ģʽ 
		//////Operation mode .0 means that the default mode, that is, navigation mode. 1 means that the radar data transmission mode
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�     If the return value is less than 0, it means failure,equal to 0 means that success
		int   SetChangeNaviPackMode(int id, int mode);

		/// �ֶ�����IMU�Ľ���    Manual IMU calibration    
		/// @param[in] id		NaviPack����ID        The ID of the NaviPack object
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�         If the return value is less than 0, it means failure,equal to 0 means that success
		int ImuCalibrate(int id);

		/// �����Լ��Ĵ��������ݵ�NaviPack    Send your own sensor data to the NaviPack
		/// @param[in] id				NaviPack����ID        The ID of the NaviPack object
		/// @param[in] sensorData		���������ݵ�ͳһ��ʽ    A unified format for sensor data
		/// @return ����ֵС��0����ʾʧ�ܣ�����0��ʾ�ɹ�     If the return value is less than 0, it means failure,equal to 0 means that success    
		int SendUnifiedSensorInfo(int id, UnifiedSensorInfo sensorData);
	private:
		void Init();
	};



}
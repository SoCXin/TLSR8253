
echo ���� ble_remote ���̺��ֹ����� lib_gen.bat�Ὣ�ʵ��� .o �ļ������ .a

rm -f ./proj_lib/liblt_8258.a 
find ./8258_ble_remote/drivers -name 'pm.o' -type f -print -exec tc32-elf-ar -r ./proj_lib/liblt_8258.a {} ;
find ./8258_ble_remote/drivers -name 'pm_32k_rc.o' -type f -print -exec tc32-elf-ar -r ./proj_lib/liblt_8258.a {} ;
find ./8258_ble_remote/drivers -name 'pm_32k_xtal.o' -type f -print -exec tc32-elf-ar -r ./proj_lib/liblt_8258.a  {} ;
find ./8258_ble_remote/drivers -name 'rf_drv.o' -type f -print -exec tc32-elf-ar -r ./proj_lib/liblt_8258.a {} ;
find ./8258_ble_remote/drivers -name 'random.o' -type f -print -exec tc32-elf-ar -r ./proj_lib/liblt_8258.a {} ;
find ./8258_ble_remote/stack -name '*.o' -type f -print -exec tc32-elf-ar -r ./proj_lib/liblt_8258.a {} ; 


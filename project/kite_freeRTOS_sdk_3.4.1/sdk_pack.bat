
echo SDK ������ߣ���ǰҪ��֤ .a �ļ��Ѿ�������¡��������� lib_gen.bat

rm -f ./sdk_release/8258_sdk.rar
find ./ -type f -not -path "./8258_ble_remote/*" -not -path "./sdk_release/*"  -not -path "./stack/*.c" -not -name "pm.c" -not -name "pm_32k_rc.c" -not -name "pm_32k_xtal.c" -not -name "rf_drv.c" -not -name "./random.c" -exec "C:\Program Files\WinRAR\rar.exe" a ./sdk_release/8258_sdk.rar {} ;


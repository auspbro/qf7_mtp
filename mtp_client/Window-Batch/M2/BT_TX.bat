@echo on

set loss_rssi=%1%
echo loss_value=%loss_rssi%

set RETARY=0
set MAX_RETRY=3

cd C:\Testprogram\QF7\M2

set logfile="C:\Testprogram\QF7\M2\LOG\BTMAC_READ.txt"
set BTMAC_READ_LOG="C:\Testprogram\QF7\M2\LOG\BTMAC_READ_LOG.bat"
set BLE112_result="C:\Testprogram\QF7\M2\BT_RSSI\result_scan.txt"
set Compare_BLE112_BTMAC="C:\Testprogram\QF7\M2\BT_RSSI\BT_MAC_RSSI.txt"
set PASS_logfile="C:\Testprogram\QF7\M2\PASS_LOG\BT_TX_LOG.bat"
set BT_TX_RSSI_LOG="C:\Testprogram\QF7\M2\LOG\BT_TX_RSSI_LOG.bat"
if exist %logfile% del %logfile%
if exist %BTMAC_READ_LOG% del %BTMAC_READ_LOG%
if exist %BLE112_result% del %BLE112_result%
if exist %Compare_BLE112_BTMAC% del %Compare_BLE112_BTMAC%
if exist %PASS_logfile% del %PASS_logfile%
if exist %BT_TX_RSSI_LOG% del %BT_TX_RSSI_LOG%

echo QF7 BT MAC Read
call Window-Client.exe BTMAC_READ > C:\Testprogram\QF7\M2\LOG\BTMAC_READ.txt

findstr Set C:\Testprogram\QF7\M2\LOG\BTMAC_READ.txt >> C:\Testprogram\QF7\M2\LOG\BTMAC_READ_LOG.bat

if "%ERRORLEVEL%"=="0" (echo Read BTMAC from QF7) else ( goto Read_BTMAC_FAIL	 )
timeout /t 1

call C:\Testprogram\QF7\M2\LOG\BTMAC_READ_LOG.bat


set BT_MAC=%BTMAC_READ%

echo QF7 BT MAC address=%BT_MAC%


timeout /t 1

rem cd C:\Testprogram\QF7\M2\BT_RSSI

echo BLE112 Scan BT device start


:BLE112_Scan

if exist %BLE112_result% del %BLE112_result%
if exist %Compare_BLE112_BTMAC% del %Compare_BLE112_BTMAC%
if exist %BT_TX_RSSI_LOG% del %BT_TX_RSSI_LOG%
timeout /t 1
call C:\Testprogram\QF7\M2\BT_RSSI\BLED112.exe com53 f >> C:\Testprogram\QF7\M2\BT_RSSI\result_scan.txt

timeout /t 6
set BT_MAC_tmp1=%BT_MAC:~0,2%
set BT_MAC_tmp2=%BT_MAC:~2,2%
set BT_MAC_tmp3=%BT_MAC:~4,2%
set BT_MAC_tmp4=%BT_MAC:~6,2%
set BT_MAC_tmp5=%BT_MAC:~8,2%
set BT_MAC_tmp6=%BT_MAC:~10,2%

set BT_MAC_tmp="%BT_MAC_tmp1%:%BT_MAC_tmp2%:%BT_MAC_tmp3%:%BT_MAC_tmp4%:%BT_MAC_tmp5%:%BT_MAC_tmp6%"
echo QF7 BT mac=%BT_MAC_tmp%

find /i "%BT_MAC_tmp1%:%BT_MAC_tmp2%:%BT_MAC_tmp3%:%BT_MAC_tmp4%:%BT_MAC_tmp5%:%BT_MAC_tmp6%" C:\Testprogram\QF7\M2\BT_RSSI\result_scan.txt >> C:\Testprogram\QF7\M2\BT_RSSI\BT_MAC_RSSI.txt
if "%ERRORLEVEL%"=="0" (echo Find BTMAC in BLE112 Result Log) else ( goto retry	 )

timeout /t 1

for /f "usebackq tokens=1-2 delims=	" %%a in (C:\Testprogram\QF7\M2\BT_RSSI\BT_MAC_RSSI.txt) do (set rssi_value=%%b)

echo set BT_RSSI_VALUE=%rssi_value% >>C:\Testprogram\QF7\M2\LOG\BT_TX_RSSI_LOG.bat

if "%rssi_value%" lss "%loss_rssi%" (echo set Result=PASS >C:\Testprogram\QF7\M2\PASS_LOG\BT_TX_LOG.bat) else (echo set Result=FAIL >>C:\Testprogram\QF7\M2\PASS_LOG\BT_TX_LOG.bat)
goto end

:retry

set /A RETARY=%RETARY%+1
if "%RETARY%" lss "%MAX_RETRY%" (goto BLE112_Scan) else (goto Compare_MAC_FAIL)

:Compare_MAC_FAIL
echo Compare_BLE112 LOG FAIL
goto end

:Read_BTMAC_FAIL

echo Read BTMAC FAIL From QF7
goto end

:end

pause

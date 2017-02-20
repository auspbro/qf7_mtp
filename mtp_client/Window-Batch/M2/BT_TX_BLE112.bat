@echo on

set loss_rssi=%1%
echo loss_value=%loss_rssi%
set F_N=M2
set high_rssi=%2%
echo high_value=%high_rssi%

set RETARY_L=0
set RETARY_H=0
set MAX_RETRY=3

cd C:\Testprogram\QF7\%F_N%

set logfile="C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ.txt"
set BTMAC_READ_LOG="C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ_LOG.bat"
set BLE112_result="C:\Testprogram\QF7\%F_N%\BT_RSSI\result_scan.txt"
set Compare_BLE112_BTMAC="C:\Testprogram\QF7\%F_N%\BT_RSSI\BT_MAC_RSSI.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_LOG.bat"
set BT_TX_RSSI_LOW_LOG="C:\Testprogram\QF7\%F_N%\LOG\BT_TX_RSSI_LOW_LOG.bat"
set BT_TX_RSSI_HIGH_LOG="C:\Testprogram\QF7\%F_N%\LOG\BT_TX_RSSI_HIGH_LOG.bat"
set BT_HIGH_PWR_LOG="C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_HIGH_PWR.bat"
set BT_LOW_PWR_LOG="C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_LOW_PWR.bat"
set BT_HIGH_PWR_txt="C:\Testprogram\QF7\%F_N%\LOG\BT_HIGH_PWR.txt"
set BT_LOW_PWR_txt="C:\Testprogram\QF7\%F_N%\LOG\BT_LOW_PWR.txt"
if exist %logfile% del %logfile%
if exist %BTMAC_READ_LOG% del %BTMAC_READ_LOG%
if exist %BLE112_result% del %BLE112_result%
if exist %Compare_BLE112_BTMAC% del %Compare_BLE112_BTMAC%
if exist %PASS_logfile% del %PASS_logfile%
if exist %BT_TX_RSSI_LOW_LOG% del %BT_TX_RSSI_LOW_LOG%
if exist %BT_TX_RSSI_HIGH_LOG% del %BT_TX_RSSI_HIGH_LOG%
if exist %BT_HIGH_PWR_LOG% del %BT_HIGH_PWR_LOG%
if exist %BT_LOW_PWR_LOG% del %BT_LOW_PWR_LOG%
if exist %BT_HIGH_PWR_txt% del %BT_HIGH_PWR_txt%
if exist %BT_LOW_PWR_txt% del %BT_LOW_PWR_txt%
echo QF7 BT MAC Read
call Window-Client.exe BTMAC_READ > C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ.txt >> C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ_LOG.bat

if "%ERRORLEVEL%"=="0" (echo Read BTMAC from QF7) else ( goto Read_BTMAC_FAIL	 )
timeout /t 1

call C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ_LOG.bat
call Window-Client.exe BT_DEVICE

set BT_MAC=%BTMAC_READ%

echo QF7 BT MAC address=%BT_MAC%


timeout /t 1

rem cd C:\Testprogram\QF7\%F_N%\BT_RSSI

echo BLE112 Scan BT device start

:BT_LOW_POWER
if exist %BT_LOW_PWR_LOG% del %BT_LOW_PWR_LOG%
if exist %BT_LOW_PWR_txt% del %BT_LOW_PWR_txt%
call Window-Client.exe BT_LOW_PWR > C:\Testprogram\QF7\%F_N%\LOG\BT_LOW_PWR.txt
findstr Set C:\Testprogram\QF7\%F_N%\LOG\BT_LOW_PWR.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_LOW_PWR.bat
timeout /t 6
goto BLE112_Scan_low




:BLE112_Scan_low
if exist %BLE112_result% del %BLE112_result%
if exist %Compare_BLE112_BTMAC% del %Compare_BLE112_BTMAC%
if exist %BT_TX_RSSI_LOW_LOG% del %BT_TX_RSSI_LOW_LOG%
timeout /t 1
call C:\Testprogram\QF7\%F_N%\BT_RSSI\BLED112.exe com53 f >> C:\Testprogram\QF7\%F_N%\BT_RSSI\result_scan.txt

timeout /t 1
set BT_MAC_tmp1=%BT_MAC:~0,2%
set BT_MAC_tmp2=%BT_MAC:~2,2%
set BT_MAC_tmp3=%BT_MAC:~4,2%
set BT_MAC_tmp4=%BT_MAC:~6,2%
set BT_MAC_tmp5=%BT_MAC:~8,2%
set BT_MAC_tmp6=%BT_MAC:~10,2%

set BT_MAC_tmp="%BT_MAC_tmp1%:%BT_MAC_tmp2%:%BT_MAC_tmp3%:%BT_MAC_tmp4%:%BT_MAC_tmp5%:%BT_MAC_tmp6%"
echo QF7 BT mac=%BT_MAC_tmp%

find /i "%BT_MAC_tmp1%:%BT_MAC_tmp2%:%BT_MAC_tmp3%:%BT_MAC_tmp4%:%BT_MAC_tmp5%:%BT_MAC_tmp6%" C:\Testprogram\QF7\%F_N%\BT_RSSI\result_scan.txt >> C:\Testprogram\QF7\%F_N%\BT_RSSI\BT_MAC_RSSI.txt
if "%ERRORLEVEL%"=="0" (echo Find BTMAC in BLE112 Result Log) else ( goto retry_low	 )

timeout /t 1

for /f "usebackq tokens=1-2 delims=	" %%a in (C:\Testprogram\QF7\%F_N%\BT_RSSI\BT_MAC_RSSI.txt) do (set rssi_value=%%b)

echo set BT_LOW_RSSI_VALUE=%rssi_value% >>C:\Testprogram\QF7\%F_N%\LOG\BT_TX_RSSI_LOW_LOG.bat

if "%rssi_value%" lss "%loss_rssi%" (echo set BT_TX_LOW=PASS >C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_LOW_LOG.bat) else (echo set BT_TX_LOW=FAIL >>C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_LOW_LOG.bat)
goto BT_HIGH_POWER

:BT_HIGH_POWER
if exist %BT_HIGH_PWR_LOG% del %BT_HIGH_PWR_LOG%
if exist %BT_HIGH_PWR_txt% del %BT_HIGH_PWR_txt%

call Window-Client.exe BT_HIGHT_PWR > C:\Testprogram\QF7\%F_N%\LOG\BT_HIGH_PWR.txt
findstr Set C:\Testprogram\QF7\%F_N%\LOG\BT_HIGH_PWR.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_HIGH_PWR.bat
timeout /t 6
goto BLE112_Scan_high

:BLE112_Scan_high
if exist %BLE112_result% del %BLE112_result%
if exist %Compare_BLE112_BTMAC% del %Compare_BLE112_BTMAC%
if exist %BT_TX_RSSI_HIGH_LOG% del %BT_TX_RSSI_HIGH_LOG%
timeout /t 1
call C:\Testprogram\QF7\%F_N%\BT_RSSI\BLED112.exe com53 f >> C:\Testprogram\QF7\%F_N%\BT_RSSI\result_scan.txt

timeout /t 1
set BT_MAC_tmp1=%BT_MAC:~0,2%
set BT_MAC_tmp2=%BT_MAC:~2,2%
set BT_MAC_tmp3=%BT_MAC:~4,2%
set BT_MAC_tmp4=%BT_MAC:~6,2%
set BT_MAC_tmp5=%BT_MAC:~8,2%
set BT_MAC_tmp6=%BT_MAC:~10,2%

set BT_MAC_tmp="%BT_MAC_tmp1%:%BT_MAC_tmp2%:%BT_MAC_tmp3%:%BT_MAC_tmp4%:%BT_MAC_tmp5%:%BT_MAC_tmp6%"
echo QF7 BT mac=%BT_MAC_tmp%

find /i "%BT_MAC_tmp1%:%BT_MAC_tmp2%:%BT_MAC_tmp3%:%BT_MAC_tmp4%:%BT_MAC_tmp5%:%BT_MAC_tmp6%" C:\Testprogram\QF7\%F_N%\BT_RSSI\result_scan.txt >> C:\Testprogram\QF7\%F_N%\BT_RSSI\BT_MAC_RSSI.txt
if "%ERRORLEVEL%"=="0" (echo Find BTMAC in BLE112 Result Log) else ( goto retry_high	 )

timeout /t 1

for /f "usebackq tokens=1-2 delims=	" %%a in (C:\Testprogram\QF7\%F_N%\BT_RSSI\BT_MAC_RSSI.txt) do (set rssi_value=%%b)

echo set BT_HIGH_RSSI_VALUE=%rssi_value% >>C:\Testprogram\QF7\%F_N%\LOG\BT_TX_RSSI_HIGH_LOG.bat

if "%rssi_value%" lss "%high_rssi%" (echo set BT_TX_HIGH=PASS >C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_HIGH_LOG.bat) else (echo set BT_TX_HIGH=FAIL >>C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_HIGH_LOG.bat)
goto end

:retry_low

set /A RETARY_L=%RETARY_L%+1
if "%RETARY_L%" lss "%MAX_RETRY%" (goto BLE112_Scan_low) else (goto Compare_MAC_FAIL)

:retry_high

set /A RETARY_H=%RETARY_H%+1
if "%RETARY_H%" lss "%MAX_RETRY%" (goto BLE112_Scan_high) else (goto Compare_MAC_FAIL)

:Compare_MAC_FAIL
echo Compare_BLE112 LOG FAIL
goto end

:Read_BTMAC_FAIL

echo Read BTMAC FAIL From QF7
goto end

:end



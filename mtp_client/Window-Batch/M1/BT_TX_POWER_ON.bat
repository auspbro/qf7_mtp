@echo off

set F_N=M1
echo QF7 BT TX ON


cd C:\Testprogram\QF7\%F_N%

set logfile_BT_TX_ON="C:\Testprogram\QF7\%F_N%\LOG\BT_TX_ON.txt"
set PASS_logfile_SET_BT_TX_ON="C:\Testprogram\QF7\%F_N%\PASS_LOG\SET_BT_TX_ON_LOG.bat"
set PASS_logfile_BT_TX="C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_LOG.bat"

if exist %logfile_BT_TX_ON% del %logfile_BT_TX_ON%
if exist %PASS_logfile_SET_BT_TX_ON% del %PASS_logfile_SET_BT_TX_ON%
if exist %PASS_logfile_BT_TX% del %PASS_logfile_BT_TX%

set BT_Level=%1%
echo BT Level=%BT_Level%

call Window-Client.exe BTPWR_ON >> C:\Testprogram\QF7\%F_N%\LOG\BT_TX_ON.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\BT_TX_ON.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\SET_BT_TX_ON_LOG.bat


call C:\Testprogram\QF7\%F_N%\Agilent_BTRF\Agilent_BTRF.exe

call C:\Testprogram\QF7\%F_N%\Agilent_BTRF\Agilent_BTRF.bat

timeout /t 1

if "%ERRORLEVEL%"=="1" (echo set Result=PASS >>C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_LOG.bat ) else (echo set Result=FAIL >>C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_LOG.bat)

cd C:\Testprogram\QF7\%F_N%
pause

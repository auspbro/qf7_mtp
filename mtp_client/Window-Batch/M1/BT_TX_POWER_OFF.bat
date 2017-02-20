@echo off

set F_N=M1
echo QF7 BT TX OFF


cd C:\Testprogram\QF7\%F_N%

set logfile_BT_TX_OFF="C:\Testprogram\QF7\%F_N%\LOG\BT_TX_OFF.txt"
set PASS_logfile_BT_TX_OFF="C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_OFF_LOG.bat"

if exist %logfile_BT_TX_OFF% del %logfile_BT_TX_OFF%
if exist %PASS_logfile_BT_TX_OFF% del %PASS_logfile_BT_TX_OFF%



call Window-Client.exe BTPWR_OFF >> C:\Testprogram\QF7\%F_N%\LOG\BT_TX_OFF.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\BT_TX_OFF.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\BT_TX_OFF_LOG.bat

timeout /t 2
cd C:\Testprogram\QF7\%F_N%


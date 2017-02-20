@echo on


echo QF7 BT MAC

cd C:\Testprogram\QF7\M1
set bt_mac=%1%
set logfile="C:\Testprogram\QF7\M1\LOG\BTMAC_WRITE.txt"
set PASS_logfile="C:\Testprogram\QF7\M1\PASS_LOG\BTMAC_WRITE_LOG.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%

call Window-Client.exe BTMAC_WRITE %bt_mac% > C:\Testprogram\QF7\M1\LOG\BTMAC_WRITE.txt

findstr Set C:\Testprogram\QF7\M1\LOG\BTMAC_WRITE.txt >> C:\Testprogram\QF7\M1\PASS_LOG\BTMAC_WRITE_LOG.bat

timeout /t 5

call Window-Client.exe BTMAC_READ > C:\Testprogram\QF7\M1\LOG\BTMAC_READ.txt

findstr Set C:\Testprogram\QF7\M1\LOG\BTMAC_READ.txt >> C:\Testprogram\QF7\M1\PASS_LOG\BTMAC_READ_LOG.bat

pause

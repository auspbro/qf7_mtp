@echo on

set F_N=M1
echo QF7 BT MAC

cd C:\Testprogram\QF7\%F_N%
set bt_mac=%1%
set logfile="C:\Testprogram\QF7\%F_N%\LOG\BTMAC_WRITE.txt"
set PASS_logfile_1="C:\Testprogram\QF7\%F_N%\PASS_LOG\BTMAC_WRITE_LOG.bat"
set PASS_logfile_2="C:\Testprogram\QF7\%F_N%\PASS_LOG\BTMAC_READ_LOG.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile_1% del %PASS_logfile_1%
if exist %PASS_logfile_2% del %PASS_logfile_2%
call Window-Client.exe BTMAC_WRITE %bt_mac% > C:\Testprogram\QF7\%F_N%\LOG\BTMAC_WRITE.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\BTMAC_WRITE.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\BTMAC_WRITE_LOG.bat

timeout /t 5

call Window-Client.exe BTMAC_READ > C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\BTMAC_READ.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\BTMAC_READ_LOG.bat



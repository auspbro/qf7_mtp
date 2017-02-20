@echo on

set F_N=M1
echo CARRIER_HEALTH_TMP108_4a

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_TMP108_4a.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_HEALTH_TMP108_4a.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_HEALTH_TMP108_4a > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_TMP108_4a.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_TMP108_4a.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_HEALTH_TMP108_4a.bat



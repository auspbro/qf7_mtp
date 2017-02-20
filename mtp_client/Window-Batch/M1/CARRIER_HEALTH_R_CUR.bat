@echo on

set F_N=M1
echo CARRIER_HEALTH_R_CUR

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_R_CUR.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_HEALTH_R_CUR.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_HEALTH_R_CUR > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_R_CUR.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_R_CUR.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_HEALTH_R_CUR.bat



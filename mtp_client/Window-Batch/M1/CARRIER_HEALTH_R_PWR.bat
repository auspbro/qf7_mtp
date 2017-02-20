@echo on

set F_N=M1
echo CARRIER_HEALTH_R_PWR

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_R_PWR.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_HEALTH_R_PWR.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe ALS_TMP_I2C > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_R_PWR.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_HEALTH_R_PWR.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_HEALTH_R_PWR.bat



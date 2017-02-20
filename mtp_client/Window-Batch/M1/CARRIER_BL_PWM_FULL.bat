@echo on

set F_N=M1
echo CARRIER_BL_PWM_FULL

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_PWM_FULL.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_PWM_FULL.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_BL_PWM_FULL > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_PWM_FULL.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_PWM_FULL.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_PWM_FULL.bat



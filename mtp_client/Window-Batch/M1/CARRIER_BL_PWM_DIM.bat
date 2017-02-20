@echo on

set F_N=M1
echo CARRIER_HDMI

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_PWM_DIM.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_PWM_DIM.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_BL_PWM_DIM > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_PWM_DIM.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_PWM_DIM.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_PWM_DIM.bat



@echo on

set F_N=M1
echo CARRIER_BL_EN_OFF

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_EN_OFF.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_EN_OFF.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_BL_EN_OFF > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_EN_OFF.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_EN_OFF.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_EN_OFF.bat



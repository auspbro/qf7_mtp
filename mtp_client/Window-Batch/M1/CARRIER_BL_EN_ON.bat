@echo on

set F_N=M1
echo CARRIER_BL_EN_ON

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_EN_ON.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_EN_ON.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_BL_EN_ON > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_EN_ON.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_BL_EN_ON.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_BL_EN_ON.bat



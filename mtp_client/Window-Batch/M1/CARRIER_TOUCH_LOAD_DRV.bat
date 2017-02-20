@echo on

set F_N=M1
echo CARRIER_TOUCH_LOAD_DRV

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TOUCH_LOAD_DRV.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_TOUCH_LOAD_DRV.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_TOUCH_LOAD_DRV> C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TOUCH_LOAD_DRV.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TOUCH_LOAD_DRV.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_TOUCH_LOAD_DRV.bat



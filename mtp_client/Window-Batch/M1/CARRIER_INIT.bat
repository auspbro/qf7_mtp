@echo on

set F_N=M1
echo CARRIER_INIT

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_INIT.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_INIT.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_INIT > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_INIT.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_INIT.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_INIT.bat



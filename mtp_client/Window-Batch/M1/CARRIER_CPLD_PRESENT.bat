@echo on

set F_N=M1
echo CARRIER_CPLD_PRESENT

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_CPLD_PRESENT.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_CPLD_PRESENT.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_CPLD_PRESENT > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_CPLD_PRESENT.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_CPLD_PRESENT.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_CPLD_PRESENT.bat



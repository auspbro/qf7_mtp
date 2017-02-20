@echo on

set F_N=M1
echo CARRIER_CPLD_HW_VERSION

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_CPLD_HW_VERSION.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_CPLD_HW_VERSION.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_HW_VERSION > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_CPLD_HW_VERSION.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_CPLD_HW_VERSION.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_CPLD_HW_VERSION.bat



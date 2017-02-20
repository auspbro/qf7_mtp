@echo on

set F_N=M1
echo CARRIER_DMIC_RIGHT

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_DMIC_RIGHT.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_DMIC_RIGHT.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_DMIC_RIGHT > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_DMIC_RIGHT.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_DMIC_RIGHT.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_DMIC_RIGHT.bat



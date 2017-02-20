@echo on

set F_N=M1
echo CARRIER_DMIC_LEFT

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_DMIC_LEFT.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_DMIC_LEFT.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_DMIC_LEFT > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_DMIC_LEFT.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_DMIC_LEFT.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_DMIC_LEFT.bat



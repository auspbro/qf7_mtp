@echo on

set F_N=M1
echo QF7 LED OFF

cd C:\Testprogram\QF7\%F_N%


set logfile_LED_O="C:\Testprogram\QF7\%F_N%\LOG\LEDAB_O.txt"
set PASS_logfile_LED_O="C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_O_LOG.bat"
if exist %logfile_LED_O% del %logfile_LED_O%
if exist %PASS_logfile_LED_O% del %PASS_logfile_LED_O%


call Window-Client.exe LEDAB_O > C:\Testprogram\QF7\%F_N%\LOG\LEDAB_O.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\LEDAB_O.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_O_LOG.bat



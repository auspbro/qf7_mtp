@echo on

set F_N=M1
echo QF7 LED B

cd C:\Testprogram\QF7\%F_N%


set logfile_LED_B="C:\Testprogram\QF7\%F_N%\LOG\LEDAB_B.txt"
set PASS_logfile_LED_B="C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_B_LOG.bat"
if exist %logfile_LED_B% del %logfile_LED_B%
if exist %PASS_logfile_LED_B% del %PASS_logfile_LED_B%


call Window-Client.exe LEDAB_B > C:\Testprogram\QF7\%F_N%\LOG\LEDAB_B.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\LEDAB_B.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_B_LOG.bat



@echo on

set F_N=M1
echo QF7 LED G

cd C:\Testprogram\QF7\%F_N%


set logfile_LED_G="C:\Testprogram\QF7\%F_N%\LOG\LEDAB_G.txt"
set PASS_logfile_LED_G="C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_G_LOG.bat"
if exist %logfile_LED_G% del %logfile_LED_G%
if exist %PASS_logfile_LED_G% del %PASS_logfile_LED_G%


call Window-Client.exe LEDAB_G > C:\Testprogram\QF7\%F_N%\LOG\LEDAB_G.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\LEDAB_G.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_G_LOG.bat



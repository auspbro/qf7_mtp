@echo on

set F_N=M1
echo QF7 LED White

cd C:\Testprogram\QF7\%F_N%


set logfile_LED_W="C:\Testprogram\QF7\%F_N%\LOG\LEDAB_W.txt"
set PASS_logfile_LED_W="C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_W_LOG.bat"
if exist %logfile_LED_W% del %logfile_LED_W%
if exist %PASS_logfile_LED_W% del %PASS_logfile_LED_W%


call Window-Client.exe LEDAB_W > C:\Testprogram\QF7\%F_N%\LOG\LEDAB_W.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\LEDAB_W.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_W_LOG.bat



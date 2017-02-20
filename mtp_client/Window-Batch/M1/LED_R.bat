@echo on

set F_N=M1
echo QF7 LED R

cd C:\Testprogram\QF7\%F_N%


set logfile_LED_R="C:\Testprogram\QF7\%F_N%\LOG\LEDAB_R.txt"
set PASS_logfile_LED_R="C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_R_LOG.bat"
if exist %logfile_LED_R% del %logfile_LED_R%
if exist %PASS_logfile_LED_R% del %PASS_logfile_LED_R%


call Window-Client.exe LEDAB_R > C:\Testprogram\QF7\%F_N%\LOG\LEDAB_R.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\LEDAB_R.txt>> C:\Testprogram\QF7\%F_N%\PASS_LOG\LEDAB_R_LOG.bat



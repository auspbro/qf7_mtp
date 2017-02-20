@echo on


echo QF7 All LED White

cd C:\Testprogram\QF7\M1


set logfile_LED_ON="C:\Testprogram\QF7\M1\LOG\LEDWHITE_ON.txt"
set PASS_logfile_LED_ON="C:\Testprogram\QF7\M1\PASS_LOG\LED_ON_LOG.bat"
if exist %logfile_LED_ON% del %logfile_LED_ON%
if exist %PASS_logfile_LED_ON% del %PASS_logfile_LED_ON%


call Window-Client.exe LEDA_ON> C:\Testprogram\QF7\M1\LOG\LEDWHITE_ON.txt

findstr Set C:\Testprogram\QF7\M1\LOG\LEDWHITE_ON.txt >> C:\Testprogram\QF7\M1\PASS_LOG\LED_ON_LOG.bat

pause

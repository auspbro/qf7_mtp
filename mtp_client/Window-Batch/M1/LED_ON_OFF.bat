@echo on


echo QF7 All LED White

cd C:\Testprogram\QF7\M1

set logfile_LED_OFF="C:\Testprogram\QF7\M1\LOG\LEDWHITE_OFF.txt"
set logfile_LED_ON="C:\Testprogram\QF7\M1\LOG\LEDWHITE_ON.txt"
set PASS_logfile_LED_OFF="C:\Testprogram\QF7\M1\PASS_LOG\LED_OFF_LOG.bat"
set PASS_logfile_LED_ON="C:\Testprogram\QF7\M1\PASS_LOG\LED_ON_LOG.bat"
if exist %logfile_LED_ON% del %logfile_LED_ON%
if exist %logfile_LED_OFF% del %logfile_LED_OFF%
if exist %PASS_logfile_LED_ON% del %PASS_logfile_LED_ON%
if exist %PASS_logfile_LED_OFF% del %PASS_logfile_LED_OFF%

call Window-Client.exe LEDA_ON> C:\Testprogram\QF7\M1\LOG\LEDWHITE_ON.txt

findstr Set C:\Testprogram\QF7\M1\LOG\LEDWHITE_ON.txt >> C:\Testprogram\QF7\M1\PASS_LOG\LED_ON_LOG.bat

timeout /t 3

call Window-Client.exe LEDA_OFF >> C:\Testprogram\QF7\M1\LOG\LEDWHITE_OFF.txt

findstr Set C:\Testprogram\QF7\M1\LOG\LEDWHITE_OFF.txt >> C:\Testprogram\QF7\M1\PASS_LOG\LED_OFF_LOG.bat

pause

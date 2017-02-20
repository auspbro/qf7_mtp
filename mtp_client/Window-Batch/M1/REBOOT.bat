@echo on

set F_N=M1
echo REBOOT

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\REBOOT.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\REBOOT.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe REBOOT > C:\Testprogram\QF7\%F_N%\LOG\REBOOT.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\REBOOT.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\REBOOT.bat



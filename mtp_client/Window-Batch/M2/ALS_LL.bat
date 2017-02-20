@echo on

set F_N=M2
echo ALS_LL

cd C:\Testprogram\QF7\M1


set logfile="C:\Testprogram\QF7\%F_N%\LOG\ALS_LL.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_LL.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe ALS_LL > C:\Testprogram\QF7\%F_N%\LOG\ALS_LL.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\ALS_LL.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_LL.bat

pause

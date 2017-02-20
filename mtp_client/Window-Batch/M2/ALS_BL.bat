@echo on

set F_N=M2
echo ALS_BL

cd C:\Testprogram\QF7\M1


set logfile="C:\Testprogram\QF7\%F_N%\LOG\ALS_BL.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_BL.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe ALS_BL > C:\Testprogram\QF7\%F_N%\LOG\ALS_BL.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\ALS_BL.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_BL.bat

pause

@echo on

set F_N=M2

echo ALS_I2C

cd C:\Testprogram\QF7\M1


set logfile="C:\Testprogram\QF7\%F_N%\LOG\ALS_I2C.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_I2C.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe ALS_I2C > C:\Testprogram\QF7\%F_N%\LOG\ALS_I2C.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\ALS_I2C.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_I2C.bat

pause

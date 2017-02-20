@echo on

set F_N=M1
echo ALS_TMP_TEMPERATURE

cd C:\Testprogram\QF7\%F_N%\


set logfile="C:\Testprogram\QF7\%F_N%\LOG\ALS_TMP_TEMPERATURE.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_TMP_TEMPERATURE.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe ALS_TMP_TEMPERATURE > C:\Testprogram\QF7\%F_N%\LOG\ALS_TMP_TEMPERATURE.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\ALS_TMP_TEMPERATURE.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\ALS_TMP_TEMPERATURE.bat



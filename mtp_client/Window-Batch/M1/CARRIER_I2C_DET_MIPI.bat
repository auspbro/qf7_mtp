@echo on

set F_N=M1
echo CARRIER_I2C_DET_MIPI

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_I2C_DET_MIPI.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_I2C_DET_MIPI.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_I2C_DET_MIPI > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_I2C_DET_MIPI.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_I2C_DET_MIPI.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_I2C_DET_MIPI.bat



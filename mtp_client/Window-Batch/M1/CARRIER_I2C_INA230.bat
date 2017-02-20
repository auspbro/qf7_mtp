@echo on

set F_N=M1
echo CARRIER_I2C_INA230

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_I2C_INA230.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_I2C_INA230.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_I2C_INA230 > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_I2C_INA230.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_I2C_INA230.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_I2C_INA230.bat



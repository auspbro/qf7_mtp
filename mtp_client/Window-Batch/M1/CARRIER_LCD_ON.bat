@echo on

set F_N=M1
echo CARRIER_LCD_ON

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_LCD_ON.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_LCD_ON.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_LCD_ON > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_LCD_ON.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_LCD_ON.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_LCD_ON.bat


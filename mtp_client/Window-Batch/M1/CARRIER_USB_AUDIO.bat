@echo on

set F_N=M1
echo CARRIER_USB_AUDIO

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_USB_AUDIO.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_USB_AUDIO.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_USB_AUDIO > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_USB_AUDIO.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_USB_AUDIO.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_USB_AUDIO.bat



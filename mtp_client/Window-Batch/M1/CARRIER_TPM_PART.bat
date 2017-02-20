@echo on

set F_N=M1
echo CARRIER_TPM_PART

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TPM_PART.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_TPM_PART.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_TPM_PART > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TPM_PART.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TPM_PART.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_TPM_PART.bat



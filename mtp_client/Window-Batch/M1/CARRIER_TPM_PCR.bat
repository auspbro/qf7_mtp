@echo on

set F_N=M1
echo CARRIER_TPM_PCR

cd C:\Testprogram\QF7\%F_N%


set logfile="C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TPM_PCR.txt"
set PASS_logfile="C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_TPM_PCR.bat"
if exist %logfile% del %logfile%
if exist %PASS_logfile% del %PASS_logfile%


call Window-Client.exe CARRIER_TPM_PCR > C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TPM_PCR.txt

findstr Set C:\Testprogram\QF7\%F_N%\LOG\CARRIER_TPM_PCR.txt >> C:\Testprogram\QF7\%F_N%\PASS_LOG\CARRIER_TPM_PCR.bat



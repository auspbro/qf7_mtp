#input the PoE injector type af/at
poe_type=$1
rm Q_CARRIER_POE_TYPE.txt
usage()
{
echo "Enter AF/AT"

}

#check $1 is not null
if [ -z "$1" ]; then
  echo "FAIL, specify PoE injector type af/at"
  exit 1
fi

echo "INFO, test carrier_poe_type"

#PoE Power Type is given in CPLD register
#0x288 bit 3 - bits 2..0 are PGOOD signals and must be High

string_af="0288: 07"
string_at="0288: 0f"

if [ "$poe_type" = "AF" ]; then
  string_success=$string_af
elif [ "$poe_type" = "AT" ]; then
  string_success=$string_at
else
  echo "ERROR, invalid PoE Power Type"
  usage
  exit 1
fi

found=`isadump -y -f 0x288 0x10 | grep "$string_success"`
if [ -z "$found" ]; then
  echo "FAIL, $poe_type PoE injector connected but NOT detected"
  echo POE_TYPE_$poe_type=FAIL >> Q_CARRIER_POE_TYPE.txt
  #exit 1
else
  echo "PASS, $poe_type PoE injector detected"
  echo POE_TYPE_$poe_type=PASS >> Q_CARRIER_POE_TYPE.txt
fi


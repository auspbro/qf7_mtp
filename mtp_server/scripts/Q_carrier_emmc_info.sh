#==================================================
#carrier_emmc_info.sh
#==================================================

echo "INFO, test carrier_emmc"

exp_size="8388608"
exp_manf="0x0000fe"
exp_name="P1XXXX"

#check eMMC device is present
emmc_size=`cat /sys/class/block/mmcblk0/device/erase_size`
emmc_manf=`cat /sys/class/block/mmcblk0/device/manfid`
emmc_name=`cat /sys/class/block/mmcblk0/device/name`
emmc_serial=`cat /sys/class/block/mmcblk0/device/serial`

if [ "$exp_size" = "$emmc_size" ]; then
  echo "PASS, eMMC size correct, found $emmc_size"
else
  echo "FAIL, eMMC size NOT correct, , found $emmc_size"
  echo CARRIER_EMMC_INFO=FAIL >>Q_CARRIER_EMMC_INFO.txt
  exit 1
fi

if [ "$exp_manf" = "$emmc_manf" ]; then
  echo "PASS, eMMC Manufacturer correct, found $emmc_manf"
else
  echo "FAIL, eMMC Manufacturer NOT correct, found $emmc_manf"
  echo CARRIER_EMMC_INFO=FAIL >>Q_CARRIER_EMMC_INFO.txt
  exit 1
fi

if [ "$exp_name" = "$emmc_name" ]; then
  echo "PASS, eMMC name correct, found $emmc_name"
else
  echo "FAIL, eMMC name NOT correct, found $emmc_name"
  echo CARRIER_EMMC_INFO=FAIL >>Q_CARRIER_EMMC_INFO.txt
  exit 1
fi

echo "INFO, eMMC serial number: $emmc_serial"


echo CARRIER_EMMC_INFO=PASS >>Q_CARRIER_EMMC_INFO.txt

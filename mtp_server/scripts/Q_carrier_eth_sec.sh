echo "INFO, test carrier_eth_sec"

device="eth1"
pcie="03:00.0"
channel="$1"
usage()
{
echo "Enter  DEVICE/SPEED/DUPLEX"
}
rm Q_CARRIER_ETH_NPOE.txt
if [ "$channel" == "DEVICE" ]; then
found=`lspci | grep "$pcie Ethernet controller: Intel Corporation I210 Gigabit Network Connection (rev 03)"`
if [ -z "$found" ]; then
  echo "FAIL, Device $device NOT found, check firmware has been written"
  echo CARRIER_ETH_NPOE_$1=FAIL >>Q_CARRIER_ETH_NPOE.txt
  #exit 1
else
  echo "SUCCESS,  Device $device found"
  echo CARRIER_ETH_NPOE_$1=PASS >>Q_CARRIER_ETH_NPOE.txt
fi

speed=`cat /sys/class/net/$device/speed`

elif [ "$channel" == "SPEED" ]; then
speed=`cat /sys/class/net/$device/speed`
if [ $speed == "1000" ]; then
  echo "PASS, Speed of $device is $speed"
  echo CARRIER_ETH_NPOE_$1=PASS >>Q_CARRIER_ETH_NPOE.txt
else
  echo "FAIL, Speed of $device is $speed"
  echo CARRIER_ETH_NPOE_$1=FAIL >>Q_CARRIER_ETH_NPOE.txt
fi
elif [ "$channel" == "DUPLEX" ]; then
duplex=`cat /sys/class/net/$device/duplex`
if [ $duplex == "full" ]; then
  echo "PASS, Duplex of $device is $duplex"
  echo CARRIER_ETH_NPOE_$1=PASS >>Q_CARRIER_ETH_NPOE.txt
else
  echo "FAIL, Duplex of $device is $duplex"
  echo CARRIER_ETH_NPOE_$1=FAIL >>Q_CARRIER_ETH_NPOE.txt
fi

else
usage
fi
#mac_add=ifconfig | grep "MAC:"
#echo "INFO, MAC Address of $device is $mac_add"

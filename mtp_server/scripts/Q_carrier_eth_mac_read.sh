#pass board to test (pri, sec)
if [ "$1" = "QSEVEN" ]; then
  device=eth1
else
  if [ "$1" = "CARRIER" ]; then
    device=eth0
  else
    echo "FAIL, invalid Ethernet Device specified"
    exit
  fi
fi
rm Q_$1_ETH_MAC.txt
echo "INFO, test carrier_eth_mac_read"

found=`ifconfig | grep $device`
if [ -z "$found" ]; then
  echo "FAIL, Device $device NOT found"
  if [ "$1" = "QSEVEN" ]; then
  	echo QSEVEN_ETH_DEVICE=FAIL >>Q_$1_ETH_MAC.txt
  else
  	echo CARRIER_ETH_DEVICE=FAIL >>Q_$1_ETH_MAC.txt
  fi
  
  exit
else
  echo "PASS, Device $device found"
fi

#report mac address
echo "INFO, MAC Address is, ${found:38:17}"
mac_f=${found:38:2}${found:41:2}${found:44:2}${found:47:2}${found:50:2}${found:53:2}
#echo $1_ETH_MAC=${found:38:17} >>Q_$1_ETH_MAC.txt
echo $1_ETH_MAC=$mac_f >>Q_$1_ETH_MAC.txt

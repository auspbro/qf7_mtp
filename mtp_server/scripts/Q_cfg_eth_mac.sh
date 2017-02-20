#pass board to test (pri, sec)

usage()
{
echo "Enter  CARRIER 00A0C9000000/QSEVEN 0090FB5C23BB"
}


if [ "$1" = "CARRIER" ]; then
  device="-nic=1"
else
  if [ "$1" = "QSEVEN" ]; then
    device="-nic=2"
  else
    echo "FAIL, invalid Ethernet Device specified"
    usage
    exit 1
  fi
fi

#input $2 as mac address XX:XX:XX:XX:XX:XX UPPER CASE
mac=$2

#check mac is not null
if [ -z "$mac" ]; then
  echo "FAIL, no mac address supplied"
  echo "INFO, mac address should be XX:XX:XX:XX:XX:XX with UPPER CASE"
  echo $1_ETH_DEVICE_NO_VALUE=FAIL >>Q_$1_ETH_MAC_W.txt
  exit 1
fi

echo "INFO, test cfg_eth_mac"

#eeupdate requires ":" to be removed
#mac_f=${mac:0:2}${mac:3:2}${mac:6:2}${mac:9:2}${mac:12:2}${mac:15:2}
mac_f=$mac
#set mac address
success_string="Updating Mac Address to $mac_f...Done."
found=`/lib/ld-linux-x86-64.so.2 /usr/sbin/eeupdate64e $device /mac=$mac_f | grep "$success_string"`
if [ -z "$found" ]; then
  echo "FAIL, MAC address NOT configured correctly for $device"
  echo $1_ETH_DEVICE_W=FAIL >>Q_$1_ETH_MAC_W.txt
  #exit 1
else
  echo "PASS, MAC address configured for $device, $mac"
  echo $1_ETH_DEVICE_W=PASS >>Q_$1_ETH_MAC_W.txt
fi

echo "INFO, System must be rebooted for changes be applied"

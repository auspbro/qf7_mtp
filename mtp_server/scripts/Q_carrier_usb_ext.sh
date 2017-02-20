echo "INFO, test carrier_usb_ext"

#check that both USB 3.0 devices are recognised by Linux

string_usb="Driver=usb-storage, 5000M"
rm Q_CARRIER_USB_EXT.txt
found=`lsusb -t | grep -c "$string_usb"`
if [ "$found" = "2" ]; then
  echo "PASS, Number of USB 3.0 Drives detected, $found"
  echo CARRIER_USB_EXT=PASS >>Q_CARRIER_USB_EXT.txt
else
  echo "FAIL, Number of USB 3.0 Drives detected, $found"
  echo CARRIER_USB_EXT=FAIL >>Q_CARRIER_USB_EXT.txt
fi

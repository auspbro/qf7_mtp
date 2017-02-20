echo "INFO, test carrier_lcd"
rm Q_CARRIER_LCD.txt

item="$1"
usage()
{
echo "Enter  CARRIER_LCD_ON/CARRIER_LCD_OFF"
}

i2c_add=68
video_status="eDP1 connected 1200x1920"
if [ "$item" == "CARRIER_LCD_ON" ]; then

echo "INFO, Scanning for Display Bridge"
found=`i2cdetect -y 9 | grep " $i2c_add "`
if [ -z "$found" ]; then
  echo "FAIL, Device 0x$i2c_add NOT found"
  echo CARRIER_LCD_DEVICE=FAIL >> Q_CARRIER_LCD.txt
  #exit 1
else
  echo "PASS, Device 0x$i2c_add found"
fi

found=`xrandr -d :0.0 | grep "$video_status"`
if [ -z "$found" ]; then
  echo "FAIL, eDP output NOT found or incorrect resolution"
  echo CARRIER_LCD_ON=FAIL >> Q_CARRIER_LCD.txt
  #exit 1
else
  echo "PASS, $video_status"
  echo CARRIER_LCD_ON=PASS >> Q_CARRIER_LCD.txt
fi


elif [ "$item" == "CARRIER_LCD_OFF" ]; then

echo CARRIER_LCD_OFF=PASS >> Q_CARRIER_LCD.txt
else
usage
fi

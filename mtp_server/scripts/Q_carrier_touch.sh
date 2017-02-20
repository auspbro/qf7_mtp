echo "INFO, test carrier_touch"

i2c_add=38
item="$1"
usage()
{
echo "Enter  CARRIER_TOUCH_I2C/CARRIER_TOUCH_LOAD_DRV/CARRIER_TOUCH_ULOAD_DRV/TOUCH_SCREEN_TEST"
}
rm Q_CARRIER_TOUCH.txt
if [ "$item" == "CARRIER_TOUCH_I2C" ]; then
found=`i2cdetect -y 9 | grep " $i2c_add "`
if [ -z "$found" ]; then
  echo "FAIL, Device 0x$i2c_add NOT found"
  echo CARRIER_TOUCH_I2C=FAIL >> Q_CARRIER_TOUCH.txt
  #exit 1
else
  echo "PASS, Device 0x$i2c_add found"
  echo CARRIER_TOUCH_I2C=PASS >> Q_CARRIER_TOUCH.txt
fi

elif [ "$item" == "CARRIER_TOUCH_LOAD_DRV" ]; then
modprobe ft7511
echo CARRIER_TOUCH_LOAD_DRV=PASS >> Q_CARRIER_TOUCH.txt

elif [ "$item" == "CARRIER_TOUCH_ULOAD_DRV" ]; then
#unload touch screen drivers
modprobe -r ft7511
echo CARRIER_TOUCH_ULOAD_DRV=PASS >> Q_CARRIER_TOUCH.txt

elif [ "$item" == "TOUCH_SCREEN_TEST" ]; then
export DISPLAY=:0
xrandr -d :0 --output HDMI1 --off
result=`/usr/bin/gizmo-touchscreen-test.py`
echo CARRIER_TOUCH_TEST=${result:0:4} >> Q_CARRIER_TOUCH.txt
xrandr -d :0 --output HDMI1 --auto

else
usage
fi

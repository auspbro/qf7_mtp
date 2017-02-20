echo "INFO, test carrier_eeprom_serial_read"

result=`eeprog -f -16 /dev/i2c-9 0x57 -r 0x10:0x10`

#report serial number
echo "INFO, serial number is, $result¡¨



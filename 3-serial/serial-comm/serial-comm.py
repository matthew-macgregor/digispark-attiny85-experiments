import serial
from time import sleep

with serial.Serial('/dev/ttyUSB0', 38400, timeout=1) as ser:
    msg = b'hello echoed from the Digispark!'
    rx = b''
    count = 1
    ser.write(b'TX >> ' + msg)
    while True:
        x = ser.read(1)
        # print('RX >> ', x)
        rx += x
        if x == b'':
            print(rx)
            rx = b''
            ser.write(b'TX >> ' + msg + b' ' + count.to_bytes(1, 'little'))
            sleep(1)
            count += 1


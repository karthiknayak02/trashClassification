import serial

ser = serial.Serial("COM6", 9600)
res = True
ser.write(res)

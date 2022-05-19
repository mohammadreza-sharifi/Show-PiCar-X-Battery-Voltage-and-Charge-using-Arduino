import serial
from robot_hat import TTS
from time import sleep

arduino = serial.Serial('/dev/ttyACM0',9600)

ttsbot = TTS()

while True:
    raw_voltage = arduino.readline()
    voltage = float(raw_voltage.decode().strip())
    #print(voltage)
    if voltage < 8:
        ttsbot.say(f"charge is low master. the charge is {voltage} volt. connect me to charger.")
        print(voltage)
        sleep(5)
    else:
        pass
    
    
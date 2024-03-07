import os
import time
import json
import serial
import string
import spidev
import sqlite3
import pynmea2
import datetime
from array import*
from decimal import*
from time import sleep
import Adafruit_ADXL345
from firebase import firebase
from functools import partial
from pyfcm import FCMNotification
datetime.datetime(2009, 1, 6, 15, 8, 24, 78915)


status_checked = 'checked'
status_ignore = 'ignore'
status_uncheck = 'uncheck'

firebase = firebase.FirebaseApplication('https://influential-rex-245811.firebaseio.com/', None)

push_service = FCMNotification(api_key = "AIzaSyDq5qClPJfclA-b9sUfsJYd_Te9BKWaFtc")

#ADXL 345
# Create an ADXL345 instance.
accel = Adafruit_ADXL345.ADXL345()
accel.set_range(Adafruit_ADXL345.ADXL345_RANGE_16_G)

#activate serial port for GPS
socket = serial.Serial("/dev/ttyAMA0", baudrate = 9600, timeout = 1)
cd = 1

#Restart the program
temp_X_Value = [0, 0]
temp_Y_Value = [0, 0]
temp_Z_Value = [0, 0]
list_Count = 0
accident_Count = 0

#GPS
def find(string, char) :
    for i, ltr in enumerate(string) :
        if ltr == char :
            yield i

            def check_status() :
            status_flag = firebase.get('/Alert Event/event_details', 'status')
            return status_flag;

def check_newtoken() :
    token = firebase.get('/', 'MobileToken')
    return token;

def get_latitude() :
    #get latitude
    response_lat = firebase.get('/Alert Event/event_details/geolocation', 'latitude')
    return response_lat

    def get_timestamp() :
    #get longitude
    response_time = firebase.get('/Alert Event/event_details/geolocation', 'timestamp')
    return response_time

    def get_longitude() :
    #get longitude
    response_lon = firebase.get('/Alert Event/event_details/geolocation', 'longitude')
    return response_lon

    def set_dataAndSend(your_gps_lat, your_gps_lon, timestamp) :
    data = {
     'geolocation':{
            'latitude':your_gps_lat,
            'longitude' : your_gps_lon,
            'timestamp' : timestamp
     },
     'status' : 'uncheck'
}

return firebase.patch('/Alert Event/event_details', data)

def push_notification() :
    #sending push notifcation as well
                registration_id = check_newtoken()
                message_title = "Collision detected!"
                message_body = "Hey, there is a collision detected click for more details."
                output = push_service.notify_single_device(registration_id = registration_id, message_title = message_title, message_body = message_body)

                def get_currentDateTime() :
                current_datetime = datetime.datetime.now()
                formatted_datetime = current_datetime.strftime("%d-%m-%Y,%H:%M").replace(":", ".", 1)
                format_string = formatted_datetime + "am"
                format = '%d-%m-%Y,%H.%M%p'
                time_1 = datetime.datetime.strptime(format_string, format)
                time_2 = time_1.strftime(format)
                return time_2

                #initialize database
                data = {
                        'geolocation':{
                                'latitude':'2.925076',
                                'longitude' : '101.645507',
                                'timestamp' : '02.16am\b07-07-2019'
                        },
                        'status' : 'uncheck'
            }

                result = firebase.patch('/Alert Event/event_details', data)

                                    while True:
                                #read database
                                    status = check_status()

                                    if status == status_checked:
                                print("deleting data in database")
                                    firebase.delete('/', 'Alert Event')
                                    print("check status received,breaking loop")
                                    print("Please notify the concerned authorities")
                                    break;
                                elif status == status_ignore:
                                print("deleting data in database")
                                    firebase.delete('/', 'Alert Event')
                                    print("ignore status received, is a false alarm. breaking loop")
                                    print("False information")
                                    continue;
                                elif status == status_uncheck:
                                print("Status uncheck.")
                                    else:
                                print("unknown status")

                                    x, y, z = accel.read()
                                    x = float(x)
                                    y = float(y)
                                    z = float(z)
                                    x = (x / 32) * 9.80665
                                    y = (y / 32) * 9.80665
                                    z = ((((((z / 32) - 32) / 32) * 9.80665) * (-1)) - 9.80665)

                                    if list_Count == 2:
                                list_Count = 0
                                    temp_X_Value[list_Count] = x
                                    temp_Y_Value[list_Count] = y
                                    temp_Z_Value[list_Count] = z
                                    list_Count += 1


                                    #Format values to 2 decimal places
                                    print('X-AXIS = {0} m/s^2, Y-AXIS = {1} m/s^2, Z-AXIS = {2} m/s^2'.format(x, y, z))
                                    if temp_X_Value[0] != 0 and temp_X_Value[1] != 0:
                                if ((temp_X_Value[0] > 85.739) or (temp_X_Value[0] < -85.739)) :
                                    accident_Count = 1
                                    if ((temp_Y_Value[0] > 85.739) or (temp_Y_Value[0] < -85.739))::
                                        accident_Count = 2
                                        if ((temp_Z_Value[0] > 85.739) or (temp_Z_Value[0] < -85.739))::
                                            accident_Count = 3
                                            if (accident_Count == 1 or accident_Count == 2 or accident_Count == 3) :
                                                print ":::::Accident is Detected:::::"
                                                temp_X_Value = [0, 0]
                                                accident_Count = 0
                                                #GPS
                                                while cd <= 50:
                                ck1 = 0
                                    fd1 = ''
                                    while ck1 <= 50 :
                                        rcv1 = socket.read(10)
                                        fd1 = fd1 + rcv1
                                        ck1 = ck1 + 1

                                        if '$GPRMC' in fd1 :
                                ps1 = fd.find('$GPRMC')
                                    dif = len(fd1) - ps1

                                    if dif1 > 50:
                                data = fd1[ps1:(ps1 + 50)]
                                    #print(data)
                                    p = list(find(data, ","))
                                    lat = data[(p[2] + 1) : p[3]]
                                    lon = data[(p[4] + 1) : p[5]]

                                    s1 = lat[2:len(lat)]
                                    s1 = Decimal(s1)
                                    s1 = s1 / 60
                                    s11 = int(lat[0:2])
                                    s1 = s11 + s1

                                    s2 = lon[3:len(lon)]
                                    s2 = Decimal(s2)
                                    s2 = s2 / 60
                                    s22 = int(lon[0:3])
                                    s2 = s22 + s2

                                    print "Latitude: " + str(s1)
                                    print "Longitude: " + str(s2)
                                    break
                                    cd = cd + 1

                                    #extracts time
                                    string_time = get_currentDateTime()
                                    string_time = str(string_time)
                                    format_string = string_time.find('.')
                                    format_string_time = string_time[(format_string - 2) : (format_string + 5)]

                                    #extracts date
                                    #concatenate date and time before sending to the database
                                    date_1 = string_time[0:10]
                                    date_time = format_string_time + '\b' + date_1

                                    # Below is your application code area
                                    set_dataAndSend(str(s1), str(s2), date_time) # call this to set your data from sensor, and send these to cloud
                                    push_notification() #call this to receive alert notification on your phone, make sure just call it once every collision.
                                    time.sleep(0.2)






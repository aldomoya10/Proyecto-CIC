# -*- coding: utf-8 -*-
"""
Created on Tue Apr  6 19:31:53 2021

@author: Aldo
"""
import serial



volt=[]
t=[]
Serial_port="COM4"
arduinoData=serial.Serial(Serial_port,9600)


while(1):
        data=arduinoData.readline()
        string_data=str(data.decode('cp437'))
        string_data=string_data.replace("\n", "")
        print(string_data)
arduinoData.close()








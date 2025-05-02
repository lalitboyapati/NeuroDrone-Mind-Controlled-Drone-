import serial
import time

# Connect to Arduino
arduino = serial.Serial('COM4', 9600)  

# Simulated EEG output
eeg_expression = "blink"  # Could be 'wink', 'smile', etc.

# Map expression to car command
expression_map = {
    "blink": "stop",
    "left_wink": "left",
    "right_wink": "right",
    "eyebrows": "forward"
}

# Send command
if eeg_expression in expression_map:
    command = expression_map[eeg_expression]
    arduino.write((command + "\n").encode())
    print(f"Sent: {command}")

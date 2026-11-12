# Wii-nunchuck-controller-robotic-arm

Wii Nunchuk Controlled Robotic Arm
Project Overview
This project interfaces a Nintendo Wii Nunchuk with an Arduino to control a 4-DOF robotic arm. The Nunchuk provides an intuitive, single-hand control scheme by utilizing the joystick for directional movement and the C-button as a "mode shifter" to toggle between joint groups.
This approach allows for precise analog control of the Base, Shoulder, and Elbow using a single joystick, while the Z-button handles the Gripper actuation.
Features
Intuitive Joy-Stick Control: Analog control for smooth movement.
Mode Switching Logic: Uses the C-Button to toggle joystick functionality between the main arm (Base/Shoulder) and the forearm (Elbow).
Smart Gripper: Toggle-style clamping using the Z-Button with customizable open/close limits.
Safety Constraints: Software limits constrain servos between 0-180° to prevent mechanical stalling.
Variable Speed: Adjustable speed parameter for fine-tuning responsiveness.
Hardware Requirements
1x Arduino Uno (or compatible)
4x Servo Motors (SG90 or MG995)
1x Wii Nunchuk Controller
1x Nunchuk Adapter (or jumper wires for direct connection)
Breadboard & External Power Supply (for servos)
Software Dependencies
Servo.h (Standard Arduino Library)
NintendoExtensionCtrl.h (Library for I2C communication with Nunchuk)
Pin Mapping
Component
Arduino Pin
Description
Servo: Base
D3
PWM Control
Servo: Shoulder
D5
PWM Control
Servo: Elbow
D6
PWM Control
Servo: Gripper
D9
PWM Control
Nunchuk: SDA
A4
I2C Data
Nunchuk: SCL
A5
I2C Clock

Control Scheme
The system operates in two modes based on the C-Button state:
Mode 1: Primary Movement (C-Button RELEASED)
Joystick Left/Right: Rotates Base
Joystick Up/Down: Moves Shoulder
Mode 2: Forearm Movement (C-Button HELD)
Joystick Up/Down: Moves Elbow
(Joystick Left/Right is disabled in this mode to prevent accidental rotation)
Gripper Control
Z-Button HELD: Gripper Closes (Target: 160°)
Z-Button RELEASED: Gripper Opens (Target: 120°)
Note: Gripper angles can be tuned in the code variables gripperOpen and gripperClosed.
Setup & Tuning
Wiring: Ensure servos are powered by an external 5V source, not directly from the Arduino 5V pin, to strictly avoid brownouts. Connect the Nunchuk SDA/SCL to Arduino A4/A5.
Calibration:
Check int speed = 2; in the code. Increase this value for faster movement, decrease for higher precision.
Adjust gripperClosed if the motors buzz when gripping an object.


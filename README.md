# Wii Nunchuk Controlled Robotic Arm

## Project Overview
This project interfaces a Nintendo Wii Nunchuk with an Arduino to control a 4-DOF robotic arm[cite: 6]. The Nunchuk provides an intuitive, single-hand control scheme by utilizing the joystick for directional movement and the C-button as a "mode shifter" to toggle between joint groups[cite: 6]. This approach allows for precise analog control of the Base, Shoulder, and Elbow using a single joystick, while the Z-button handles the Gripper actuation[cite: 6].

## Features
*   **Intuitive Joy-Stick Control:** Analog control for smooth movement[cite: 6].
*   **Mode Switching Logic:** Uses the C-Button to toggle joystick functionality between the main arm (Base/Shoulder) and the forearm (Elbow)[cite: 6].
*   **Smart Gripper:** Toggle-style clamping using the Z-Button with customizable open/close limits[cite: 6].
*   **Safety Constraints:** Software limits constrain servos between 0-180° to prevent mechanical stalling[cite: 6].
*   **Variable Speed:** Adjustable speed parameter for fine-tuning responsiveness[cite: 6].

## Hardware Requirements
*   1x Arduino Uno (or compatible)[cite: 6]
*   4x Servo Motors (SG90 or MG995)[cite: 6]
*   1x Wii Nunchuk Controller[cite: 6]
*   1x Nunchuk Adapter (or jumper wires for direct connection)[cite: 6]
*   Breadboard & External Power Supply (for servos)[cite: 6]

## Software Dependencies
*   `Servo.h` (Standard Arduino Library)[cite: 6]
*   `NintendoExtensionCtrl.h` (Library for I2C communication with Nunchuk)[cite: 6]

## Pin Mapping
| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| Servo: Base | D3 | PWM Control[cite: 7] |
| Servo: Shoulder | D5 | PWM Control[cite: 7] |
| Servo: Elbow | D6 | PWM Control[cite: 7] |
| Servo: Gripper | D9 | PWM Control[cite: 7] |
| Nunchuk: SDA | A4 | I2C Data[cite: 7] |
| Nunchuk: SCL | A5 | I2C Clock[cite: 7] |

## Control Scheme
The system operates in two modes based on the C-Button state[cite: 7]:

**Mode 1: Primary Movement (C-Button RELEASED)**
*   **Joystick Left/Right:** Rotates Base[cite: 7].
*   **Joystick Up/Down:** Moves Shoulder[cite: 7].

**Mode 2: Forearm Movement (C-Button HELD)**
*   **Joystick Up/Down:** Moves Elbow[cite: 7].
*   (Joystick Left/Right is disabled in this mode to prevent accidental rotation)[cite: 7].

**Gripper Control**
*   **Z-Button HELD:** Gripper Closes (Target: 160°)[cite: 7].
*   **Z-Button RELEASED:** Gripper Opens (Target: 120°)[cite: 7].
*   *Note:* Gripper angles can be tuned in the code variables `gripperOpen` and `gripperClosed`[cite: 7].

## Setup & Tuning
1.  **Wiring:** Ensure servos are powered by an external 5V source, not directly from the Arduino 5V pin, to strictly avoid brownouts[cite: 8]. Connect the Nunchuk SDA/SCL to Arduino A4/A5[cite: 8].
2.  **Calibration:** Check `int speed = 2;` in the code[cite: 8]. Increase this value for faster movement, decrease for higher precision[cite: 8]. Adjust `gripperClosed` if the motors buzz when gripping an object[cite: 8].


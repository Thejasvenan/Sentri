# 🛠️ SENTRI Automated Pickup and Cleaning Robot

This repository contains the Arduino code developed for the navigation system of **SENTRI**, an autonomous robot designed to collect leftover bottles from cafeteria tables. This system enables SENTRI to accurately follow navigation lines, detect obstacles, and stop at designated table locations for item collection.

## 📌 Project Overview

SENTRI operates in a cafeteria environment (Sentra Court), where black navigation lines are laid on the floor to define movement paths between tables. The robot uses IR sensors for line following and an ultrasonic sensor for obstacle detection. A special '+' marker near each table is used as a signal for SENTRI to stop and collect items.

## 🚀 Features

- 🔍 **Line Following:**  
  Utilizes two infrared (IR) sensors mounted underneath to follow black lines on the floor.

- ⛔ **Obstacle Detection:**  
  Ultrasonic sensor mounted on the front detects obstacles within a 30 cm range and halts the robot to prevent collisions.

- ✋ **Stop at Tables:**  
  Detects perpendicular black lines ("+") next to tables and stops for 3 seconds to simulate the collection process.

- 🔄 **Autonomous Resume:**  
  After completing the collection, the robot resumes navigation to the next table.

## 🧠 Technologies Used

- Arduino Uno  
- IR Sensors  
- Ultrasonic Sensor (HC-SR04)  
- Dual DC Motor Control  
- Embedded C (Arduino IDE)

## 🔧 Hardware Overview

- 4 × Caster Wheels (for support)  
- 2 × DC Motor Gear Wheels (for movement)  
- 2 × IR Sensors (line following)  
- 1 × Ultrasonic Sensor (obstacle detection)

# Traffic Light for Cars and Pedestrians (Arduino)

My very first Arduino project — a functional traffic light system for cars and pedestrians, controlled by a push button. Built with Arduino Uno and simulated in Tinkercad.

## 🔧 Components
- Arduino Uno
- 5 LEDs (red, yellow, green for cars, red and green for pedestrians)
- 5 resistors (220Ω)
- 1 push button
- Breadboard + jumper wires

## 🧠 Project Logic
- The LEDs simulate a real traffic light for cars (red, yellow, green).
- 2 separate LEDs represent the pedestrian signal (red/green).
- When the button is pressed, the sequence changes:
  - Cars stop (red light).
  - Pedestrians get the green light to cross.
  - After a few seconds, the system resets to the normal cycle.

## 💻 Arduino Code
The code was written in Tinkercad and exported as `.ino`.  
You can open it in Arduino IDE, upload it to your board, and modify it as you like.

## 📷 Tinkercad Simulation
https://www.tinkercad.com/things/1R5TYZ0OOzB-trafficlight/editel?returnTo=%2Fthings%2F1R5TYZ0OOzB-semaforpietoni

## 🧠 What I Learned
- How to use digital pins on Arduino
- Controlling LEDs and a push button
- Implementing real-world traffic light logic
- Documenting and sharing projects on GitHub

## 🚀 Posible Improvements
- Add a buzzer for sound alerts
- Display countdown timer for pedestrians
- Replace button with a proximity sensor

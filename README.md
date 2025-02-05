## Project Overview
This project aims to combine image processing and IoT devices to monitor and control various environmental and device parameters using ESP32 devices and sensors. The core functionality involves real-time hand gesture recognition, where the number of fingers detected by a camera is sent to ESP32 devices to control LEDs, a 7-segment display, and other components such as temperature sensors and buzzers.
Key components of the system include:
- **Image Processing** using OpenCV for real-time hand gesture detection
- **ESP32 Communication** for controlling devices based on detected hand gestures
- **Web Integration** for data visualization and remote access to results
## Hardware Components
- **ESP32**: Microcontroller responsible for handling data, controlling LEDs, and interfacing with sensors
- **LEDs & 7-Segment Display**: Used for visual feedback based on hand gesture input
- **DHT11 Sensor**: Measures temperature and humidity
- **Ultrasonic Sensor**: Measures distance for environmental data collection
- **Buzzer**: Provides auditory feedback
- **RGB LED**: Visual feedback with multiple colors based on the sensor input
## Software Libraries
- **OpenCV**: For image processing (detecting fingers)
- **ESP32 WebServer**: For handling HTTP requests and controlling devices
- **HTTPClient**: For making HTTP GET requests to send data to a web server
- **DHT11**: For reading temperature and humidity data
## Key Features
### 1. Hand Gesture Detection
- A camera captures the image and detects the number of fingers using OpenCV.
- A Region of Interest (ROI) is defined, and the image is processed (converted to grayscale, blurred, thresholded).
- The number of fingers is determined by analyzing the contours in the image.
### 2. ESP32 Control
- The detected number of fingers is sent to an ESP32 device via an HTTP GET request.
- The ESP32 controls LEDs and displays the number on a 7-segment display according to the number of fingers detected.
### 3. Web Integration
- The detected data is sent to a website, where the information is stored in a database and can be accessed remotely.
### 4. Data Visualization and Control
- Based on the received finger count, the system provides visual feedback (LED and 7-segment display).
- Additional environmental data (temperature, humidity, distance) is also collected and displayed.
## Project Structure
```bash
|-- src/
|   |-- main/
|   |   |-- image_processing.py (OpenCV script for finger detection)
|   |   |-- esp32_control.ino (Arduino code for ESP32 control)
|   |-- web/
|   |   |-- data_visualization.html (Web page for displaying collected data)
|-- docs/
|   |-- IotProje.pdf (Project documentation)
```
## Setup and Installation
### Hardware Setup
1. **ESP32**: Connect the ESP32 to your network using Wi-Fi credentials in the code.
2. **Sensors**: Attach the necessary sensors (DHT11, Ultrasonic, etc.) to the specified pins on the ESP32.
3. **LEDs & 7-Segment Display**: Connect the LEDs and 7-segment display to the appropriate pins.
### Software Setup
1. Clone the repository to your local machine.
   ```bash
   git clone https://github.com/furkannuzum/IoTProject.git
   ```
2. Install dependencies:
   - For Python, install OpenCV using `pip install opencv-python`.
   - For Arduino IDE, ensure the ESP32 library is installed.
3. Upload the `esp32_control.ino` to your ESP32 using the Arduino IDE.

### Running the Project
1. Open the image processing script `image_processing.py` to start detecting hand gestures.
2. The ESP32 will listen for incoming HTTP requests and update the LEDs and display accordingly.
3. Data will be sent to the web server for remote access.

### Video Demonstrations
- [First ESP32 demo](https://youtube.com/shorts/_X-tBcpf5Og?feature=share)
- [Second ESP32 demo](https://youtu.be/iaPInkb580s)

## Contributors
- **Cuma Aktaş**: Second ESP32 Code and Control
- **Mehmet Emin Gündüzlü**: Sensor Handling
- **Fürkan Üzüm**: First ESP32 Code and Control
- **Ömer Faruk Özalp**: Image Processing Code and Control

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

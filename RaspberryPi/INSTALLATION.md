# Raspberry pi installation

- Imager https://www.raspberrypi.com/software/
- User Imager to flash sd card with "Raspberry pi OS Lite (32 bits)"
- boot pi
- connect with pi/raspberry
- activate ssh (sudo raspi-config)
- Install AP https://github.com/RaspAP/raspap-webgui
- sudo apt install docker-compose git
- `sudo adduser -aG docker pi`
- `git clone <myprojet>`
- cd myproject/RaspberryPi/PrometheusGrafana
- `docker-compose up -d`
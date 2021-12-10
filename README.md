# Potager Connecté

## Hardware

- ESP8266
- BMP180 (I2C)
- BH1750 (I2C)
- ...

- Raspberry Pi

## Programming ESP8266

platformio code in `ESP8266/`

## Raspberry pi (raspi)

- [Installation notes](RaspberryPi/INSTALLATION.md)

## How to use

1. Plug the raspi
    - it creates a wifi
    - it (automatically?) starts prometheus and grafana as docker containers
2. connect your phone / tablet / pc to raspi wifi
3. go to Grafana [http://10.3.141.1:3000/](http://10.3.141.1:3000/)

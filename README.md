# Sheradon #
### A python docker app to control a gate or trigger anything else using a telegram bot. ###

## Usage ##

```
git clone https://github.com/BionicWeb/Sheradon.git
cd Sheradon
```
Edit config.py:
```
nano config.py
```
Run the container:
```
docker run --rm -d -v $PWD/config.py:/app/config.py -p 5000:5000 --name sheradon bionicweb/sheradon
```
Open sheradon.ino in Arduino IDE

Make sure to edit settings in wifi_secrets.h

Upload the sketch to your ESP8266 or ESP32

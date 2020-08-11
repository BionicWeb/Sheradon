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
(Optional but Better) Run using docker compose and traefik to get SSL:
Make sure to replace your email and domain below where it is in CAPS.
```
version: "3.3"

services:

  traefik:
    image: "traefik:v2.2"
    container_name: "traefik"
    command:
      #- "--log.level=DEBUG"
      #- "--api=true"
      #- "--api.insecure=true"
      #- "--api.dashboard=true"
      - "--providers.docker=true"
      - "--providers.docker.exposedbydefault=false"
      - "--entrypoints.web.address=:80"
      - "--entrypoints.websecure.address=:443"
      - "--certificatesresolvers.myresolver.acme.httpchallenge=true"
      - "--certificatesresolvers.myresolver.acme.httpchallenge.entrypoint=web"
      - "--certificatesresolvers.myresolver.acme.email=YOUR@EMAIL.COM"
      - "--certificatesresolvers.myresolver.acme.storage=/letsencrypt/acme.json"
    ports:
      - "80:80"
      - "443:443"
      #- "8080:8080"
    volumes:
      - "./letsencrypt:/letsencrypt"
      - "/var/run/docker.sock:/var/run/docker.sock:ro"

  sheradon:
    image: "bionicweb/sheradon"
    container_name: "sheradon"
    ports:
      - "5000:5000"
    volumes:
      - "${HOME}/Sheradon/config.py:/app/config.py"
    labels:
      - "traefik.enable=true"
      - "traefik.http.routers.sheradon.rule=Host(`YOUR.DOMAIN.COM`)"
      - "traefik.http.routers.sheradon.entrypoints=websecure"
      - "traefik.http.routers.sheradon.tls.certresolver=myresolver"
```

Open sheradon.ino in Arduino IDE

Make sure to edit settings in wifi_secrets.h

Upload the sketch to your ESP8266 or ESP32

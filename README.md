# Sheradon #
### A python docker app to control a gate or trigger anything else using a telegram bot. ###

## Usage ##

```
git clone https://github.com/BionicWeb/Sheradon.git
cd Sheradon
```
Then please edit config.py:
```
nano config.py
```
run the container:
```
docker run --rm -d -v $PWD/config.py:/app/config.py -p 5000:5000 bionicweb/sheradon
```


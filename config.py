# Server Settings
APP_PORT = 5000

# MQTT Settings (I used https://io.adafruit.com)
MQTT_USERNAME = "MQTTUsername"
MQTT_PASSWORD = "MQTTPassword"
MQTT_SERVER = "MQTTServer"
MQTT_PORT = 1883
# The below topic structure is specific to how adafruit requires
# If you use your own MQTT broker feel free to use whatever you want
# This is subscribed to on the ESP8266 or any other device you choose
MQTT_COMMAND_TOPIC = "username/feeds/feedname"
# When I receive the below string on my ESP8266, I trigger the D1 pin for a short period to trigger the gate
MQTT_OPEN_COMMAND = "open"

# MongoDB Settings ( I used https://www.mongodb.com/cloud/atlas for a free DB )
MONGODB_SERVER = "mongodb+srv://user:password@blah.blah.mongodb.net/mydbname?retryWrites=true&w=majority" 
MONGODB_CLUSTER = "sheradon" # name what you named your db in mongo
MONGODB_COLLECTION = "tokens" # the collection name in mongo

# Domain Settings

# The domain you want to use where people can use the tokens to open the gate or trigger whatever you want triggered.
DOMAIN_NAME = "https://www.mydomain.com"

# Telegram Settings

# Get from the @BotFather on telegram
TELEGRAM_BOT_TOKEN = "telegramtoken"
TOKEN_EXPIRE_MINUTES = 30
BOT_OPENING_MSG = "Opening Gate"
BOT_TOKEN_NOT_FOUND_MSG = "Token expired..."
# User IDs that should have access to get tokens and send open command (Get from @userinfobot)
LIST_OF_ADMINS = [00000, 11111, 22222]

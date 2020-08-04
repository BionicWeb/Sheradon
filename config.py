# Server Settings
APP_PORT = 5000

# MQTT Settings (I used https://io.adafruit.com)
MQTT_USERNAME = "MQTTUsername"
MQTT_PASSWORD = "MQTTPassword"
MQTT_SERVER = "MQTTServer"
MQTT_PORT = 1883
MQTT_COMMAND_TOPIC = "username/feeds/feedname"
MQTT_OPEN_COMMAND = "open"

# MongoDB Settings ( I used https://www.mongodb.com/cloud/atlas for a free DB )
MONGODB_SERVER = "mongodb+srv://user:password@blah.blah.mongodb.net/mydbname?retryWrites=true&w=majority" 
MONGODB_CLUSTER = "sheradon" # name what you named your db in mongo
MONGODB_COLLECTION = "tokens" # the collection name in mongo

# Domain Settings
DOMAIN_NAME = "https://www.mydomain.com" # the domain you want to use where people can use the tokens to open the gate or trigger whatever you want triggered.

# Telegram Settings
TELEGRAM_BOT_TOKEN = "telegramtoken" # Get from the @BotFather on telegram
TOKEN_EXPIRE_MINUTES = 30
BOT_OPENING_MSG = "Opening Gate"
BOT_TOKEN_NOT_FOUND_MSG = "Token expired..."
LIST_OF_ADMINS = [00000, 11111, 22222] # User IDs that should have access to get tokens and send open command (Get from @userinfobot)

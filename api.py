from flask import Flask, request

# Hosting a development Web API
# as an intermediate connection
# for both the ESP8266-12E and
# the Roblox game

app = Flask(__name__)
isOn = False

network = {
    'ipaddr': 'ip',
    'port': '8080'
}

@app.route('/post', methods=['POST'])
def receivePost():
    global isOn
    isOn = not isOn
    return '<p>Approved</p>'


@app.route('/dat', methods=['GET'])
def get():
    return '{ \"isOn\": '+str(isOn).lower()+' }'

app.run(host=network['ipaddr'], port=network['port'])

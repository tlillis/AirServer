#Example websocket client using autobahn

from autobahn.twisted.websocket import WebSocketClientProtocol, \
    WebSocketClientFactory

import json

class MyClientProtocol(WebSocketClientProtocol):

    def onConnect(self, response):
        print("Server connected: {0}".format(response.peer))

    def onOpen(self):
        print("WebSocket connection open.")

    def onMessage(self, payload, isBinary):
        if not isBinary:
            try:
                msg = json.loads(payload.decode('utf8'))
                print("GOT: {}".format(msg))
            except:
                print("JSON Parse Error")


    def onClose(self, wasClean, code, reason):
        print("WebSocket connection closed: {0}".format(reason))

if __name__ == '__main__':

    import sys

    from twisted.python import log
    from twisted.internet import reactor

    log.startLogging(sys.stdout)

    factory = WebSocketClientFactory("ws://localhost:9000", debug=False)
    factory.protocol = MyClientProtocol

    reactor.connectTCP("127.0.0.1", 9000, factory)
    reactor.run()
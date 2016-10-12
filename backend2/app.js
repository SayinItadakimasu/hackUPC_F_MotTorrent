var express = require('express');
var app = express();
var net = require('net');
var zpad = require('zpad');
var PADLENGTH = 10; //The message format sends a PADLEGTH-long ASCII header with the number of octets to follow

function sendBuffer(data, socket)
{
    //Adds the LENGTH pseudo-header and sends the data over the socket
    var dataLength = zpad(Buffer.byteLength(data), PADLENGTH);
    socket.write(dataLength + data);
}

app.get('/api/allStatus', function(req, res) {
    var client = new net.Socket();
    client.connect(8492,'localhost', function() {
        sendBuffer('Please get allStatus\n', client);
    });

    var recvBuffer = new Buffer(0);

    client.on('data', function(receivedData) {
        recvBuffer = Buffer.concat([recvBuffer, receivedData]);
    });

    client.on('end', function() {
        res.send(recvBuffer);
        res.end();
    })

});



app.listen(3000);
var express = require('express');
var net = require('net');
var zpad = require('zpad');
var PADLENGTH = 10; //The message format sends a PADLENGTH-long ASCII header with the number of octets to follow

var app = express();
app.disable('etag'); //we don't want the app to include an ETAG header, it will cause any proxying server

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

    var recvBuffer = new Buffer(0); //we buffer all the response from the daemon before acting on it

    client.on('data', function(receivedData) {
        recvBuffer = Buffer.concat([recvBuffer, receivedData]);
    });

    client.on('end', function() {
        res.type('json'); //we expect the dameon to return a JSON string with our data, so we just passthrough
        res.send(recvBuffer);
    })

});



app.listen(3000);
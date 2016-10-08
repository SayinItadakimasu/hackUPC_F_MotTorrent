var express = require('express');
var bodyParser = require('body-parser');
var app = express();
var request = require('request');
// view engine setup
// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

module.exports = app;

var router = express.Router();

router.get('/testingSocket', function(req, res) {
  res.json({message: 'welcome to the api'});
  var net = require('net');
  var client = new net.Socket();
  client.connect(8492, 'localhost', function(){
    console.log("conectado al socket");
    client.write("Can I haz status");
  });

  client.on('data', function(data) {
    console.log('Received: ' + data);
    client.destroy(); // kill client after server's response
  });

  client.on('close', function() {
    console.log('Connection closed')
  });
});


router.route('/add/torrent')
  //add a torrent via .torrent file
  .post(function (req, res) {
    res.json({message: 'Adding Torrent - STUB METHOD'});
    var net = require('net');
    var client = new net.Socket();
  });

router.route('/add/magnet')
  //add a torrent via magnet link
  .post(function (req, res) {
    var magnet = req.body.magnet;
    var net = require('net');
    var client = new net.Socket();
    client.connect(8492, 'localhost', function(){
      client.write('ADD MAGNET \n'+magnet);
    });

    client.on('data', function(data) {
      console.log('Received: '+data);
      res.json({Received: data});
      client.destroy();
    });

    client.on('close', function() {
      console.log('magnet connection closed');
    });
  });

route.route('/remove/:torrent_id')
  .delete(function (req, res) {
    var id = req.params.torrent_id;
    var net = require('net');
    var client = new net.Socket();
    client.connect(8492, 'localhost', function(){
      client.write('DELETE TORRENT \n'+id);
    });
    client.on('data', function(data) {
      console.log('Received: '+data);
      res.json({Received: data});
      client.destroy();
    });

    client.on('close', function() {
      console.log('delete connection closed');
    });
  });

route.route('/status')
    .get(function (req, res) {
      var net = require('net');
      var client = new net.Socket();
      client.connect(8492, 'localhost', function(){
        console.log("conectado al socket");
        client.write("GET STATUS\n");
      });
      client.on('data', function(data) {
        console.log('Received: '+data);
        //Montar el json
        res.json({Status: data});
        client.destroy();
      });

      client.on('close', function() {
        console.log('status connection closed');
      });
    });
app.use('/api/v1', router);

route.route('/testingproxy')
    .get(function (req, res) {
      res.json({Status: 'Proxy properly working'});
    });
app.listen(8080);
console.log("localhost:8080");

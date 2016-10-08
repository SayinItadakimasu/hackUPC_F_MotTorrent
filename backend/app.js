var express = require('express');
var bodyParser = require('body-parser');
var app = express();
// var request = require('request');
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
    client.end("Can I haz status");
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
    res.json({"message": "Adding Torrent - STUB METHOD"});
    var net = require('net');
    var client = new net.Socket();
  });

router.route('/add/magnet')
  //add a torrent via magnet link
  .post(function (req, res) {
    //var magnet = "magnet:?xt=urn:btih:13068ce029934ce8504d5137e5683c9c701ddf77&dn=Hawaii.Five-0.2010.S07E03.HDTV.x264-LOL%5Bettv%5D&&tr=udp%3A%2F%2Ftracker.openbittorrent.com%3A80%2Fannounce&tr=udp%3A%2F%2Fglotorrents.pw%3A6969%2Fannounce&tr=udp%3A%2F%2Ftracker.openbittorrent.com%3A80%2Fannounce&tr=udp%3A%2F%2Ftracker.opentrackr.org%3A1337%2Fannounce&tr=udp%3A%2F%2Fzer0day.to%3A1337%2Fannounce&tr=udp%3A%2F%2Ftracker.coppersurfer.tk%3A6969%2Fannounce";
    //var magnet = req.body.magnet;
    var net = require('net');
    var client = new net.Socket();
    client.connect(8492, 'localhost', function(){
      client.end('ADD MAGNET \n'+JSON.stringify(req.body));
    });

    client.on('data', function(data) {
      console.log('Received: '+data);
      res.json({"Received": ""+data});
      client.destroy();
    });

    client.on('close', function() {
      console.log('magnet connection closed');
    });
  });

router.route('/remove/:torrent_id')
  .delete(function (req, res) {
    //var id = req.params.torrent_id;
    var net = require('net');
    var client = new net.Socket();
    client.connect(8492, 'localhost', function(){
      client.end('DELETE TORRENT \n'+JSON.stringify(req.params.id));
    });
    client.on('data', function(data) {
      console.log('Received: '+data);
      res.json({"Received": ""+data});
      client.destroy();
    });

    client.on('close', function() {
      console.log('delete connection closed');
    });
  });

router.route('/status')
    .get(function (req, res) {
      var net = require('net');
      var client = new net.Socket();
      client.connect(8492, 'localhost', function(){
        console.log("conectado al socket");
        client.end("GET STATUS\n");
      });
      client.on('data', function(data) {
        console.log('Received: '+data);
        //Montar el json
        res.json({"Status": ""+data});
        client.destroy();
      });

      client.on('close', function() {
        console.log('status connection closed');
      });
    });
app.use('/api/v1', router);

router.route('/testingproxy')
    .get(function (req, res) {
      res.json({"Status": "Proxy properly working"});
    });
app.listen(8080);
console.log("localhost:8080");

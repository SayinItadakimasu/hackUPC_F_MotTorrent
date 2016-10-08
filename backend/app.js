var express = require('express');
var bodyParser = require('body-parser');
var app = express();
var net = require('net');
var zpad = require('zpad');
// var request = require('request');
// view engine setup
// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));

module.exports = app;

var router = express.Router();

router.route('/add/magnet')   //add a torrent via magnet link
  .post(function (req, res) {
    var client = new net.Socket();
    client.connect(8492, 'localhost', function () {
      var data = 'ADD MAGNET\n' + JSON.stringify(req.body);
      var length = zpad(Buffer.byteLength(data, 'utf8'), 10);
      console.log(length);
      console.log(data);

      client.write(length);
      client.write(data);

    });

    client.on('data', function (data) {
      console.log('Received: ' + data);
      res.send(data);
    });

    client.on('close', function () {
      console.log('magnet connection closed');
    });
  });

router.route('/status')
  .get(function (req, res) {
    var client = new net.Socket();
    client.connect(8492, 'localhost', function () {
      var data = "GET STATUS\n";
      var length = zpad(Buffer.byteLength(data, 'utf8'), 10);

      client.write(length);
      client.write(data);
    });
    client.on('data', function (data) {
      console.log('Received: ' + data);
      res.send(data);
    });

    client.on('close', function () {
      console.log('status connection closed');

    });
  });


router.route('/remove/:torrent_id')
  .delete(function (req, res) {
    //var id = req.params.torrent_id;
    var client = new net.Socket();
    client.connect(8492, 'localhost', function () {
      client.end('DELETE TORRENT \n' + JSON.stringify(req.params.id));
    });
    client.on('data', function (data) {
      console.log('Received: ' + data);
      res.json({"Received": "" + data});
      client.destroy();
    });

    client.on('close', function () {
      console.log('delete connection closed');
    });
  });

app.use('/api/v1', router);

app.listen(8080);
console.log("listening on localhost:8080 for http");

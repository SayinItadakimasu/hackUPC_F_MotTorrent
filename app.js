var express = require('express');
var bodyParser = require('body-parser');
var app = express();

// view engine setup
// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

module.exports = app;

var router = express.Router();

router.get('/', function(req, res) {
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

app.use('/api', router);

app.listen(8080);
console.log("localhost:8080");

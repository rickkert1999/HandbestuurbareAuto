//express npm
const express = require("express");
const app = express();

//socket.io npm
const http = require("http").Server(app);
const io = require("socket.io")(http);

//serialport npm
const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");
const port = new SerialPort("COM7");
const parser = port.pipe(new Readline({ delimiter: "\r\n" }));

const serverPort = 3000;

app.use(express.static("public")); //set the public folder to static
app.get("/", function (req, res) {
  res.sendFile("public/index.html", { root: __dirname }); //your html file path
});

//Whenever someone connects this gets executed
io.on("connection", function (socket) {
  console.log("A user connected");

  //Get var for client site
  socket.on("check", value);

  //Send data
  function value(Direction) {
    console.log(Direction);

    //send data to arduino
    port.write(Direction);
  }

  //Whenever someone disconnects this piece of code executed
  socket.on("disconnect", function () {
    console.log("A user disconnected");
  });
});

//declare the port
http.listen(3000, function () {
  console.log("listening on *:3000");
  console.log("listening on: http://localhost:" + serverPort);
});

//instal npm's: socket.io, express, serialport

var socket = io();

var buttons = document.querySelectorAll('.buttons');

buttons.forEach(function(button) {
  button.addEventListener('click', function(){
    let direction = button.dataset.direction;
    dataSend(direction);
  });
});

//Tell the arduino what to do
function dataSend(Direction){
  console.log(Direction);
  socket.emit("check", Direction);    
};

//Leap.loop uses browser's requestAnimationFrame
var options = { enableGestures: true };

let leftHand = "";
let rightHand = "";

//Main Leap loop
Leap.loop(options, function (frame) {

  //Loop for the hands
  for (var i = 0, len = frame.hands.length; i < len; i++) {
    //Make te hand
    hand = frame.hands[i];
  
    //Get 2 var from your 2 hands
    if (hand.type === "left") {
      leftHand = hand.grabStrength
    }
    else {
      rightHand = hand.grabStrength
    }

    //Tell the arduino what to do
    if (frame.hands.length === 2) { 
      if (rightHand < 0.5 && leftHand < 0.5){
        socket.emit("check", "f");    
      }
      if (rightHand > 0.5 && leftHand > 0.5){
        socket.emit("check", "b");    
      }
      if (rightHand < 0.5 && leftHand > 0.5){
        socket.emit("check", "r");    
      }
      if (rightHand > 0.5 && leftHand < 0.5){
        socket.emit("check", "l");    
      }
    } //Stop if there are no hands in the frame of the Leap Motion
    else {
      socket.emit("check", "s")
    }    
  }
});

function concatData(id, data) {
  return id + ": " + data + "<br>";
}

function getFingerName(fingerType) {
  switch (fingerType) {
    case 0:
      return "Thumb";
      break;
    case 1:
      return "Index";
      break;
    case 2:
      return "Middle";
      break;
    case 3:
      return "Ring";
      break;
    case 4:
      return "Pinky";
      break;
  }
}

function concatJointPosition(id, position) {
  return id + ": " + position[0] + ", " + position[1] + ", " + position[2] + "<br>"; //prettier-ignore
}

var output = document.getElementById("output");
var frameString = "",
  handString = "",
  fingerString = "";
var hand, finger;

//Leap.loop uses browser's requestAnimationFrame
var options = { enableGestures: true };

//Main Leap loop
Leap.loop(options, function (frame) {
  //Show te amout of hands and fingers
  frameString = concatData("frame_id", frame.id);
  frameString += concatData("num_hands", frame.hands.length);
  frameString += concatData("num_fingers", frame.fingers.length);
  frameString += "<br>";

  for (var i = 0, len = frame.hands.length; i < len; i++) {
    //Show which hand is displayed
    hand = frame.hands[i];
    handString = concatData("hand_type", hand.type);

    //if this is close to 1 its moste accurate
    handString += concatData("confidence", hand.confidence);

    //Pinch strength of hand
    handString += concatData("pinch_strength", hand.pinchStrength);

    //Grab strength of hand
    handString += concatData("grab_strength", hand.grabStrength);

    handString += concatData("palm_position", hand.palmPosition);

    handString += "<br>";

    for (var j = 0, len2 = hand.fingers.length; j < len2; j++) {
      finger = hand.fingers[j];
      fingerString = concatData("finger_type", finger.type) + "(" + getFingerName(finger.type) + ")" + "<br>" //prettier-ignore
      fingerString += concatJointPosition("finger_dip", finger.dipPosition); //Dip is the joint closest to your nail
      fingerString += concatJointPosition("finger_pip", finger.pipPosition); //Pip is the middle joint
      fingerString += concatJointPosition("finger_mcp", finger.mcpPosition); //Mcp is th joint closest to your knucle
      fingerString += "<br>";

      frameString += fingerString;
    }

    frameString += handString;
  }

  output.innerHTML = frameString;
});

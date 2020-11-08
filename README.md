# Vrije Project - Arduino/Leap Motion

In kombinatie met de Arduino en leap Motion heb ik een rijdend voorwerp gemaakt.

- [Vrije Project - Arduino/Leap Motion](#vrije-project---arduinoleap-motion)
  - [Clone](#clone)
  - [Installeren](#installeren)
  - [Arduino](#arduino)
  - [Gebruik](#gebruik)
  - [Voorbeeld](#voorbeeld)

## Clone

Eerst moet het project clonen of de .Zip downloaden van de Gitlab pagina.

- Kloon de repository naar je lokale machine `https://git.fhict.nl/I400494/semester-5.3`
  of
- Download de zip van `https://git.fhict.nl/I400494/semester-5.3`

## Installeren

Pull packages via de terminal.

```bash
npm i socket.io, express, serialport
```

## Arduino

Zet de arduino op zo als in de volgende [link](https://www.circuito.io/app?components=10190,10190,10218,11021,395589) wordt aan gegeven (De HM-10 BLE Bleutooth 4.0 module staat gelijk aan de [SparkFun Bluetooth Mate silver](https://www.sparkfun.com/products/12576) die gebruikt is in dit project).

Upload hierna het bestand arduinoNodeJs.ino op de arduino.

## Gebruik

Zet vervolgens de server aan door het volgende commando.

```
node .\server.js
```

## Voorbeeld 

![Example](img/example.jpeg)
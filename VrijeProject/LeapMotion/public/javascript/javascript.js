var buttons = document.querySelectorAll('.buttons');

buttons.forEach(function(button) {
  button.addEventListener('click', function(){
    let direction = button.dataset.direction;
    dataSend(direction);
  });
});

function dataSend(Direction){
  console.log(Direction);
  socket.emit("check", Direction);    
};
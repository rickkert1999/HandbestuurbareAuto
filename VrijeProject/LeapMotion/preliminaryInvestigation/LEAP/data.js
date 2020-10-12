  // call this once per page, after the DOM is ready.
  window.plotter = new LeapDataPlotter();


  Leap.loop(function(frame){
    var hand = frame.hands[0];
    if (!hand) return;


    // call this once per frame per plot
    plotter.plot('height', hand.palmPosition[1], {
      precision: 3,
      units: 'mm'
    });


    plotter.plot('y velocity', hand.palmVelocity[1], {
      precision: 4,
      units: 'mm/s'
    });


    // call this once per frame
    plotter.update()

  });

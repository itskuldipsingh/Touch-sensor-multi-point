# Touch Sensor LED Toggle

This Arduino project demonstrates a simple touch sensor-controlled LED toggle. When any of the specified touch sensors are activated, it toggles the state of the LED connected to the D5 pin.

## Components Used
- Arduino board (e.g., ESP8266)
- Touch sensors (4)
- LED
- Resistors (if needed)
- Jumper wires

## Circuit Connection

Ensure you have the following connections:
- LED connected to D5
- Touch sensors connected to D0 (touch1), D1 (touch2), D2 (touch3), and D3 (touch4)

## How to Use

1. Upload the provided Arduino code to your board.
2. Connect the hardware components as per the specified connections.
3. Power up the Arduino board.
4. When any of the touch sensors (touch1 or touch2) is touched, the LED connected to D5 will toggle its state.

## Code Explanation

- The setup function configures the pin modes for the LED and touch sensors and initializes the LED to a LOW state.
- In the loop function, it checks if any of the specified touch sensors are HIGH. If true, it toggles the LED state and introduces a delay of 500 milliseconds.

Feel free to modify the code or circuit according to your requirements!

Happy tinkering!

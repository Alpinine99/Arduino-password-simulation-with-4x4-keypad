# Pin simulation with a 4x4 keypad library

## How it works

This is an simple arduino program that simulates pin entry using a 4x4 keypad module. It offers features like back space and cancellation.

## How to use it

> NOTE: You can get the library documentation from [this repo](https://github.com/Alpinine99/Arduino-keypad-library). Requirements are having an arduino or a similar avr board and a 4x4 keypad module.

- Hook up your 4x4 module as follows.

| Module pin | Arduino pin |
| ---------- | ----------- |
| R1 | 5 |
| R2 | 4 |
| R3 | 3 |
| R4 | 2 |
| C1 | 6 |
| C2 | 7 |
| C3 | 8 |
| C4 | 9 |

- [Download](https://github.com/Alpinine99/Arduino-keypad-library/archive/refs/heads/main.zip) the library zip and install it.

![install zip library](/resources/install-zip-library.gif)

- Compile and upload to your board.

- For some reason the arduino ide2 does not allow manipulation of the text on the serial monitor so I used the vscode extension [microsoft serial monitor](https://github.com/microsoft/vscode-serial-monitor) in the case of deleting already input text.

> Install the microsoft serial monitor extension on vscode to get and switch to vscode. Make sure your arduino ide serial monitor is closed before you start monitoring on vscode serial monitor.

- Open vscode and hit the start monitoring your port, you should now be set to test it out.

![How to use it](/resources/usage.gif)

> Make sure you change the baud rate as in the code it is set to `115200` and select your board before you hit start monitoring. I have used a pin of `5678`.

#include <KeypadLib.h>


/*basic script to simulate password entering with the keypad library*/

const int rows[4] = { 5, 4, 3, 2 };
const int columns[4] = { 6, 7, 8, 9 };
const char keys[4][4] = { { 'A', 'B', 'C', 'D' },
						{ '3', '6', '9', '#' },
						{ '2', '5', '8', '0' },
						{ '1', '4', '7', '*' } };

KeypadLib keypad(rows, columns, keys);

void setup() {
	// put your setup code here, to run once:
	Serial.begin(115200);
	keypad.pinSetup();
	Serial.println("[D] enter\t [C] cancel\t [B] delete");
}

void loop() {
	// put your main code here, to run repeatedly:
	static int PIN = 5678;

	char key = keypad.readKey(KeypadLib::PRESSED);
	if (key == 'D') {
		String attempt = "";
		bool unlocked = false;
		Serial.print("Enter pin: ");
		while (true) {
			key = keypad.readKey(KeypadLib::PRESSED);
			if (key == '_')
				continue;

			else if (key == 'B') {
				if (attempt.length() > 0) {
					attempt = attempt.substring(0, attempt.length()-1);
					Serial.write(8);
					Serial.print(" ");
					Serial.write(8);
				}
			}

			else if (key == 'C') {
				Serial.println("\nCancelled!");
				break;
			}

			else if (key == 'D') {
				if (PIN == attempt.toInt()) {
					Serial.println("");
					unlocked = true;
					break;
				}

				Serial.print("\nWrong pin try again!\nEnter pin: ");
				attempt = "";
			}

			else {
				Serial.print(key);
				attempt += key;
			}
		}
		if (unlocked) {
			Serial.println("horay you unlocked the pin");
		}
		else {
			Serial.println("press [D] to enter password\n\n");
		}
	}
}

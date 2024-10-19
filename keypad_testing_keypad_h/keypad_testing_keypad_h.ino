#include <Keypad.h>
#define ROW_NUM 4 // for four rows
#define COLUMN_NUM 4 // for four columns
char keys[ROW_NUM][COLUMN_NUM] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte pin_rows[ROW_NUM] = {11, 9, 10, 1}; // GPIO11, GPIO9, GPIO10,
//GPIO1 connect to the row pins
byte pin_column[COLUMN_NUM] = {34, 21, 14, 12}; // GPIO34, GPIO21,
//GPIO14, GPIO12 connect to the column pins

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM,
COLUMN_NUM );

const String password = "1738"; // change your password here
String input_password;
void setup() {
Serial.begin(9600);
input_password.reserve(32); // maximum input characters is 33, change if
//needed
}
void loop() {
char key = keypad.getKey();
if (key) {
Serial.println(key);
if (key == '*') {
input_password = ""; // clear input password
} else if (key == '#') {
if (password == input_password) {
Serial.println("The password is correct, ACCESS GRANTED!");
// DO YOUR WORK HERE
} else {
Serial.println("The password is incorrect, ACCESS DENIED!");
}
input_password = ""; // clear input password
} else {
input_password += key; // append new character to input password
//string

}
}
}

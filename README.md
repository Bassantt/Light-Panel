# Light-Panel
10*10 LEDs grid. This grid is controlled by a 10 keys keypad.
The grid has two modes:
1- Numeric mode
2- Emotions mode
As the system power on, the LEDs grid starts self-testing by turning on the first column while all other columns
turned off. The turning on the second column after 200 millisecond and turning off all other columns including
the first one. After finishing all columns, the first row is turned on while all other rows are turned off. Then, the
second row is turned on while all other rows are turned off including the first row... etc.
After completing self-testing, the grid is working in the numeric mode. In this mode, if the user pressed any key
from 0 – 9 the key is drawn on the led grid using LEDs one by one. Meaning that, the first led will open then the
second one after 100 milliseconds and so on. 

If the user entered the password (which is 1234) the system enters the emotions mode. Each key will activate
certain emotion of your choice. Therefore, it is required for to select 10 different emotions.

If the user entered the reverse of the password (which is 4321) the system returns to the numeric mode.

The user is able to change password by entering 1212 followed by four keys. For example, if the user entered
12127891 then the password to change mode from numeric mode to emotions mode is 7891 and the password to
change mode from emotions mode to numeric mode is 1987.

And a longer sound if password sequence is detected.
While drawing the number or emotion, if the user pressed any other key (other than the one to be drawn) the
system should stop drawing the current number/emotion immediately and start in the new one.
You are allowed to use (AND – OR – NAND – NOR – NOT – XOR – XNOR – Resistors) as you wish with any
number of inputs

# Password

In this challenge, the task is to manipulate the binary file "password.exe" to bypass the password check. The original code will ask you for a password and display a message based on whether the password you entered is correct or not. The goal is to patch the binary such that it always displays the "Congratulations!" message, regardless of the input.

The crucial part of the code is the cmovnz instruction, which stands for "conditional move if not zero". This instruction is part of the validation function, which compares the entered password to the correct one. The cmovnz instruction is used to choose the message to display based on the result of the comparison: if the result of the comparison is non-zero (meaning the passwords don't match), it prepares to print the "Wrong password" message.

To make the program always display the "Congratulations!" message, you need to patch the cmovnz instruction and replace it with nop (No Operation) instructions. nop is an instruction that does essentially nothing - it doesn't affect the processor flags or the execution flow, and it doesn't modify memory or registers. In other words, replacing cmovnz with nop instructions will prevent the program from ever choosing the "Wrong password" message, making it always display "Congratulations!".
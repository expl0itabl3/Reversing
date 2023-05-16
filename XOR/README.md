# XOR encryption

Let's break down this simple XOR cipher implemented in C and its corresponding disassembly in x64 assembly. This will help us understand how the C compiler translates our code into machine instructions.

## C Code
The C code first defines a simple XOR cipher function, which takes a string and a key, and performs an XOR operation on every character of the string with the key. This function is then used to encrypt and decrypt a message "Hello, World!" with the key `0x2B`.

## Assembly code
The assembly code is the result of the C compiler translating the C code into machine instructions. The compiler used here employs certain strategies such as function prologues and epilogues, which are necessary for function call conventions and stack integrity.

## Function prologue
At the beginning of the `main` function, we see a series of operations that set up the function's stack frame:
```
push    rbx
sub     rsp, 40h
mov     rax, cs:__security_cookie
xor     rax, rsp
mov     [rsp+48h+var_18], rax
```
Here, the `rbx` register is pushed onto the stack (to preserve its value as per the calling convention). The `rsp` register, which points to the top of the stack, is then decremented by `0x40` (64 in decimal) to allocate space on the stack for local variables and saved registers.

The `__security_cookie` (or "stack canary") is a random value that's placed on the stack to help detect stack buffer overflow attacks. If an attacker overflows the buffer and overwrites this value, the difference will be detected before the function returns, and the program will terminate.

## XOR cipher implementation
The XOR cipher function is implemented as a simple loop that performs the XOR operation on each character of the string:
```
loc_1400010B0:
xor     [rsp+rax+48h+secret_message], 2Bh
inc     rax
cmp     rax, 0Dh
jb      short loc_1400010B0
```
Here, the `xor` instruction performs the XOR operation on the character at the memory address calculated by `rsp+rax+48h+secret_message`, where `rax` is the loop counter. The `inc` instruction then increments `rax`, and the `cmp` instruction compares `rax` to `0Dh` (13 in decimal), which is the length of the string "Hello, World!" including the null terminator. If `rax` is less than `0Dh`, the `jb` instruction branches back to the start of the loop.

The same loop is later used to decrypt the message, with `rbx` used as the loop counter instead of `rax`.

## Function epilogue
At the end of the `main` function, we see a series of operations that clean up the function's stack frame:
```
xor     eax, eax
mov     rcx, [rsp+48h+var_18]
xor     rcx, rsp        ; StackCookie
call    __security_check_cookie
add     rsp, 40h
pop     rbx
retn
```
Here, `eax` is cleared (set to 0) before the `__security_check_cookie` function is called to verify that the `__security_cookie` has not been tampered with. If the `__security_cookie` is intact, the function returns, the stack pointer is incremented to deallocate the local variables, the saved `rbx` register is popped off the stack, and the function returns (`retn`).

## Printing the result
After each XOR cipher operation, the program prints the result:
```
lea     rdx, [rsp+48h+secret_message]
lea     rcx, _Format    ; "The encrypted message is: %s\n"
call    printf
```

Here, the `lea` instructions load the address of the `secret_message` string and the format string into `rdx` and `rcx`, respectively. The `printf` function is then called to print the message.
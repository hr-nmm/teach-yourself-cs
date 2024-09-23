# ch4: Binary and data representaion

## introduction

- Whether there’s a laser scanning the surface of a DVD or a disk head gliding over a magnetic plat­ter, the output from the storage device is ultimately a sequence of electrical signals in binary.
- Binary signal has one of 2 states:
  1. the absence of a voltage (interpreted as zero)
  2. the presence of a voltage (one).
- A sequence of N bits can represent 2^N unique values, eg: a single bit represents 2 vals: 0 and 1. Two bits can represent four values(00 01 10 11) and so on..
- 1 byte = 8 bits (representing 2^8= 256 values) enough for a character(letter/punctuation).

- Bytes are the smallest unit of **addressable memory** in a computer sys­tem meaning that a program can’t ask for fewer than eight bits to store avariable.

- **word size** (or word length) refers to the number of bits processed by a computer's CPU in a single operation and it (32/64 bit) uses to move data from one component to another (e.g., between memory and registers).

- Any information can be encoded in binary, including rich data like graphics and audio, eg: image's smallest unit is pixel(just like a sentence's smallest unit is alphabet) and each pixel is allocated 4 bytes which can represent any of 2^32 = 16.7million color and millions of these pixels make up an image.

## 4.1 Number bases and unsigned integers

- unsigned means 0 or +ve.
- representation eg: 13(decimal/base10) == **0b**1101(binary/base2) == **0x**D(hexadecimal/base16)
- 13 = 1 \* 2^3 + 1 \* 2^2 + 0 \* 2^1 + 1 \* 2^0
- while adding 2 bin nos(vertically)
  => 0+0 = 0
  => 1+0 = 0+1 = 1
  => 1+1 = 0 with carry 1
- Systems => decimal : comfortable for humans, binary: matches the way data is stored in hardware, hexadecimal: convinience for reading memory-addresses.

- system’s main memory is typically large but storage locations inside the CPU that are used as temporary “scratch space”(CPU registers that are limited to its word size).
- data flow while saving data: ip device to CPU registers and then to main memory(HDD/ssd).
- As values get larger, storage devices need more wires to communicate signals between them. Hence, expanding storage increases the complexity of the hardware and leaves less physical space for other components.
- Integer overflow - attempt to store a value larger than its allocated memory/variable size.

## 4.2 Converting bw bases

- hex to bin: eg 0xB491 =(dont try to convert into base10 first, since 2^4=16 pick repr of 1 hex bit to 4 bin bits and map them)
  --B-- 4--- 9--- 1
  1011 0100 1001 0001 -> 0b1011010010010001

## 4.3 Signed binary numbers

- 2 ways signed binary encodings:

  1. **Singned magnitude**: leftmost bit is reserved for sign negative (1) or non­negative (0).

  - To negate a value, simply flip the most significant bit to change its sign.
  - eg of 4-bit signed-magnitude:
    1111 is -7, 1110 is -6, 1101 is -5,1100 is -4,1011 is -3,1111 is -2,1010 is -1,1001 is -0
    0111 is +7, 0110 is +6, 0101 is +5,0100 is +4,0011 is +3,0010 is +2,0001 is +1,0000 is +0
  - Two disadvantages : 1. it presents two reps of zero 2.adding 1 to the four­ bit sequence eg, say 0b1111 “rolls over” back to 0b0000. With signed magnitude, this effect means 0b1111 (–7) + 1 might be mistaken for 0 rather than the ex­pected –6.

  2. **Two’s Complement**: leftmost bit represents sign but in contrast it also affects the value of the number.

  - +ve nos are represented as usual in binary of their **remaining counterpart**
  - eg: 0110 => LSB is 0 means +ve no. => 110(remaining counterpart) = 2^2\*1 + 2^1\*1 + 2^1\*0 = +6
  - -ve nos are represented by taking the two's complement of their **positive counterpart**.
  - 2's complement has 2 steps:1. invert the bits and 2. add 1(binary addition)
  - eg: 1011 => LSB is 1 means -ve no. => 011(remaining counterpart) =>1. invert =100 => 2. add 1=> 101 which is 5 => hence ans is -5.
  - both disadvantages solved: 1. reps of 2 zeros: 1000 now reps -8 and 2.adding bit makes sense 0b1111 + 1 = 0b0000 i.e, -1 + 1 = 0.
  - Negation :to negate an N­bit value X, find a bit sequence Y(your negation answer) (X’s complement) such that X + Y = 2^N and flip Y.
    - ADD 1 to both sides of eq.n (2^N + 1 = 0) => X+Y+1 = 0 => SUB X-1 from both sides => Y = -(X-1) => Y = 1-X => Y = 1 + (2's complement of **X's counterpart**)
    - but adding 1 means the 2's complement of the whole thing.
    - Y is 2's compliment of the whole byte/number(note: not only the remaining counterpart)
  - ANOTHER advantage of 2's complement is that we can stuff leading 0s and 1s without affecting the value. It is very usable in sign extension

- **Sign extension** in C refers to the process of increasing the bit-width of a signed integer while preserving its sign (positive or negative) and value. This is particularly important when converting smaller signed data types (like int8_t or int16_t) to larger types (like int32_t or int64_t)(generally for arithmetic purposes).

- 2 step process: identify the sign and extend the bits by adding leading 0's/1's.
- For positive numbers, leading zeros are added to fill the new bits. For negative numbers, leading ones are added to maintain the negative value. this number is converted to a 16-bit integer, it becomes 11111111 11111101, where additional leading ones are added to maintain its sign.
- eg: in memory calculation(2's complement of counterpart):
  0b1011 = -8 + 0 + 2 + 1 = -5
  0b11011 = -16 + 8 + 0 + 2 + 1 = -5
  0b111011 = -32 + 16 + 8 + 0 + 2 + 1 = -5
  0b1111011 = -64 + 32 + 16 + 8 + 0 + 2 + 1 = -5
  0b11111011 = -128 + 64 + 32 + 16 + 8 + 0 + 2 + 1 = -5

## 4.4 Binary Integer Arithmetic

- Hardware designers build same hardware components for both unsigned and signed operations because encoding does not matter to the arithmetic pro­cedures whether we choose to interpret the operands or result as signed or unsigned.
- 1(digitA) + 1(digitB) +1(carryIN) = 1(result/sum) + 1(carryIN)

- 4-bit sequence represents values in the range 0to15(unsigned) and -8 to +7(signed).
- Overflow :unsigned example=> 0b1100 (12) + 0b0111 (7) is 0b10011. While perform­ing four­bit arithmetic, there’s nowhere to put the carry out’s extra bit, sothe hardware simply drops or **truncates** it, leaving 0b0011 as the result. Of course, if the goal was to add 12 + 7, a result of 3 is likely to be surprising. This is an example of integer overflow.

- **Subtraction** X-Y = X + (-Y) => first negate 2nd operand and then binary-add.
- To **multiply** binary numbers, use the common pencil­and­paper strategy of considering one digit at a time and adding the results.
- Binary **division** usesthe same long form method that most students learn in grade school.

## 4.5 Integer Overflow

- Integer overflow occurs when an arithmetic operation moves be­tween the minimum and maximum values that its result can represent.
- If N= no of bits, overflow happens when => result > 2^N-1(for un-signed) and result > 2^(N-1) -1 || result < -2^(N-1) (for signed).

- Overflows can break programs, fact: PSY's gangnam style threatened overflow in 32-bit int for views count. youtube then switched to 64-bit. Also reason why famous "half board glitch" happened when an expert pacman player won level 255 of pacman(8-bit games).

## 4.6 Bitwise Operators

- CPUs support bitwise operators in addition to standard arithmetic operations like addition and subtraction. These bitwise operators directly implement the behavior of basic logic gates like AND, OR, and XOR.
- Bitwise operators are straightforward to implement efficiently in hardware, making them fast to execute.

- Bitwise AND(&) => finds 1st falsy(0) and returns, if falsy not present return 1. eg,26 & 54 = 18
- Bitwise OR(|) => finds 1st truth(1) and returns, if truthy not present return 0. eg,26 | 54 = 62
- Bitwise XOR(^) => behaves like the bitwise OR operator except that it outputs a 1 for a digit only if exactly one (but not both) of the inputs is 1 in the corresponding position. eg,26 ^ 54 = 44
- Bitwise NOT(~) => flips the bit. eg, ~26 = -27 because it only flips and does not add 1.

- Bitwise Left-shift (a << b) => shifts the bits(stuffs 0's) of a number to the left by a specified number of positions. Each shift to the left effectively multiplies the number by 2 for each position shifted. eg: 13 << 3 = 104 coz, 13\*(2\*\*3) = 104 => 1101 becomes 1101000
- Bitwise Right-shift (a << b) => shifts the bits of a number to the right by a specified number of positions. Each shift to the left effectively divides the number by 2 for each position shifted. eg: 104 >> 3 = 13 coz, 104\*(2\*\*3) = 104 => 1101000 becomes 1101

- right shifting introduces an additional consideration: the new bits prepended to the left side of the result may need to be either all zeros or all ones depending on the type of the variable being shifted and its high­order bit value.
- for unsigned variables **logical right** shift prepends zeros to the high­order bits of the result.
  eg: 0b101100**11** >> 2 => 0b**00**101100
- for signed variables **arithmetic right** shift happens where it prepends a copy of the shifted value’s most significant bit into each of the new bit positions.
  eg: 0b101100**11** >> 2 => 0b**11**101100
  0b001100**10** >> 2 => 0b**00**101100

## 4.7 Byte Order

- The byte order (or endianness) of a system defines how its hardware as­signs the bytes of a multibyte variable to consecutive memory addresses.
  eg: short x = 0xABCD(hex) ; at address 0x1008
  - a short has 2 bytes it can be stored at either with order(**ABCD** @ 0x1008-0x1011 ) or with order (**DCBA** @ 0x1008-0x1011)
- x86 CPUs store integers in a little­endian format—from least­significant byte (“little end”) to the most­significant byte in consecutive addresses.

### important programming tool: to visualize bytes in c program use 0x hex nos coz 2 hex digits make up 1 byte.

## 4.8 Real numbers in binary

- real number encodings typically store only approximations of values that have been truncated to a predeter­ mined number of bits
- there are two methods for repre­senting real numbers in binary: **fixed­-point**, which extends the binary integer format, and **floating­point**, which represents a large range of values at the cost of some extra complexity.

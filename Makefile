#  Daniel Alemu G00884794
#  CS 262, Lab Section 207
#  Lab 7
#  The Compiler: gcc for C programs, g++ for C++ programs, etc

all:AsciiToBinary_dalemu2_207 BinaryToAscii_dalemu2_207
AsciiToBinary_dalemu2_207:
	gcc -Wall -o AsciiToBinary AsciiToBinary_dalemu2_207.c

BinaryToAscii_dalemu2_207:
	gcc -Wall -o BinaryToAscii BinaryToAscii_dalemu2_207.c

clean:
	rm AsciiToBinary BinaryToAscii

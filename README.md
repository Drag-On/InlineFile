InlineFile
==========

Converts binary files into code.

Q: It does WHAT?
A: It reads in a binary file and outputs a c++11 source file defining a char array holding exactly the bytes of the input file.

Q: Why would you need something like this?
A: Probably never. If you think you need it, reconsider. There is a reason why data and code should stay separate.

Q: And for what reason did you create it?
A: I don't listen to my own advice. I wanted to bundle a very small amount of binary data with a program of mine in order to guarantee that there's always something to fall back to.

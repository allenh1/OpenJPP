Build Instructions:
===================

```
$ qmake
$ make
```


Usage:
======
1. The file extension of your OpenJ++ source does not matter, but I am using *.jpp currently. The syntax is basically that of Java, but we added a way to do pointers, and will soon have a method of overloading operators in a C++ fashion (Syntax guide will appear shortly after things are compiling).

```
$ OpenJ++ example.jpp
```

Description:
============
 - This is a simple C++ application that extends some Java syntax.
 - Provides pointers, 
 - Generates the code as Java code, then calls javac.
 - The code also attempts to optimize the code somewhat.
 - Outputs the number of lines modified.


Contributions:
==============
 - Generally, no contributions will be accepted if they don't compile.
 - Also, no warnings are to be generated in compile phase.
 - Otherwise, feel free to contribute!

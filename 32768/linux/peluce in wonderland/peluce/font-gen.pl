#!/usr/bin/perl

$_=<<EOF;

.......
.......
.......
.......
.......

x*****x
**...**
*******
**...**
**...**

******+
**...**
******+
**...**
******+

x*****x
**...**
**.....
**.....
x******

******+
**...**
**...**
**...**
******+

+******
**.....
****...
**.....
*******

+******
**.....
****...
**.....
**.....

x******
**.....
**.****
**...**
x*****x

**...**
**...**
*******
**...**
**...**

******.
.+**+..
..**...
.+**+..
******.

..+****
.....**
.....**
**+.+**
x*****x

**..+**
**.+**.
*****..
**.+**.
**..+**

**.....
**.....
**.....
**.....
*******

x**x**x
*******
**+*+**
**.+.**
**...**

******x
**...**
**...**
**...**
**...**

x*****x
**...**
**...**
**...**
x*****x

x*****x
**...**
******x
**.....
**.....

x*****x
**...**
**..+x*
**..x**
x******

*******
**...**
*******
*****+.
**.+***

x******
**.....
x*****x
.....**
******x

******.
..**...
..**...
..**...
..**...

**...**
**...**
**...**
**...**
x*****x

**...**
**...**
**x.x**
+**x**+
.+***+.

**...**
**...**
**.*.**
**x*x**
***+***

**..**.
.****..
.+**+..
.****..
**..**.

**...**
**...**
x******
.....**
....x*x

*******
...x**+
.+***+.
+**x...
*******

..x**..
..***..
...**..
...**..
*******

x*****x
**...**
x******
.....**
******x

.......
.......
x*****x
.......
.......

*x.*.x*
..***..
x**.**x
*******
**...**

*x...x*
.......
*******
**...**
*******
EOF

 s/x/0x77\,/g;
s/\./0x00\,/g;
s/\*/0xff\,/g;
s/\+/0x88\,/g;
print "char pwpfont[][5*7]=\n{$_};\n";

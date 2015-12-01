A mixture of tr and sed, incomplete
===================================

This project actually developed when I wanted a
fast way to remove Javascript from webpages
(for (mkdict)[www.github.com/scharlatan/mkdict])
without having to write some dirty and specialised.
So I ended up writing something dirty.

skip(1) is sort of a mixture of tr and sed.
It simply skip the text between two strings
of it's standard input.

skip(1) is neithet line-agnostic, nor capable of handling
regular expressions, nor flexible or (gasp!) programmable.
Take a look at the manpage.

Installation
============

I assume you have everything you need
for compiling and installing this project (make and a c compiler).
Then
	make install
is enough.

License
=======

Look at the file COPYING.

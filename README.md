Skip text between two strings
=============================

This project was developed when I wanted a
fast way to remove Javascript from webpages
(for [mkdict](https://www.github.com/scharlatan/mkdict))
without having to write some dirty and specialised.
So I ended up writing something dirty.

skip simply skips the text between two strings
of it's standard input.

skip is neither line-agnostic, nor capable of handling
regular expressions, nor flexible or (gasp!) programmable.
Take a look at the manpage.

Installation
------------

I assume you have everything you need
for compiling and installing this project (make and a c compiler).
Then

	make install

is enough.

License
-------

Look at the file COPYING.

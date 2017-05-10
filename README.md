Skip text between two strings
=============================

skip removes all of its input that is enclosed by
its two arguments. Example:

	$ echo '/* comment */ int main(void) { puts("hello world!"); /* print */ return 0; }' | skip '/*' '*/'
	 int main(void) { puts("hello world!");  return 0; }

skip is neither line-agnostic, nor capable of handling regular
expressions, nor flexible or programmable.

Installation
------------

Run

	make install

License
=======

[MIT/X11 license](./LICENSE).

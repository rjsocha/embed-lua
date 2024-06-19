all: embed-lua

embed-lua: embed-lua.c
	gcc -o embed-lua -s embed-lua.c /usr/lib/x86_64-linux-gnu/liblua5.4.a -I/usr/include/lua5.4 -lm

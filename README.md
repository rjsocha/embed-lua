# (POC) - embed lua script within executable

## "linking"

```
./link-script main.lua
```

## static build
  embed-lua was compiled with musl-gcc

```
gcc -Os embed-lua.c -o embed-lua /usr/lib/lua5.3/liblua.a -lm -o embed-lua -I/usr/include/lua5.3 -static
```

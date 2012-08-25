CFLAGS = -Wall -g
all:
	cc mapper.c -o obj/mapper lexMap/keyMapper.c regex.c -lpcre
	cc looper.c -o obj/looper
#	cc regex.c -o obj/regex -lpcre
clean:
	rm -f obj/mapper obj/looper obj/regex

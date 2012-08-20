CFLAGS = -Wall -g
all:
	cc mapper.c -o obj/mapper lexMap/keyMapper.c
	cc looper.c -o obj/looper
clean:
	rm -f obj/mapper obj/looper

CFLAGS = -Wall -g
all:
	gcc mapper.c $(CFLAGS) -o obj/mapper lexMap/keyMapper.c regex.c -lpcre
	gcc looper.c $(CFLAGS) -o obj/looper
#	gcc regex.c -o obj/regex -lpcre
clean:
	rm -f obj/mapper obj/looper obj/regex

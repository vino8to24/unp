CC = gcc
#CFLAGS = -c -lunp
all: server client
server: tcpserver01.c
	$(CC) -o server tcpserver01.c -lunp
client: tcpcli01.c
	$(CC) -o client tcpcli01.c -lunp

#server.o: tcpserver01.c
#	$(CC) $(CFLAGS) $<
#client.o: tcpcli.c
#	$(CC) $(CFLAGS) $<


.PHONY: clean
clean:
	rm all
	rm -f *.o

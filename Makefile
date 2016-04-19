CC = gcc
CFLAGS = -g
PROG = bomb_prep


$(PROG) : bomb_prep.c phases.c phases.h
	$(CC) $(CFLAGS) -o $@ bomb_prep.c phases.c


clean :
	-rm -f $(PROG)

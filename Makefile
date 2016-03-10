
CC=clang
CFLAGS:=-DNO_SMACK

insertion_sort: insertion_sort.c
	$(CC) $(CFLAGS) insertion_sort.c -o insertion_sort

sum: sum.c
	$(CC) $(CFLAGS) -lpthread sum.c -o sum
CC = gcc -std=c99
CC2 = g++
ARGS = -O3 -Wall -funroll-loops -ffast-math -lm

all: e26 e27 e28 e30 e31 e32 e33 e34 e35 e36 e37 e38 e39 e41 e42 e43 e44 e46 e47 e49 e50

e26:
	$(CC) euler26.c -o linux_bin/eu26 $(ARGS)

e27:
	$(CC) euler27.c -o linux_bin/eu27 $(ARGS)

e28:
	$(CC) euler28.c -o linux_bin/eu28 $(ARGS)

e30:
	$(CC) euler30.c -o linux_bin/eu30 $(ARGS)

e31:
	$(CC) euler31.c -o linux_bin/eu31 $(ARGS)

e32:
	$(CC) euler32.c -o linux_bin/eu32 $(ARGS)

e33:
	$(CC) euler33.c -o linux_bin/eu33 $(ARGS)

e34:
	$(CC) euler34.c -o linux_bin/eu34 $(ARGS)

e35:
	$(CC) euler35.c -o linux_bin/eu35 $(ARGS)

e36:
	$(CC) euler36.c -o linux_bin/eu36 $(ARGS)

e37:
	$(CC) euler37.c -o linux_bin/eu37 $(ARGS)

e38:
	$(CC) euler38.c -o linux_bin/eu38 $(ARGS)

e39:
	$(CC) euler39.c -o linux_bin/eu39 $(ARGS)

e41:
	$(CC) euler41.c -o linux_bin/eu41 $(ARGS)

e42:
	$(CC) euler42.c -o linux_bin/eu42 $(ARGS)

e43:
	$(CC) euler43.c -o linux_bin/eu43 $(ARGS)

e44:
	$(CC) euler44.c -o linux_bin/eu44 $(ARGS)

e46:
	$(CC) euler46.c -o linux_bin/eu46 $(ARGS)

e47:
	$(CC) euler47.c -o linux_bin/eu47 $(ARGS)

e49:
	$(CC) euler49.c -o linux_bin/eu49 $(ARGS)

e50:
	$(CC) euler50.c -o linux_bin/eu50 $(ARGS)

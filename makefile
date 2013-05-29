CC = gcc -std=c99
CC2 = g++
ARGS = -O3 -Wall -funroll-loops -ffast-math -lm
TARGET_DIR = linux_bin

all: e26 e27 e28 e30 e31 e32 e33 e34 e35 e36 e37 e38 e39 e41 e42 e43 e44 e46 e47 e49 e50

e26:
	$(CC) euler26.c -o $(TARGET_DIR)/eu26 $(ARGS)

e27:
	$(CC) euler27.c -o $(TARGET_DIR)/eu27 $(ARGS)

e28:
	$(CC) euler28.c -o $(TARGET_DIR)/eu28 $(ARGS)

e30:
	$(CC) euler30.c -o $(TARGET_DIR)/eu30 $(ARGS)

e31:
	$(CC) euler31.c -o $(TARGET_DIR)/eu31 $(ARGS)

e32:
	$(CC) euler32.c -o $(TARGET_DIR)/eu32 $(ARGS)

e33:
	$(CC) euler33.c -o $(TARGET_DIR)/eu33 $(ARGS)

e34:
	$(CC) euler34.c -o $(TARGET_DIR)/eu34 $(ARGS)

e35:
	$(CC) euler35.c -o $(TARGET_DIR)/eu35 $(ARGS)

e36:
	$(CC) euler36.c -o $(TARGET_DIR)/eu36 $(ARGS)

e37:
	$(CC) euler37.c -o $(TARGET_DIR)/eu37 $(ARGS)

e38:
	$(CC) euler38.c -o $(TARGET_DIR)/eu38 $(ARGS)

e39:
	$(CC) euler39.c -o $(TARGET_DIR)/eu39 $(ARGS)

e41:
	$(CC) euler41.c -o $(TARGET_DIR)/eu41 $(ARGS)

e42:
	$(CC) euler42.c -o $(TARGET_DIR)/eu42 $(ARGS)

e43:
	$(CC) euler43.c -o $(TARGET_DIR)/eu43 $(ARGS)

e44:
	$(CC) euler44.c -o $(TARGET_DIR)/eu44 $(ARGS)

e46:
	$(CC) euler46.c -o $(TARGET_DIR)/eu46 $(ARGS)

e47:
	$(CC) euler47.c -o $(TARGET_DIR)/eu47 $(ARGS)

e49:
	$(CC) euler49.c -o $(TARGET_DIR)/eu49 $(ARGS)

e50:
	$(CC) euler50.c -o $(TARGET_DIR)/eu50 $(ARGS)

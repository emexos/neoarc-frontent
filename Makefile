CC = gcc
CFLAGS = -std=c99 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -O2 -Isrc/lib
LFLAGS = -Lsrc/lib -lfrecli -lm

SRC = src/main.c
TARGET = neoarc_f

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< $(LFLAGS) -o $@

clean:
	rm -f $(TARGET)

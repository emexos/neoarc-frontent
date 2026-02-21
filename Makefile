CC = gcc
CFLAGS = -std=c99 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -O2 -Isrc/lib
LFLAGS = -Lsrc/lib -lfrecli -lm

SRCS = src/main.c src/gfc.c src/gen/gen.c src/ui/screen/sidebar.c src/ui/screen/main.c src/ui/games/games.c
TARGET = neoarc_f

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LFLAGS) -o $@

run:
	@chmod +x $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)

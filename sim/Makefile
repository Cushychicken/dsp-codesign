CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm

SRCS = fir_main.c fir_filter.c
OBJS = $(SRCS:.c=.o)
TARGET = fir_filter

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c fir_filter.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)


CFLAGS= -std=gnu11 -O3 -Wall -g -include all.h 
LDFLAGS= -lprocps
all: ProgressiveV

.PHONY:clean
clean:
	rm ProgressiveV

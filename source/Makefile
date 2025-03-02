objs  = main.o pa.o help.o
avoid = -Wno-switch
flags = -Wall -Wextra -Wpedantic $(avoid)
exec  = pf
cc    = gcc

all: $(exec)

$(exec): $(objs)
	$(cc)	-o $(exec) $(objs)
%.o: %.c
	$(cc)	-c $(flags) $<
clean:
	rm	-rf $(objs) $(exec)

Obj:=$(patsubst %.c,%.o,$(wildcard *.c))

calc.exe:$(Obj)
	gcc -o $@ $^

clean:
	rm *.exe *.o
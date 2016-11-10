all:
	gcc signals.c -o signals

run: signals
	./signals

clean:
	rm *~

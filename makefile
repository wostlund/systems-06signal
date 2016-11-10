compile: sig.c
	gcc sig.c -o driver

run: driver
	./driver

clean: *~
	rm *~

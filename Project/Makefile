all: \
a

compile:
	gcc -o sud2sat.out sud2sat.c
	gcc -o sat2sud.out sat2sud.c
	gcc -o sud2sathard.out sud2sathard.c
a:
	gcc -o sud2sat.out sud2sat.c
	./sud2sat.out $(ARG1) $(ARG2)

b:
	gcc -o sat2sud.out sat2sud.c
	./sat2sud.out $(ARG1) $(ARG2)

c:
	gcc -o sud2sat.out sud2sat.c
	./sud2sat.out $(ARG1) $(ARG2)

clean:
	rm first.in
	rm sud2sat.out

target:
	

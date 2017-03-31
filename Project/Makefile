all: \
a

compile:
	gcc -o sud2sat.out sud2sat.c
	gcc -o sat2sud.out sat2sud.c
	gcc -o sud2sathard.out sud2sathard.c
a:
	gcc -o sud2sat.out sud2sat.c
	./sud2sat.out input.txt first.in

b:
	gcc -o sat2sud.out sat2sud.c
	./sat2sud.out first.out done.txt

c:
	gcc -o sud2sat.out sud2sat.c
	./sud2sat.out grid01hard.txt hardfirst01.in

clean:
	rm first.in
	rm sud2sat.out

target:
	

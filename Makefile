all: life

life:
	g++ -fcilkplus life.cpp -o life
	g++ -DCILK_SERIALIZE life.cpp -o life_serial

compare:
	g++ compare.cpp -o compare

test: life compare
	./test_life.sh

clean:
	rm -f life life_serial compare result.txt

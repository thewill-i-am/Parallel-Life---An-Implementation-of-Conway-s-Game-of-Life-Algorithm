# test 1: still structure (block)
CILK_NWORKERS=16 ./life 10 100 test_life_1.txt > result.txt
./compare 100 result.txt result_life_1.txt
# test 2: still structure (beehive)
CILK_NWORKERS=16 ./life 6 200 test_life_2.txt > result.txt
./compare 36 result.txt result_life_2.txt
# test 3: oscillator (pulsar), period 3
CILK_NWORKERS=16 ./life 17 99 test_life_3.txt > result.txt
./compare 389 result.txt result_life_3.txt
# test 4: spaceship (glider), period 4, offset x+1 y+1
CILK_NWORKERS=16 ./life 10 28 test_life_4.txt > result.txt
./compare 100 result.txt result_life_4.txt
# removing result.txt file
rm -f result.txt

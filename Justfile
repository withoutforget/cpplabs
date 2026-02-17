@run file='':
    g++ -O3 --std=c++20 {{ file }} -o ./bin/a.out && ./bin/a.out
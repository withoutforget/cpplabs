@run file='':
    g++ -O3 --std=c++23 {{ file }} -o ./bin/a.out && ./bin/a.out
@init:
    mkdir bin
@clean:
    rm -rf ./bin/


@lint file='':
    clang-format -i {{ file }}


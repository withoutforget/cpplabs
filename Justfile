@run dir='src':
    g++ -O3 --std=c++23 {{ dir }}/*.cpp -o ./bin/a.out && ./bin/a.out
@init:
    mkdir bin
@clean:
    rm -rf ./bin/

@lint dir='.':
    find {{ dir }} \( -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) | xargs clang-format -i
#!/bin/bash
for filepath in src/*.c; do
    filename=$(basename $filepath)
    name=${filename%.c}
    gcc -I$(pwd)/include -c $filepath -o bin/obj/$name.o
done

gcc bin/obj/*.o -o bin/out/main

rm -f bin/obj/*.o
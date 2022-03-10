#!/bin/bash

cmake .
make

mkdir -p test-logs

for file in testing/input_*.txt; do
    valgrind \
        --leak-check=full \
        --show-leak-kinds=all \
        --track-origins=yes \
        ./task-scheduler < "$file" \
        2> "tmp/$(basename $file).log"
done

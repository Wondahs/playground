#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

file_name="$1"

if [ ! -f "$file_name" ]; then
    echo "File '$file_name' does not exist"
    exit 1
fi

# Define the factor function
factor() {
    local num=$1
    local i=2
    local half=$((num / 2))
    while [ $(echo "$i <= $half" | bc) -eq 1 ]; do
        if [ $(echo "$num % $i" | bc) -eq 0 ]; then
            fact=$(echo "$num / $i" | bc)
            echo "$num=$i*$fact"
            break
        else
            i=$((i + 1))
        fi
    done
}

while IFS= read -r line; do
    factor "$line"
done < "$file_name"


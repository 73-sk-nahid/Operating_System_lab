#!/bin/bash

declare -a a
declare -a frame

printf "Enter the number of pages: "
read n

printf "Enter the page numbers:\n"
for ((i = 1; i <= n; i++))
do
    printf "Page %d: " "$i"
    read a[$i]
done

printf "Enter the number of frames: "
read no

for ((i = 0; i < no; i++))
do
    frame[$i]=-1
done

j=0
printf "\nRef String\tPage Frames\n"
for ((i = 1; i <= n; i++))
do
    printf "%d\t\t" "${a[$i]}"
    avail=0

    for ((k = 0; k < no; k++))
    do
        if [ "${frame[$k]}" -eq "${a[$i]}" ]; then
            avail=1
            break
        fi
    done

    if [ "$avail" -eq 0 ]; then
        frame[$j]=${a[$i]}
        j=$(( (j + 1) % no ))
        count=$((count + 1))

        for ((k = 0; k < no; k++))
        do
            printf "%d\t" "${frame[$k]}"
        done
    fi
    printf "\n"
done

printf "Total Page Faults: %d\n" "$count"


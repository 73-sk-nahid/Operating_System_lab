#!/bin/bash

print() {
    local frameno=$1
    local frame=("$@")
    for ((j=0; j<$frameno; ++j))
    do
        printf "%d\t" "${frame[$j]}"
    done
    printf "\n"
}

read -p "Enter the number of pages: " n
printf "Enter the page reference numbers: "
read -a page
read -p "Enter the number of frames: " frameno

for ((i=0; i<frameno; ++i))
do
    frame[$i]=-1
done

count=0
move=0
declare -a count1

printf "Page reference string\tFrames\n"

for ((i=0; i<n; ++i))
do
    printf "%d\t\t\t" "${page[$i]}"
    flag=0

    for ((j=0; j<frameno; ++j))
    do
        if [[ ${page[$i]} -eq ${frame[$j]} ]]
        then
            flag=1
            count1[$j]=$((count1[$j]+1))
            printf "No replacement\n"
            break
        fi
    done

    if [[ $flag -eq 0 && $count -lt $frameno ]]
    then
        frame[$move]=${page[$i]}
        count1[$move]=1
        move=$(( (move+1) % frameno ))
        count=$((count+1))
        print $frameno "${frame[@]}"
    elif [[ $flag -eq 0 ]]
    then
        repindex=0
        leastcount=${count1[0]}

        for ((j=1; j<frameno; ++j))
        do
            if [[ ${count1[$j]} -lt $leastcount ]]
            then
                repindex=$j
                leastcount=${count1[$j]}
            fi
        done

        frame[$repindex]=${page[$i]}
        count1[$repindex]=1
        count=$((count+1))
        print $frameno "${frame[@]}"
    fi
done
printf "\nNumber of page faults is %d\n" $count

#!/bin/bash

pageFaultCount=0
declare -a pages
declare -a memory
memoryIndex=0

printf "Enter number of pages: "
read numberOfPages

printf "Enter the pages:\n"
for ((i = 0; i < numberOfPages; i++))
do
    read pages[$i]
done

printf "Enter number of frames: "
read numberOfFrames

for ((i = 0; i < numberOfFrames; i++))
do
    memory[$i]=-1
done

printf "The Page Replacement Process is -->\n"
for ((i = 0; i < numberOfPages; i++))
do
    for ((j = 0; j < numberOfFrames; j++))
    do
        if [ ${memory[$j]} -eq ${pages[$i]} ]
        then
            break
        fi
    done

    if [ $j -eq $numberOfFrames ]
    then
        memory[$memoryIndex]=${pages[$i]}
        memoryIndex=$((memoryIndex+1))
        pageFaultCount=$((pageFaultCount+1))
    fi

    for ((k = 0; k < numberOfFrames; k++))
    do
        printf "\t%s" "${memory[$k]}"
    done

    if [ $j -eq $numberOfFrames ]
    then
        printf "\tPage Fault No: %d" $pageFaultCount
    fi

    printf "\n"

    if [ $memoryIndex -eq $numberOfFrames ]
    then
        memoryIndex=0
    fi
done

printf "The number of Page Faults using FIFO is: %d\n" $pageFaultCount

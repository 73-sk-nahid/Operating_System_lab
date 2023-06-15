#!/bin/bash

declare -a q p c c1 d f b c2
k=0
c=0

printf "Enter the number of pages: "
read n

printf "Enter the reference string: \n"
for ((i=0; i<n; i++))
do
    printf "String %d: " "$i"
    read p[i]
done

printf "Enter the number of frames: "
read f

q[k]=${p[k]}
printf "\nFor ${p[k]} : ${q[k]}\n"
((c++))
((k++))

for ((i=1; i<n; i++))
do
    c1=0

    for ((j=0; j<f; j++))
    do
        if [[ ${p[i]} -ne ${q[j]} ]]
        then
            ((c1++))
        fi
    done

    if [[ c1 -eq f ]]
    then
        ((c++))

        if [[ k -lt f ]]
        then
            q[k]=${p[i]}
            ((k++))

            for ((j=0; j<k; j++))
            do
                printf "\t%s" "${q[j]}"
            done

            printf "\n"
        else
            for ((r=0; r<f; r++))
            do
                c2[r]=0

                for ((j=i-1; j<n; j--))
                do
                    if [[ ${q[r]} -ne ${p[j]} ]]
                    then
                        ((c2[r]++))
                    else
                        break
                    fi
                done
            done

            for ((r=0; r<f; r++))
            do
                b[r]=${c2[r]}
            done

            for ((r=0; r<f; r++))
            do
                for ((j=r; j<f; j++))
                do
                    if [[ ${b[r]} -lt ${b[j]} ]]
                    then
                        t=${b[r]}
                        b[r]=${b[j]}
                        b[j]=$t
                    fi
                done
            done

            for ((r=0; r<f; r++))
            do
                if [[ ${c2[r]} -eq ${b[0]} ]]
                then
                    q[r]=${p[i]}
                fi

                printf "\t%s" "${q[r]}"
            done

            printf "\n"
        fi
    else
        printf "For ${p[i]} :No page fault!\n"
    fi
done

printf "\nTotal number of page faults using LRU: %d\n" "$c"

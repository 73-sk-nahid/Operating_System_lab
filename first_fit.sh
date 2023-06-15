#!/bin/bash

max=25

declare -a frag
declare -a b
declare -a f
declare -a bf
declare -a ff

printf "Enter the number of blocks: "
read nb

printf "Enter the number of files: "
read nf

printf "Enter the size of the blocks:\n"
for ((i=1; i<=nb; i++))
do
    printf "Block %d: " "$i"
    read b[$i]
done

printf "Enter the size of the files:\n"
for ((i=1; i<=nf; i++))
do
    printf "Files %d: " "$i"
    read f[$i]
done

for ((i=1; i<=nf; i++))
do
    for ((j=1; j<=nb; j++))
    do
        if [[ ${bf[$j]} != 1 ]]
        then
            temp=$((b[$j] - f[$i]))
            if [[ $temp -ge 0 ]]
            then
                    ff[$i]=$j
                    break
            fi
        fi
    done
    frag[$i]=$temp
    bf[${ff[$i]}]=1
done

printf "\nFile_no \tFile_size \tBlock_no \tBlock_size \tFragment\n"
for ((i=1; i<=nf; i++))
do
    printf "%d\t\t%d\t\t%d\t\t%d\t\t%d\n" "$i" "${f[$i]}" "${ff[$i]}" "${b[${ff[$i]}]}" "${frag[$i]}"
done


#!/bin/bash

cd $(dirname $0)

ts_list=(`ls translations/*.ts`)

for ts in "${ts_list[@]}"
do
    printf "\nprocess ${ts}\n"
    /usr/lib/qt6/bin/lupdate -no-obsolete Printer.pro -ts "${ts}"
done

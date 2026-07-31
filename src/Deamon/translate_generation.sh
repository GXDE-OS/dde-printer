#!/bin/bash
# this file is used to auto-generate .qm file from .ts file.
# author: shibowen at linuxdeepin.com

cd $(dirname $0)

/usr/lib/qt6/bin/lupdate -no-obsolete Deamon.pro -ts translations/dde-printer-helper.ts

ts_list=(`ls translations/*.ts`)
for ts in "${ts_list[@]}"
do
    printf "\nprocess ${ts}\n"
    /usr/lib/qt6/bin/lrelease "${ts}"
done

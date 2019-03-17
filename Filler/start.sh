#!/bin/bash

cp /dev/null log
make
mv tdontos-.filler players
./filler_vm -f maps/map01 -p1 players/tdontos-.filler  -p2 players/abanlin.filler



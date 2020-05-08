#!/usr/bin/env bash

echo "Friendly Fire"
echo TL2
../eigen_bench -T -t 2 --a1=1024 --a2=16384 --a3=8196 --r1=100 --w1=20 --r2=400 --w2=0 --r3i=200 --w3i=0 --r3o=0 --w3o=0 -p=y
echo PipinoTM
../pipino_eigen_bench -T -t 2 --a1=1024 --a2=16384 --a3=8196 --r1=100 --w1=20 --r2=400 --w2=0 --r3i=200 --w3i=0 --r3o=0 --w3o=0 -p=y
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 2 --a1=1024 --a2=16384 --a3=8196 --r1=100 --w1=20 --r2=400 --w2=0 --r3i=200 --w3i=0 --r3o=0 --w3o=0 -p=y

echo "Starving Elder 1"
echo TL2
../eigen_bench -T -t 1 --a1=1024 --a3=8196 --r1=128 --w1=32 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=100 --w3o=100
echo PipinoTM
../pipino_eigen_bench -T -t 1 --a1=1024 --a3=8196 --r1=128 --w1=32 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=100 --w3o=100
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 1 --a1=1024 --a3=8196 --r1=128 --w1=32 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=100 --w3o=100

echo "Starving Elder 4"
echo TL2
../eigen_bench -T -t 4 --a1=1024 --a3=8196 --r1=2 --w1=2 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=100 --w3o=100
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=1024 --a3=8196 --r1=2 --w1=2 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=100 --w3o=100
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=1024 --a3=8196 --r1=2 --w1=2 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=100 --w3o=100

echo "Restart Convoy"
echo TL2
../eigen_bench -T -t 4 --a1=8 --a2=4096 --a3=8196 --r1=4 --w1=2 --r2=20 --w2=20 --r3i=5 --w3i=0 --r3o=100 --w3o=100
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=8 --a2=4096 --a3=8196 --r1=4 --w1=2 --r2=20 --w2=20 --r3i=5 --w3i=0 --r3o=100 --w3o=100
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=8 --a2=4096 --a3=8196 --r1=4 --w1=2 --r2=20 --w2=20 --r3i=5 --w3i=0 --r3o=100 --w3o=100

echo "Serialized Commit"
echo TL2
../eigen_bench -T -t 4 --a2=16384 --a3=8196 --r1=0 --w1=0 --r2=10 --w2=500 --r3i=200 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a2=16384 --a3=8196 --r1=0 --w1=0 --r2=10 --w2=500 --r3i=200 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a2=16384 --a3=8196 --r1=0 --w1=0 --r2=10 --w2=500 --r3i=200 --w3i=0 --r3o=0 --w3o=0

echo "Starving Writer 1"
echo TL2
../eigen_bench -T -t 1 --a1=32 --a3=1048576 --r1=0 --w1=30 --r2=0 --w2=0 --r3i=500 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM
../pipino_eigen_bench -T -t 1 --a1=32 --a3=1048576 --r1=0 --w1=30 --r2=0 --w2=0 --r3i=500 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 1 --a1=32 --a3=1048576 --r1=0 --w1=30 --r2=0 --w2=0 --r3i=500 --w3i=0 --r3o=0 --w3o=0

echo "Starving Writer 4"
echo TL2
../eigen_bench -T -t 4 --a1=32 --r1=30 --w1=0 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=32 --r1=30 --w1=0 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=32 --r1=30 --w1=0 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=0 --w3o=0

echo "Futile Stall"
echo TL2
../eigen_bench -T -t 4 --a1=1024 --a2=16384 --r1=80 --w1=20 --r2=10 --w2=10 --r3i=0 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=1024 --a2=16384 --r1=80 --w1=20 --r2=10 --w2=10 --r3i=0 --w3i=0 --r3o=0 --w3o=0
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=1024 --a2=16384 --r1=80 --w1=20 --r2=10 --w2=10 --r3i=0 --w3i=0 --r3o=0 --w3o=0

echo "Dueling Upgrade"
echo TL2
../eigen_bench -T -t 2 --a1=128 --a3=2097152 --r1=80 --w1=10 --r2=0 --w2=0 --r3i=20 --w3i=0 --r3o=0 --w3o=0 --lct=0.75
echo PipinoTM
../pipino_eigen_bench -T -t 2 --a1=128 --a3=2097152 --r1=80 --w1=10 --r2=0 --w2=0 --r3i=20 --w3i=0 --r3o=0 --w3o=0 --lct=0.75
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 2 --a1=128 --a3=2097152 --r1=80 --w1=10 --r2=0 --w2=0 --r3i=20 --w3i=0 --r3o=0 --w3o=0 --lct=0.75

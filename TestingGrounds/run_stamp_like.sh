#!/usr/bin/env bash

echo "Genome 4"
echo "-T -t 4 --a1=262144 --a2=524288 --a3=262144 --r1=21 --w1=2 --r2=64 --w2=5 --r3i=20 --w3i=20 --r3o=0 --w3o=0 --lct=0.5"
echo TL2
../eigen_bench -T -t 4 --a1=262144 --a2=524288 --a3=262144 --r1=28 --w1=2 --r2=64 --w2=5 --r3i=0 --w3i=0 --r3o=20 --w3o=20 --lct=0.5
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=262144 --a2=524288 --a3=262144 --r1=28 --w1=2 --r2=64 --w2=5 --r3i=0 --w3i=0 --r3o=20 --w3o=20 --lct=0.5
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=262144 --a2=524288 --a3=262144 --r1=28 --w1=2 --r2=64 --w2=5 --r3i=0 --w3i=0 --r3o=20 --w3o=20 --lct=0.5

echo "Vacation-low"
echo "-T -t 4 --a1=524288 --a2=32768 --a3=65536 --r1=198 --w1=2 --r2=47 --w2=3 --r3i=0 --w3i=0 --r3o=0 --w3o=0 --lct=0.6"
echo TL2
../eigen_bench -T -t 4 --a1=524288 --a2=32768 --a3=65536 --r1=198 --w1=2 --r2=47 --w2=3 --r3i=0 --w3i=0 --r3o=0 --w3o=0 --lct=0.6
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=524288 --a2=32768 --a3=65536 --r1=198 --w1=2 --r2=47 --w2=3 --r3i=0 --w3i=0 --r3o=0 --w3o=0 --lct=0.6
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=524288 --a2=32768 --a3=65536 --r1=198 --w1=2 --r2=47 --w2=3 --r3i=0 --w3i=0 --r3o=0 --w3o=0 --lct=0.6

echo "Labyrinth"
echo "-T -t 4 --a1=131072 --a2=2097152 --a3=65536 --r1=10 --w1=5 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=600 --w3o=600 --lct=0.7"
echo TL2
../eigen_bench -T -t 4 --a1=131072 --a2=2097152 --a3=65536 --r1=10 --w1=5 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=600 --w3o=600 --lct=0.7
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=131072 --a2=2097152 --a3=65536 --r1=10 --w1=5 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=600 --w3o=600 --lct=0.7
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=131072 --a2=2097152 --a3=65536 --r1=10 --w1=5 --r2=0 --w2=0 --r3i=0 --w3i=0 --r3o=600 --w3o=600 --lct=0.7

echo "SSCA2"
echo "-T -t 4 --a1=33554432 --a2=8196 --a3=65536 --r1=1 --w1=1 --r2=1--w2=0 --r3i=0 --w3i=0 --r3o=15 --w3o=0 --lct=0"
echo TL2
../eigen_bench -T -t 4 --a1=33554432 --a2=8196 --a3=65536 --r1=1 --w1=1 --r2=1--w2=0 --r3i=0 --w3i=0 --r3o=15 --w3o=0 --lct=0
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=33554432 --a2=8196 --a3=65536 --r1=1 --w1=1 --r2=1--w2=0 --r3i=0 --w3i=0 --r3o=15 --w3o=0 --lct=0
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=33554432 --a2=8196 --a3=65536 --r1=1 --w1=1 --r2=1--w2=0 --r3i=0 --w3i=0 --r3o=15 --w3o=0 --lct=0

echo "Intruder"
echo "-T -t 4 --a1=1024 --a2=1024 --a3=65536 --r1=8 --w1=2 --r2=0--w2=0 --r3i=0 --w3i=0 --r3o=2 --w3o=2 --lct=0.5"
echo TL2
../eigen_bench -T -t 4 --a1=1024 --a2=1024 --a3=65536 --r1=8 --w1=2 --r2=0--w2=0 --r3i=0 --w3i=0 --r3o=2 --w3o=2 --lct=0.5
echo PipinoTM
../pipino_eigen_bench -T -t 4 --a1=1024 --a2=1024 --a3=65536 --r1=8 --w1=2 --r2=0--w2=0 --r3i=0 --w3i=0 --r3o=2 --w3o=2 --lct=0.5
echo PipinoTM_v2
../pipino_eigen_bench_v2 -T -t 4 --a1=1024 --a2=1024 --a3=65536 --r1=8 --w1=2 --r2=0--w2=0 --r3i=0 --w3i=0 --r3o=2 --w3o=2 --lct=0.5

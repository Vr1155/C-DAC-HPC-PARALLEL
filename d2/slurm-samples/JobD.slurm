#!/bin/bash
#SBATCH --job-name=JobD
#SBATCH --time=00:05:00
#SBATCH --ntasks=1
#SBATCH --output=JobD.stdout
#SBATCH --error=JobD.stderr
echo "I'm job D"
echo "I'm using output from jobs B and C"
cat jobB.out >> jobD.out
echo "" >> jobD.out
cat jobC.out >> jobD.out
echo "" >> jobD.out
echo "Sample job D output" >> jobD.out
sleep 120

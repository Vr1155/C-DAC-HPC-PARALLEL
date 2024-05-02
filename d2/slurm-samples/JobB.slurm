#!/bin/bash
#SBATCH --job-name=JobB
#SBATCH --time=00:05:00
#SBATCH --ntasks=1
#SBATCH --output=JobB.stdout
#SBATCH --error=JobB.stderr
echo "I'm job B"
echo "I'm using output from job A"
cat jobA.out >> jobB.out
echo "" >> jobB.out
echo "Sample job B output" >> jobB.out
sleep 120

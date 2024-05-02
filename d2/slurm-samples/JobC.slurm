#!/bin/bash
#SBATCH --job-name=JobC
#SBATCH --time=00:05:00
#SBATCH --ntasks=1
#SBATCH --output=JobC.stdout
#SBATCH --error=JobC.stderr
echo "I'm job C"
echo "I'm using output from job A"
cat jobA.out >> jobC.out
echo "" >> jobC.out
echo "Sample job C output" >> jobC.out
sleep 120

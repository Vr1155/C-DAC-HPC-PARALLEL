#!/bin/bash
#SBATCH --job-name=JobA
#SBATCH --time=00:05:00
#SBATCH --ntasks=1
#SBATCH --output=JobA.stdout
#SBATCH --error=JobA.stderr
echo "I'm job A"
echo "Sample job A output" > jobA.out
sleep 120

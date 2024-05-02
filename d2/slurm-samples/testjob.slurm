#!/bin/bash
#SBATCH -J TestJob
#SBATCH -N 1
#SBATCH --time=01:00:00
#SBATCH --error=job.%J.err
#SBATCH --output=job.%J.out
#SBATCH --partition=standard

/bin/hostname



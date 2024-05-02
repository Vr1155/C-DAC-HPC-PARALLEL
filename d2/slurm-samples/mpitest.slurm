#!/bin/bash
#SBATCH -J sampleMPI1
#SBATCH -N 4
#SBATCH --time=01:00:00
#SBATCH --error=job.%J.err
#SBATCH --output=job.%J.out
#SBATCH --partition=standard

mpirun --mca btl ^openib -np 4 ./basic_mpi


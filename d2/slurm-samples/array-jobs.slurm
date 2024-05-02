#!/bin/bash

#SBATCH --job-name=array
#SBATCH --array=1-4
#SBATCH --time=01:00:00
#SBATCH --partition=standard
#SBATCH --ntasks=1
#SBATCH --mem=1G
#SBATCH --output=array_%A-%a.out

# Print the task id.
srun bash -c "sleep 10; echo 'My SLURM_ARRAY_TASK_ID:' $SLURM_ARRAY_TASK_ID"

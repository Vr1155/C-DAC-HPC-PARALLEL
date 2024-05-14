#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks-per-core=10
#SBATCH --cpus-per-task=10
#SBATCH --partition=standard
##SBATCH --gres=gpu:1
#SBATCH --job-name=sycl
#SBATCH --error=error_%j.err
#SBATCH --output=output_%j.out
#SBATCH --time=01:00:00

##SBATCH --mem=default
##SBATCH --mail-user=email@gmail.com
##SBATCH --mail-type=ALL
##SBATCH --ntasks-per-sockets=4

ulimit -s unlimited

##source /scratch/parade/Laxmikant/set_path.sh

##./SYCLvecadd_icpx

./vecMUL
###############################

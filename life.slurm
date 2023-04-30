#!/bin/bash
#SBATCH --job-name=life
#SBATCH --output=life.o%j
#SBATCH --partition=nu
#SBATCH --ntasks=64
#SBATCH --time=00:10:00

cd $SLURM_SUBMIT_DIR

module load gcc/7.2.0

./life 10 10

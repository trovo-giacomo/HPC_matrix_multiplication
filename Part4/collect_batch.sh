#!/bin/bash
# 02614 - High-Performance Computing, January 2018
# 
# batch script to run collect on a decidated server in the hpcintro
# queue
#
# Author: Bernd Dammann <bd@cc.dtu.dk>
#
#BSUB -J collector
#BSUB -o collector_%J.out
#BSUB -q hpcintro
#BSUB -n 1
#BSUB -R "rusage[mem=2048]"
#BSUB -W 15

module load studio

# define the driver name to use
# valid values: matmult_c.studio, matmult_f.studio, matmult_c.gcc or
# matmult_f.gcc
#
EXECUTABLE=matmult_c.gcc

# define the mkn values in the MKN variable
#
MKN="100 100 100"

# define the permutation type in PERM
#
PERM="blk"

# uncomment and set a reasonable BLKSIZE for the blk version
#
BLKSIZE="2 4 8 16 32"
#BLKSIZE=4

# define the max no. of iterations the driver should use - adjust to
# get a reasonable run time.  You can get an estimate by trying this
# on the command line, i.e. "MFLOPS_MAX_IT=10 ./matmult_...." for the
# problem size you want to analyze.
#
export MFLOPS_MAX_IT=1000
export MATMULT_COMPARE=0

# experiment name 
#
JID=${LSB_JOBID}
EXPOUT="$LSB_JOBNAME.${JID}.er"

# uncomment the HWCOUNT line, if you want to use hardware counters
# define an option string for the harwdware counters (see output of
# 'collect -h' for valid values.  The format is:
# -h cnt1,on,cnt2,on,...  (up to four counters at a time)
#
# the example below is for L1 hits, L1 misses, L2 hits, L2 misses
#
HWCOUNT="-h dch,on,dcm,on,l2h,on,l2m,on"

# start the collect command with the above settings
for BS in $BLKSIZE
do
    collect -o $EXPOUT $HWCOUNT ./$EXECUTABLE $PERM $MKN $BLKSIZE
done
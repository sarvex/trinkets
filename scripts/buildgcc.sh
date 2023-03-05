#!/bin/bash

# buildgcc.sh: a user-friendly installation script for GCC
# Designed for GCC 12.2

# Get flags (I actually have no idea what this does but it works)
# while getopts a: flag
# do
#   case "${flag}" in
#     a) arg=${OPTARG};;
#   esac
# done

# echo $1

check_args() {
  # case $1 in
  #   '-h' | '--help')
  #     printf "Welcome to the Help manual."
  #     ;;
  #   *)
  #     printf "Unrecognized argument. Check spelling or rerun with --help."
  #     ;;
  # esac
  if [ "$1" = "-h" ]; then
    printf "tea"
  fi
}

check_args

printf "\033[0m\n"
exit 0
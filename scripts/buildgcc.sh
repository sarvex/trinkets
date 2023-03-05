#buildgcc.sh: a user-friendly installation script for GCC
#Designed for GCC 12.2

while getopts a: flag
do
  case "${flag}" in
    a) arg=${OPTARG};;
  esac
done

echo $arg

printf "\n\n\033[0mThank you for using HackerDaGreat57's GCC Build Script. Exiting...\n"
exit 0
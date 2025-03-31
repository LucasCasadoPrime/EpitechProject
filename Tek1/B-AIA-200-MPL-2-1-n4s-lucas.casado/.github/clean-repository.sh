#!/bin/sh

# Running tests
bad=0
check_file () {
  echo -n "$1 not in repository > "
  if [ "$3" = "dir" ]; then
    if [ -d $2 ]; then
      echo "KO: $1 present in delivery"
      bad=1
    else 
      echo "PASSED"
    fi
  fi
  if [ "$3" = "file" ]; then
    if [ -f $2 ]; then
      echo "KO: $1 present in delivery"
      bad=1
    else 
      echo "PASSED"
    fi
  fi
}

# Tests
check_file "CoppeliaSim" "CoppeliaSim*" "dir"
check_file "VREP" "V-REP*" "dir"
check_file "n4s" "n4s" "file"
check_file "n4s_buffer" "n4s_buffer" "file"
check_file "pipes.sh" "pipes.sh" "file"

exit $bad;
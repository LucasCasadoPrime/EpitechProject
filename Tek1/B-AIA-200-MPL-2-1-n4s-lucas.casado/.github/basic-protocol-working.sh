#!/bin/sh
echo -n "START_SIMULATION > "
make &>/dev/null
if [ ! -f './ai' ]; then
  echo "KO: ./ai not found."
  exit 1;
fi

echo "PASSED"
exit 0;
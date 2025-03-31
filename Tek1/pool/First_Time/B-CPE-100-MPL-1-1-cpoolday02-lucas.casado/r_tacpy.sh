cut -d ':' -f 1 | sed -n "2~2p" | rev | sort -r  | tr "\n" "," | cut -d ',' -f ${MY_LINE1}-${MY_LINE2} | sed -e "s/,/, /g" | tr "\n" "." | sed "s/\./.\n/g" | tr '\n' '.'

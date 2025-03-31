#!/bin/bash
grep -e 'theo1' -e 'steven' -e 'arnaud1' -e 'pierre-jean' | sed -e 's/theo1/Wile E. Coyote/' | sed -e 's/steven1/Daffy Duck/' | sed -e 's/arnaud1/Porky Pig/' | sed -e 's/pierre-jean/Marvin the Martian/'

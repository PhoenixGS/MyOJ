i=1; for x in *.in; do mv $x name$i.in; let i=i+1; done
i=1; for x in *.out; do mv $x name$i.out; let i=i+1; done

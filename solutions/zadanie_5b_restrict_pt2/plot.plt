set terminal png
set output 'filtr.png'
system 'head -n 255 source.dat > source1.dat; head -n 255 destination.dat > destination1.dat;'
plot 'source1.dat' smooth unique w l  , 'destination1.dat' smooth unique w l lw 2

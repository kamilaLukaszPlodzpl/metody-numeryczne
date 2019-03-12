set terminal pngcairo #Ustawienie sposobu rederowania obrazka
set output "out.png" #Nazwa pliku wyjściowego
set xlabel "X" #Etykieta osi X
set ylabel "Y" #Etykieta osi Y
set title "(n,2n) reaction" #Nazwa u góry wykresu
set xrange [ 0 : 20 ] #Przedział do wyrederowania na osi X
set yrange [ 0 : 2 ] #Przedział do wyrederowania na osi Y
set mxtics 5 #X Ilość małych podziałek
set mytics 5 #Y
set xtics 1 #X Co ile rysować duża podziałke
set ytics 1 #Y

#Rysowanie 2 linii
plot "-" with lines title "title1", "-" with lines title "title2"
1 1
2 2
3 3
e
1 3
2 2
3 1
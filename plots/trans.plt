set term postscript color eps

set style data boxplot
set style boxplot nooutliers

set title 'convGEMM trans ' . ARG2
set ylabel 'Acceleration'
set xtics ("im2row+BLAS\nvs B3A2C0 NHWC" 1, "im2row+BLAS\nvs A3B2C0 NHWC" 2, "im2col+trans+BLAS\nvs B3A2C0 NCHW" 3, "im2col+trans+BLAS\nvs A3B2C0 NCHW" 4)
#, "convGEMM NCHW\nvs convGEMM NHWC" 3)
set key off
set bmargin 3

plot 1.0 with line ls 0, \
     ARG1 using (1):(($14+$15)/$16), \
     ARG1 using (2):(($14+$15)/$17), \
     ARG1 using (3):(($18+$19+$20)/$21), \
     ARG1 using (4):(($18+$19+$20)/$22)

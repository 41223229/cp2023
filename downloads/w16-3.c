#include <stdio.h>

int main() {
    FILE *gnuplotPipe = popen("gnuplot", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set terminal png\n");
        fprintf(gnuplotPipe, "set output 'motion_plot.png'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Position / Velocity'\n");
        fprintf(gnuplotPipe, "plot 'motion_data.txt' using 1:2 with lines title 'm1 position', 'motion_data.txt' using 1:3 with lines title 'm2 position', 'motion_data.txt' using 1:4 with lines title 'm1 velocity', 'motion_data.txt' using 1:5 with lines title 'm2 velocity'\n");
        fprintf(gnuplotPipe, "exit\n");
        fflush(gnuplotPipe);
        pclose(gnuplotPipe);
    } else {
        printf("Error opening pipe to Gnuplot.\n");
    }
    return 0;
}
// OmpTrace.cpp : painting OMP threads
// compilation:
// g++ -c EasyBMP.cpp
// g++ -c OmpTrace.cpp -fopenmp
// g++ OmpTrace.o EasyBmp.o -fopenmp

#include "EasyBMP.h"
#include "omp.h"
#define  HAUTEUR   1080
#define  LARGEUR   1920

int main(int argc, char* argv[])
{
    RGBApixel pixel;
    BMP img ;
#ifdef _OPENMP
    printf("*** Compiled with OPENMP ***\n");
#endif
    if (argc < 3)
        goto finally;
    img.SetSize(LARGEUR, HAUTEUR);
    for (int m = 0; m < LARGEUR; m++)  // Thread1 Thread2 etc.
    {
        for (int n = 0; n < HAUTEUR; n++)
        {
            pixel.Blue = 0;
            pixel.Green = 0 ;
            pixel.Red = 255;

            img.SetPixel(m, n, pixel);
        } // columns
    } // lines
    img.WriteToFile(argv[1]);

    printf( "...done\n");
    return 0;

    finally:
    printf("syntaxe: %s  fichier_bmp  nombre_de_threads\n",argv[0]);
    printf("     ex: %s  trace.bmp 4\n",argv[0]);
    return -1;
}
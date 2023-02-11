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
    omp_set_num_threads(argv[2]);
    for (int m = 0; m < LARGEUR; m++)  // Thread1 Thread2 etc.
    {
        #pragma omp parallel for
        for (int n = 0; n < HAUTEUR; n++)
        {
            switch(omp_get_num_threads()){
                case 0:
                    pixel.Blue = 0;
                    pixel.Green = 0;
                    pixel.Red = 255;
                    break;
                case 1:
                    pixel.Blue = 0;
                    pixel.Green = 255;
                    pixel.Red = 0;
                    break;
                case 2:
                    pixel.Blue = 255;
                    pixel.Green = 0;
                    pixel.Red = 0;
                    break;  
                case 3:
                    pixel.Blue = 0;
                    pixel.Green = 255;
                    pixel.Red = 255;
                    break;  
                case 4:
                    pixel.Blue = 255;
                    pixel.Green = 0;
                    pixel.Red = 255;
                    break; 
                case 5:
                    pixel.Blue = 255;
                    pixel.Green = 255;
                    pixel.Red = 0;
                    break;       
                case 6:
                    pixel.Blue = 255;
                    pixel.Green = 255;
                    pixel.Red = 255;
                    break;  
                case 7:
                    pixel.Blue = 0;
                    pixel.Green = 0;
                    pixel.Red = 0;
                    break;                   
            }

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
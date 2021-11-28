using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BusquedaBinariaEnMatriz
{
    internal class Program
    {

        static int[,] ConvertMatrix(int[] flat, int m, int n)
        {
            if (flat.Length != m * n)
            {
                throw new ArgumentException("Longitud invalida");
            }
            int[,] ret = new int[m, n];
            Buffer.BlockCopy(flat, 0, ret, 0, flat.Length * sizeof(int));
            return ret;
        }

        static void imprimirMatriz(int[,] matriz, int f,int c) {

            for (int i = 0; i < f; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    Console.Write(matriz[i, j] + " - ");
                }
                Console.WriteLine("");
            }
        }

        static void Main(string[] args)
        {
            int valorB = 9;

            //definimos matriz

            int[,] Matriz = {                {  1,  2,  4,  7},
                {  9, 12, 15, 16},
                { 22, 65, 75, 82},
                { 83, 84, 86, 90},
                { 98,120,135,400}};

            int[] Vector = new int[5*4];

            //imprimirMatriz

            imprimirMatriz(Matriz, 5, 4);

            //transformarMatriz

            int Indice = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 4; j++) {
                    Vector[Indice] = Matriz[i, j];
                    Indice++;
                }
            }

            //ImprimirVector

            Console.WriteLine("");
            for (int i = 0; i < Vector.Length; i++) {
                Console.Write(Vector[i] + " - ");
            }
            Console.WriteLine("");


            //transformarVector

            int[,] matrix = ConvertMatrix(Vector, 5, 4);

            //imprimirMatriz

            imprimirMatriz(matrix, 5, 4);

        }
    }
}

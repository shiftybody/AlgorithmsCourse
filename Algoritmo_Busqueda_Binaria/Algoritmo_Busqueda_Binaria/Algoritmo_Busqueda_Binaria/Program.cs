using System;
using System.Diagnostics;
using System.Threading;

namespace Algoritmo_Busqueda_Binaria
{
    class Program
    {
        private static int valorB;
        private static int[] Valores = new int[1];
        
        private static void Main(string[] args)
        {
            valorB = 200;
            GenerarValores(13, 100);
            Array.Sort(Valores);
            MostrarValores();
            
            Console.WriteLine(BusquedaBinaria());
        }

        private static int BusquedaBinaria()
        {
            ElapsedTime timer = new ElapsedTime();
            timer.startTimeMeasure();
            
            int postI = 0;
            int postF = Valores.Length - 1;
            int Encontrado = -1;
            int Pivote;

            while (postI <= postF )
            {
                Pivote = (postF + postI) / 2;
                Console.WriteLine("pivote actual " + Pivote);
                if (Valores[Pivote] == valorB)
                {
                    Encontrado = Pivote;
                    break;
                }
                else
                {
                    if (Valores[Pivote] > valorB)
                    {
                        postF = Pivote - 1;
                    }
                    else
                    {
                        postI = Pivote + 1;
                    }
                }
            }
            timer.endTimeMeasure();
            Console.WriteLine("Tiempo de Ejecución: " + timer.getElapsedTime().TotalMilliseconds + " Milisegundos");

            return Encontrado;
        }

        private static void MostrarValores()
        {
            Console.WriteLine("Valor Buscado = " + valorB);

            for (int i = 0; i < Valores.Length; i++)
            {
                Console.WriteLine("[ " + i + " ] " + Valores[i]);
            }
        }

        private static void GenerarValores(int n, int max)
        {
            Array.Resize(ref Valores,n);
            Random Num = new Random();

            for (int i = 0; i < Valores.Length; i++)
            {
                Valores[i] = Num.Next(max);
            }
        }
    }
}
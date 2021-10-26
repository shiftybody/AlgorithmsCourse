/*
 Algoritmo de Busqueda Secuencial/Lineal
 Autor: @Shiftybody  David Cano
 Version: 0.1
 */

using System;
using System.Diagnostics;
using System.Threading;

namespace Algoritmo_Busqueda_Secuencial
{
    internal class Program
    {
        private static int _valorB;
        private static int _comparaciones = 0;

        private static int[] _valores = new int[1];

        private static void Main(string[] args)
        {
            _valorB = 21;
            GenerarValores(50000000, 20);
            //MostrarDatos();
            Console.WriteLine(BusquedaLineal());
            Console.WriteLine("Comparaciones: " + _comparaciones);
           


        }

        private static int BusquedaLineal()
        {
            // esta solución implementa la clase ElpsedTime 

            ElapsedTime timer = new ElapsedTime();

            timer.startTimeMeasure();

            int encontrado = -1;
           
            for (int i = 0; i < _valores.Length; i++)
            {
                _comparaciones++;
                if (_valores[i] == _valorB)
                {
                    encontrado = i;
                    break;
                    
                }
            }

            timer.endTimeMeasure();

            Console.WriteLine("Tiempo Transcurrido:" + timer.getElapsedTime().TotalMilliseconds);


            return encontrado;

        }

        private static void MostrarDatos()
        {

            Console.WriteLine("Valor Busqueda = " + _valorB);

            for (int i = 0; i < _valores.Length; i++)
            {
                Console.WriteLine("[" + i + "]= " + _valores[i]);
            }

        }


        private static void GenerarValores(int n, int max)
        {
            Array.Resize(ref _valores, n);
            Random Numero = new Random();

            for (int i = 0; i < _valores.Length; i++)
            {
                _valores[i] = Numero.Next(max);
            }
        }
    }
}
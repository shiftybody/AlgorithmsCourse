using System;
using System.Collections.Generic;

namespace RutaCritica
{
    internal class Program
    {
        static int cantNodos;
        static int actividades;
        static int[,] mAdyacencia;
        static int nodoInicio;
        static int nodoFinal;
        static List<List<int>> Rutas = new List<List<int>>();
        static List<int> distancias = new List<int>();


        public static void Main(string[] args)
        {

            int[,] nodeMap = new int[,] {
                                                                {0,1,3},
                                                                {0,2,5},
                                                                {1,3,4},
                                                                {2,5,9},
                                                                {3,5,6},
                                                                {3,4,1},
                                                                {5,6,12},
                                                                {4,6,9}};

            /*            int[,] nodeMap = new int[,] {
                                                    {0,1,10},
                                                    {0,2,8},
                                                    {1,3,4},
                                                    {2,1,8},
                                                    {2,4,5},
                                                    {3,5,5},
                                                    {4,3,5},
                                                    {4,5,7},
                                                    {5,6,12},
                                                    {5,7,4},
                                                    {6,2,7},
                                                    {5,4,2},
                                                    {6,7,5}};*/

            actividades = nodeMap.GetLength(0);
            cantNodos = getCantidadNodos(nodeMap, actividades);

            Console.WriteLine("\n\t" + "aristas: " + actividades + "   nodos: " + cantNodos);

            initAdjMatix(nodeMap);
            printAdjMatix();

            nodoInicio = getInicio();
            nodoFinal = getFinal();

            Console.WriteLine("\n   nodo Incio: " + nodoInicio + "  nodo Final: " + nodoFinal);

            printPaths(nodoInicio, nodoFinal);
            Console.WriteLine("La ruta más corta es: " + getSortedPath() + "\n");


        }

        private static String getSortedPath()
        {
            int distanciaMin = int.MaxValue;
            int indiceDistancia = 0;

            foreach (var distancia in distancias)
            {
                if (distancia < distanciaMin)
                {

                    distanciaMin = distancia;
                    indiceDistancia = distancias.IndexOf(distanciaMin);
                }
            }

            string sortedPath = string.Join(" ", Rutas[indiceDistancia]) + " -> " + distanciaMin;

            return sortedPath;
        }

        private static int getCantidadNodos(int[,] nodeMap, int aristas)
        {
            int[] Vector = new int[aristas * 2];

            int Indice = 0;

            for (int i = 0; i < aristas; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    Vector[Indice] = nodeMap[i, j];
                    Indice++;
                }
            }

            Array.Sort(Vector);


            int nNodos = 0;
            for (int i = 0; i < Vector.Length; i++)
            {
                while (i < Vector.Length - 1 && Vector[i] == Vector[i + 1])
                {
                    i++;
                }
                nNodos++;
            }
            return nNodos;

        }

        static int getFinal()
        {
            int nFinal = 0;

            for (int i = 0; i < cantNodos; i++)
            {
                int suma = 0;
                for (int j = 0; j < cantNodos; j++)
                {
                    suma += mAdyacencia[i, j];

                }
                if (suma == 0)
                {
                    nFinal = i;
                    break;
                }
            }
            return nFinal;
        }


        private static int getInicio()
        {
            int nInicio = 0;

            for (int j = 0; j < cantNodos; j++)
            {
                int suma = 0;

                for (int i = 0; i < cantNodos; i++)
                {
                    suma += mAdyacencia[i, j];
                }
                if (suma == 0)
                {
                    nInicio = j;
                    break;
                }
            }

            return nInicio;
        }

        static void initAdjMatix(int[,] nodeMap)
        {
            mAdyacencia = new int[cantNodos, cantNodos];

            for (int i = 0; i < actividades; i++)
            {
                mAdyacencia[nodeMap[i, 0], nodeMap[i, 1]] = nodeMap[i, 2];
            }
        }

        static void printAdjMatix()
        {

            Console.Write("  ");

            for (int x = 0; x < cantNodos; x++)
                Console.Write("    " + x);

            Console.WriteLine();

            for (int x = 0; x < cantNodos; x++)
            {
                Console.Write(" " + x);

                for (int y = 0; y < cantNodos; y++)
                {
                    Console.Write("    " + mAdyacencia[x, y]);
                }
                Console.WriteLine();
            }
        }

        static void printPaths(int inicio, int final)
        {

            bool[] isVisited = new bool[cantNodos];
            List<int> listaRutaNodos = new List<int>();

            shortPaths(inicio, final, isVisited, listaRutaNodos);
            printPaths();

        }

        private static void printPaths()
        {

            Console.WriteLine();
            foreach (var ruta in Rutas)
            {
                int suma = 0;
                int[] array = ruta.ToArray();

                for (int i = 1; i < array.GetLength(0); i++)
                {
                    Console.Write(array[i - 1] + " ");

                    for (int x = 0; x < cantNodos; x++)
                    {
                        for (int y = 0; y < cantNodos; y++)
                        {
                            if (array[i] == y && array[i - 1] == x)
                            {
                                suma += mAdyacencia[x, y];
                            }
                        }
                    }
                }

                Console.Write(array[array.GetLength(0) - 1] + " ");

                distancias.Add(suma);
                Console.WriteLine("-> " + suma);
            }
            Console.WriteLine();
        }

        static void shortPaths(int nodoActual, int nodoFinal, bool[] isVisited, List<int> listaRutaNodos)
        {
            if (nodoActual == nodoFinal)
            {
                List<int> resultTemp = new List<int>();
                resultTemp.Add(nodoInicio);
                resultTemp.AddRange(listaRutaNodos);
                Rutas.Add(resultTemp);
            }

            isVisited[nodoActual] = true;

            for (int i = 0; i < cantNodos; i++)
            {
                if (mAdyacencia[nodoActual, i] >= 1 && !isVisited[i])
                {
                    listaRutaNodos.Add(i);
                    shortPaths(i, nodoFinal, isVisited, listaRutaNodos);
                    listaRutaNodos.Remove(i);
                }
            }
            isVisited[nodoActual] = false;
        }
    }
}

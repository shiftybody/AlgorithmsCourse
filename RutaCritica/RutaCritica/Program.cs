using System;
using System.Collections.Generic;

namespace RutaCritica
{
    internal class Program
    {


        public static void Main(string[] args)
        {
            int inicio = 0;
            int final = 0;
            int distancia = 0;
            int x = 0;
            int y = 0;
            int cantNodos = 7;   // crear algoritmo para calcular numero de nodos
            string dato = "";
            int nodo1 = 0;

            int actual = 0;
            int columna = 0;

            /*matriz con las actividades representadas
            desde el nodo actual, el nodo posterior y la duración. */

            int[,] nodeMap = new int[,] {{0,1,3},
                                         {0,2,5},
                                         {1,3,4},
                                         {2,4,9},
                                         {3,5,1},
                                         {3,4,6},
                                         {5,6,9},
                                         {4,6,12}};

            int aristas = nodeMap.GetLength(0);

            Grafo graph = new Grafo(cantNodos);

            /*convertir nodeMap en MatrizdeAdyacencia*/

            int[,] mAdyacencia = new int[cantNodos, cantNodos]; //instancia de la matriz adyacencia

            for (int i = 0; i < aristas; i++) {
                mAdyacencia[nodeMap[i,0],nodeMap[i,1]] = nodeMap[i,2];
            }

            /*Imprimir mAdyacencia;*/

            for (x = 0; x < cantNodos; x++)
                Console.Write("\t{0}", x);

            Console.WriteLine();

            for (x = 0; x < cantNodos; x++)
            {     
                Console.Write(x);

                for (y = 0; y < cantNodos; y++)
                {
                    Console.Write("\t" + mAdyacencia[x, y]);
                }
                Console.WriteLine();

            }

            graph.AdicionaArista(0, 1, 3);
            graph.AdicionaArista(0, 2, 5);
            graph.AdicionaArista(1, 3, 4);
            graph.AdicionaArista(2, 4, 9);
            graph.AdicionaArista(3, 5, 1);
            graph.AdicionaArista(3, 4, 6);
            graph.AdicionaArista(5, 6, 9);
            graph.AdicionaArista(4, 6, 12);

            graph.MuestraAdyacencia();

            graph.CalcularIndegree();
            graph.MostrarIndegree();

            do
            {
                nodo1 = graph.EncuentraI0();
                if (cantNodos != -1)
                {
                    Console.Write(nodo1);
                    graph.DecrementaIndigree(nodo1);
                }


            } while (nodo1 != -1);

            Console.WriteLine();




            Console.WriteLine("Dame el indice del nodo inicio");
            dato = Console.ReadLine();
            inicio = Convert.ToInt32(dato);

            Console.WriteLine("Dame el indice del nodo final");
            dato = Console.ReadLine();
            final = Convert.ToInt32(dato);

            //creamos tabla
            // 0 visitado
            // 1 distancia
            // 2 previo
            int[,] tabla = new int[cantNodos, 3];

            for (x = 0; x < cantNodos; x++)
            {
                tabla[x, 0] = 0;
                tabla[x, 1] = int.MaxValue;
                tabla[x, 2] = 0;
            }

            tabla[inicio, 1] = 0;

            MostrarTabla(tabla);


            //algoritmo dijkstra
            actual = inicio;

            do
            {
                //marcar nodo como visitado
                tabla[actual, 0] = 1;

                for (columna = 0; columna < cantNodos; columna++)
                {

                    // buscamos a quien se dirige
                    if (graph.ObtenerAdyacencia(actual, columna) != 0)
                    {

                        //calculamos la distancia  obtener adyacencia es el peso
                        distancia = graph.ObtenerAdyacencia(actual, columna) + tabla[actual, 1];

                        //colocamos la distanicas
                        if (distancia < tabla[columna, 1])
                        {
                            tabla[columna, 1] = distancia;
                            // colocamos la inforamcion de padre;
                            tabla[columna, 2] = actual;
                        }
                    }
                }

                // el nuevo actual es el nodo con la menor distanica que no ha sido visitado

                int indiceMenor = -1;
                int distanciaMenor = int.MaxValue;

                for (int j = 0; j < cantNodos; j++)
                {
                    if (tabla[j, 1] < distanciaMenor && tabla[j, 0] == 0)
                    {
                        indiceMenor = j;
                        distanciaMenor = tabla[j, 1];

                    }
                }

                actual = indiceMenor;

            } while (actual != -1);

            MostrarTabla(tabla);

            //obtener la ruta
            List<int> ruta = new List<int>();
            int nodo = final;

            while (nodo != inicio)
            {
                ruta.Add(nodo);
                nodo = tabla[nodo, 2];

            }
            ruta.Add(inicio);

            ruta.Reverse();

            foreach (int posicion in ruta)
                Console.Write("{0}->", posicion);
            Console.Write(distancia);
            Console.WriteLine();

        }

        public static void MostrarTabla(int[,] pTabla)
        {
            int n;

            for (n = 0; n < pTabla.GetLength(0); n++)
            {
                Console.WriteLine("{0} /> {1}\t{2}\t{3}", n, pTabla[n, 0], pTabla[n, 1], pTabla[n, 2]);


            }
            Console.WriteLine("----------");
        }

        public class Grafo
        {

            private int[,] mAdyacencia;
            private int[] indegree;
            private int nodos;

            public Grafo(int pNodos)
            {
                nodos = pNodos;
                mAdyacencia = new int[nodos, nodos];
                indegree = new int[nodos];

            }

            public void AdicionaArista(int pNodoInicio, int pNodoFinal, int pPeso)
            {
                mAdyacencia[pNodoInicio, pNodoFinal] = pPeso;
            }

            public void MuestraAdyacencia()
            {
                int n;
                int m;

                Console.ForegroundColor = ConsoleColor.Yellow;

                for (n = 0; n < nodos; n++)
                    Console.Write("\t{0}", n);

                Console.WriteLine();

                for (n = 0; n < nodos; n++)
                {
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.Write(n);

                    for (m = 0; m < nodos; m++)
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write("\t{0}", mAdyacencia[n, m]);
                    }
                    Console.WriteLine();

                }
            }


            public int ObtenerAdyacencia(int pFila, int pColumna)
            {
                return mAdyacencia[pFila, pColumna];
            }


            public void CalcularIndegree()
            {
                int n;
                int m;

                for (n = 0; n < nodos; n++)
                {
                    for (m = 0; m < nodos; m++)
                    {
                        if (mAdyacencia[m, n] != 0 && mAdyacencia[m, n] != -1)
                            indegree[n]++;
                    }
                }
            }

            public void MostrarIndegree()
            {
                int n;
                Console.ForegroundColor = ConsoleColor.White;
                for (n = 0; n < nodos; n++)
                    Console.WriteLine("Nodo: {0}, {1}", n, indegree[n]);
            }

            public int EncuentraI0()
            {
                bool encontrado = false;
                int n;

                for (n = 0; n < nodos; n++)
                {
                    if (indegree[n] == 0)
                    {
                        encontrado = true;
                        break;
                    }

                }

                if (encontrado)
                    return n;
                else
                    return -1;

            }

            public void DecrementaIndigree(int pNodo)
            {
                indegree[pNodo] = -1;

                int n;

                for (n = 0; n < nodos; n++)
                {
                    if (mAdyacencia[pNodo, n] != 0 && mAdyacencia[pNodo, n] != -1)
                    {
                        indegree[n]--;
                    }
                }
            }
        }
    }
}

using System;

namespace Algoritmos_Busqueda_Comparacion
{
    class Program
    {
        static int valorB;
        static int ComparacionesBL = 0;
        static int ComparacionesBB = 0;
        private static int comparaciones = 0, intercambios = 0;
        static int[] Valores = new int[1]; 


        static void Main(string[] args)
        {

            valorB = 201;
   
            GenerarValores(200, 200);
            MostrarDatos();
            Console.WriteLine(BusquedaLineal());

            //Array.Sort(Valores);
            insertionSort();
            
            MostrarDatos();
            Console.WriteLine(BusquedaBinaria());
            Console.WriteLine("Comparaciones Lineal: " + ComparacionesBL);
            Console.WriteLine("Comparaciones Binaria: " + ComparacionesBB);
            Console.WriteLine('\n' + "Insertion Sort >  Comparaciones:" + comparaciones + " Intercambios: " + intercambios);
            
            Console.Read();   
        }

        private static int BusquedaLineal()
        {

            ElapsedTime timer = new ElapsedTime();
            timer.startTimeMeasure();

            int encontrado = -1;
           
            for (int i = 0; i < Valores.Length; i++)
            {
                ComparacionesBL++;
                if (Valores[i] == valorB)
                {
                    encontrado = i;
                    break;
                    
                }
            }

            timer.endTimeMeasure();
            Console.WriteLine("Tiempo Transcurrido:" + timer.getElapsedTime().TotalMilliseconds);


            return encontrado;

        }

        private static int BusquedaBinaria()
        {
            ElapsedTime timer2 = new ElapsedTime();
            timer2.startTimeMeasure();
            
            int postI = 0;
            int postF = Valores.Length - 1;
            int Encontrado = -1;
            int Pivote;

            while (postI <= postF )
            {
                Pivote = (postF + postI) / 2;
                // Console.WriteLine("pivote actual " + Pivote);
                ComparacionesBB++;
                
                if (Valores[Pivote] == valorB && Encontrado == -1)
                {
                    Encontrado = Pivote;
                    break;
                }
                else
                {
                    ComparacionesBB++;
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
            timer2.endTimeMeasure();
            Console.WriteLine("Tiempo de Ejecución: " + timer2.getElapsedTime().TotalMilliseconds + " Milisegundos");

            return Encontrado;
        }

        static void MostrarDatos()
        {
            Console.WriteLine("Valor Buscado = " + valorB);
            for (int i = 0; i < Valores.Length; i++)
            {
                Console.WriteLine("[" + i + "] = " + Valores[i]);
            }
        }
        

        static void GenerarValores(int n, int max)
        {
            Array.Resize(ref Valores, n);
            Random Numero = new Random();

            for(int i = 0; i < Valores.Length; i++)
            {
                Valores[i] = Numero.Next(max);
            }
        }

        static void insertionSort()
        {
            for (int pivote = 1; pivote < Valores.Length; pivote++)
            {
                int posActual = pivote;
                for (int numIzq = pivote; numIzq >= 0; numIzq--)
                {
                    comparaciones++;
                    if (Valores[numIzq] > Valores[posActual])
                    {
                        var buffer = Valores[numIzq];
                        Valores[numIzq] = Valores[posActual];
                        Valores[posActual] = buffer;
                        intercambios++;
                        posActual = numIzq;  
                    }
                }
            }
        }
    }
}
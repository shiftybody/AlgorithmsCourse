using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CalculadoraRutaCritica
{
    public class Vertice
    {
        public int Valor { get; set; }
        public List<Vertice> Aristas { get; set; }

        public Vertice(int Valor)
        {
            this.Valor = Valor;
            Aristas = new List<Vertice>();
        }
    }
}

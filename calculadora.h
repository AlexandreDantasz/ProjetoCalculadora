#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <cmath>

namespace abd{
    class Calculadora
    {
        public:
            //Construtores
            Calculadora();
            Calculadora(double primeiroValor, double segundoValor);
            //Métodos
            double calcularAdicao()const;
            double calcularSubtracao()const;
            double calcularMultiplicacao()const;
            double calcularDivisao()const;
            double calcularRadiciacao(double valorNaRaiz)const;
            double calcularPotenciacao(double valorDaBase, double expoente)const;
            void setPrimeiroValor(double newPrimeiroValor);
            double getPrimeiroValor()const;
            void setSegundoValor(double newSegundoValor);
            double getSegundoValor()const;
        private:
            //Atributos
            double primeiroValor;
            double segundoValor;
    };
}
#endif // CALCULADORA_H

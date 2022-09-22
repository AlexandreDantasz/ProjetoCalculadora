#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <cmath>
#include <QString>

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
            double calcularRadiciacao(double valorNaRaiz, double indice)const;
            double calcularPotenciacao(double valorDaBase, double expoente)const;
            void setPrimeiroValor(double newPrimeiroValor);
            double getPrimeiroValor()const;
            void setValores(QString newValores);
            void setSegundoValor(double newSegundoValor);
            double getSegundoValor()const;
        private:
            //Atributos
            QString valores;
            double primeiroValor;
            double segundoValor;
    };
}
#endif // CALCULADORA_H

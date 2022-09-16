#ifndef CALCULADORA_H
#define CALCULADORA_H

namespace abd{
    class Calculadora
    {
        public:
            Calculadora();
            Calculadora(double primeiroValor, double segundoValor);
            double calcularAdicao()const;
            double calcularSubtracao()const;
            double calcularMultiplicacao()const;
            double calcularDivisao()const;
            double calcularRadiciacao()const;
            double calcularPotenciacao()const;
            void setPrimeiroValor(double newPrimeiroValor);
            double getPrimeiroValor()const;
            void setSegundoValor(double newSegundoValor);
            double getSegundoValor()const;
        private:
            double primeiroValor;
            double segundoValor;
    };
}
#endif // CALCULADORA_H

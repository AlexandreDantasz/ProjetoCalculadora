#include "calculadora.h"


namespace abd{
    Calculadora::Calculadora():
    primeiroValor(0.0),
    segundoValor(0.0)
    {
    }
    Calculadora::Calculadora(double primeiroValor, double segundoValor):
    primeiroValor(0.0),
    segundoValor(0.0)
    {
        this->primeiroValor = primeiroValor;
        this->segundoValor = segundoValor;
    }
    double Calculadora::getPrimeiroValor()const{
        return primeiroValor;
    }
    void Calculadora::setPrimeiroValor(double newPrimeiroValor){
        primeiroValor = newPrimeiroValor;
    }
    double Calculadora::getSegundoValor()const{
        return primeiroValor;
    }
    void Calculadora::setSegundoValor(double newsegundoValor){
        segundoValor = newsegundoValor;
    }
    double Calculadora::calcularAdicao()const{
        return primeiroValor + segundoValor;
    }
    double Calculadora::calcularDivisao()const{
        return primeiroValor / segundoValor;
    }
    double Calculadora::calcularMultiplicacao()const{
        return primeiroValor * segundoValor;
    }
    double Calculadora::calcularPotenciacao(double valorDaBase, double expoente)const{
        return pow(valorDaBase,expoente);
    }
    double Calculadora::calcularRadiciacao(double valorNaRaiz)const{
        return sqrt(valorNaRaiz);
    }
}


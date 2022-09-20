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
    void Calculadora::setValores(QString newValores){
            valores = newValores;
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
        if(valores.size() == 1) throw QString ("Digite algum valor");
        return primeiroValor + segundoValor;
    }
    double Calculadora::calcularSubtracao()const{
        if(valores.size() == 1) throw QString ("Digite algum valor");
        return primeiroValor - segundoValor;
    }
    double Calculadora::calcularDivisao()const{
        if(segundoValor == 0 ) throw QString ("O denominador não pode ser zero(0).");
        return primeiroValor / segundoValor;
    }
    double Calculadora::calcularMultiplicacao()const{
        if(valores.size() == 1) throw QString ("Digite algum valor");
        return primeiroValor * segundoValor;
    }
    double Calculadora::calcularPotenciacao(double valorDaBase, double expoente)const{
        return pow(valorDaBase,expoente);
    }
    double Calculadora::calcularRadiciacao(double valorNaRaiz)const{
        return sqrt(valorNaRaiz);
    }
}


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
    double Calculadora::calcularAdicao()const{ //  Função que calcula a adição de 2 valores
        if(valores.size() == 1) throw QString ("Digite algum valor");
        return primeiroValor + segundoValor;
    }
    double Calculadora::calcularSubtracao()const{ // função que calcula a subtração
        if(valores.size() == 1) throw QString ("Digite algum valor");
        return primeiroValor - segundoValor;
    }
    double Calculadora::calcularDivisao()const{ // função que calcula a divisão
        if(segundoValor == 0 ) throw QString ("O denominador não pode ser zero(0)."); // tratamento de excessão caso digite 0 como denominador
        return primeiroValor / segundoValor;
    }
    double Calculadora::calcularMultiplicacao()const{ // função que calcula a multiplicação
        if(valores.size() == 1) throw QString ("Digite algum valor"); // tratamento de excessão caso o usuário digite mais de um operador
        return primeiroValor * segundoValor;
    }
    double Calculadora::calcularPotenciacao(double valorDaBase, double expoente)const{ // função que calcula a potênciação
        if(valores.size() == 1) throw QString("Digite algum valor."); // tratamento de excessão caso o usuário digite mais de um operador
        return pow(valorDaBase,expoente);
    }
    double Calculadora::calcularRadiciacao(double valorNaRaiz)const{ // função que calcula a raiz de índice 2
        if(valorNaRaiz < 0) throw QString("o número não pode ser negativo"); // tratamento de excessão para o caso do usuário digitar um número negativo dentro da raiz
        return sqrt(valorNaRaiz);
    }
    double Calculadora::calcularRadiciacao(double valorNaRaiz, double indice)const{ // função que calcula a raiz de qualquer índice
        if(valorNaRaiz < 0) throw QString("o número não pode ser negativo"); // tratamento de excessão para o caso do usuário digitar um número negativo dentro da raiz
        return pow(valorNaRaiz, 1/indice);
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

abd::Calculadora resultado;
QString saida;
int contador=0,contadorDePontos=0;
bool verificador;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonInformacoes_clicked()
{
    QMessageBox::about(this,"Versão 1.0\n", "Devs:\n" "Alexandre Dantas\n" "Bruno Enzo \n" "Diego Silva\n");
}


void MainWindow::on_pushButtonZero_clicked()
{
    saida += '0';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonUm_clicked()
{
    saida += '1';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonDois_clicked()
{
    saida += '2';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonTres_clicked()
{
    saida += '3';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonSeis_clicked()
{
    saida += '6';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonQuatro_clicked()
{
    saida += '4';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonCinco_clicked()
{
    saida += '5';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonSete_clicked()
{
    saida += '7';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonOito_clicked()
{
    saida += '8';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonNove_clicked()
{
    saida += '9';
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonMultiplicacao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
        saida += '*';
        resultado.setValores(saida);
        contador++;
        ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonSubtracao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0 && saida[saida.size() - 1] != '/') throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
        saida += '-';
        resultado.setValores(saida);
        if(saida.size() > 1){
            contador++;
        }
        ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAdicao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
        saida += '+';
        resultado.setValores(saida);
        contador++;
        ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonParteDecimal_clicked()
{
    try {
    if(contadorDePontos > 0) throw QString ("HÁ MAIS DE UM PONTO FLUTUANTE EM UM DOS VALORES.");
    saida += '.';
    resultado.setValores(saida);
    contadorDePontos++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonPotencializacao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
        saida += '^';
        resultado.setValores(saida);
        contador++;
        ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonRadiciacao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
        saida += "√";
        resultado.setValores(saida);
        ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonDivisao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0 && saida[0] != '-') throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
        saida += '/';
        resultado.setValores(saida);
        contador++;
        ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAC_clicked()
{
    saida.clear();
    resultado.setValores(saida);
    contador=0;
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonApagar_clicked()
{
    if(!saida.isEmpty()){
        contador=0;
        contadorDePontos=0;
        QString rad = "√";
        QString copia = saida;
        int tam = saida.size();
        saida.clear();
        for(int i = 0; i < tam - 1; i++){
            saida += copia[i];
        }
        int i = tam - 1;
        if(copia[i] == '+' || copia[i] == '-' || copia[i] == '*' || copia[i] == '/' || copia[i] == '^' || copia[i] == rad)
        {
            contador--;
        }
        else
        {
            if(copia[i] == '.')
            {
                contadorDePontos--;
            }
        }
        resultado.setValores(saida);
        ui->lineEditOperacoes->setText(saida);
    }
}


void MainWindow::on_pushButtonExecutar_clicked()
{
    try{
        contador = 0;
        contadorDePontos=0;
        if(saida.isEmpty()){
            ui->lineEditResultado->setText(saida);
        }
        else
        {
            contador=0;
            QString rad = "√";
            int i, k;
            for(i = 0; i < saida.size() && saida[i] != '+' && (saida[i] != '-' || i == 0) && saida[i] != '*' && saida[i] != '/' && saida[i] != rad && saida[i] != '^'; i++);
            QString primeiroValor, segundoValor;
            for(k = 0; k < i; k++){
                primeiroValor += saida[k];
            }
            for(k = i + 1; k < saida.size(); k++){
                segundoValor += saida[k];
            }
            resultado.setPrimeiroValor(primeiroValor.toDouble());
            resultado.setSegundoValor(segundoValor.toDouble());
            if(i == saida.size())
            {
                ui->lineEditResultado->setText(saida);
            }
            else
            {
                if(saida[i] == '+'){
                    saida = QString::number(resultado.calcularAdicao());
                }
                else{
                    if(saida[i] == '-'){
                        saida = QString::number(resultado.calcularSubtracao());
                    }
                    else
                    {
                        if(saida[i] == '*'){
                            saida = QString::number(resultado.calcularMultiplicacao());
                        }
                        else
                        {
                            if(saida[i] == '/'){
                                saida = QString::number(resultado.calcularDivisao());
                            }
                            else
                            {
                                if(saida[i] == '^'){
                                    saida = QString::number(resultado.calcularPotenciacao(primeiroValor.toDouble(), segundoValor.toDouble()));
                                }
                                else
                                {
                                    if(saida[0] == '-')
                                    {
                                        saida.clear();
                                        saida +='-';
                                        saida += QString::number(resultado.calcularRadiciacao(segundoValor.toDouble()));
                                    }
                                    else
                                    {
                                        saida += QString::number(resultado.calcularRadiciacao(segundoValor.toDouble()));
                                    }
                                }
                            }
                        }
                    }
                }
                ui->lineEditResultado->setText(saida);
            }
        }
    }
    catch (QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

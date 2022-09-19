#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QMessageBox>

QString saida;
int contador=0;

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
    QMessageBox::about(this,"Versão 1.0\n", "Devs\n" "Alexandre Dantas\n" "Bruno Enzo \n" "Diego Silva\n");
}


void MainWindow::on_pushButtonZero_clicked()
{
    saida += '0';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonUm_clicked()
{
    saida += '1';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonDois_clicked()
{
    saida += '2';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonTres_clicked()
{
    saida += '3';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonSeis_clicked()
{
    saida += '6';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonQuatro_clicked()
{
    saida += '4';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonCinco_clicked()
{
    saida += '5';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonSete_clicked()
{
    saida += '7';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonOito_clicked()
{
    saida += '8';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonNove_clicked()
{
    saida += '9';
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonMultiplicacao_clicked()
{
    try {
    if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
    saida += '*';
    contador++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonSubtracao_clicked()
{
    try {
    if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
    saida += '-';
    contador++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAdicao_clicked()
{
    try {
    if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
    saida += '+';
    contador++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonParteDecimal_clicked()
{
    try {
    if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
    saida += '.';
    contador++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonPotencializacao_clicked()
{
    try {
    if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
    saida += '^';
    contador++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonRadiciacao_clicked()
{
    try {
    if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
    saida += "√";
    contador++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonDivisao_clicked()
{
    try {
    if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE DUAS OPERACOES POR VEZ.");
    saida += '/';
    contador++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAC_clicked()
{
    saida.clear();
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonApagar_clicked()
{
    QString rad = "√";
    QString copia = saida;
    int tam = saida.size();
    saida.clear();
    for(int i = 0; i < tam - 1; i++){
        saida += copia[i];
    }

    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonExecutar_clicked()
{
    abd::Calculadora resultado;
    contador=0;
    QString rad = "√";
    int i, k;
    for(i = 0; i < saida.size() && saida[i] != '+' && saida[i] != '-' && saida[i] != '*' && saida[i] != '/' && saida[i] != rad && saida[i] != '^'; i++);
    QString primeiroValor, segundoValor;
    for(k = 0; k < i; k++){
        primeiroValor += saida[k];
    }
    for(k = i + 1; k < saida.size(); k++){
        segundoValor += saida[k];
    }

    resultado.setPrimeiroValor(primeiroValor.toDouble());
    resultado.setSegundoValor(segundoValor.toDouble());
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
                        saida = QString::number(resultado.calcularRadiciacao(segundoValor.toDouble()));
                    }
                }
            }
        }
    }
    ui->lineEditResultado->setText(saida);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

abd::Calculadora resultado;
QString saida;
int contador=0; // contador de operadores para verificação de quantidadade dos mesmos
int contadorDePontos=0; // contador de pontos flutuantes para verificação de quantidade dos mesmos
bool verificador = false;

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
    saida += '1'; // Adiciona valor 1 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonDois_clicked()
{
    saida += '2'; // Adiciona valor 2 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonTres_clicked()
{
    saida += '3'; // Adiciona valor 3 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonSeis_clicked()
{
    saida += '6'; // Adiciona valor 6 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonQuatro_clicked()
{
    saida += '4'; // Adiciona valor 4 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonCinco_clicked()
{
    saida += '5'; // Adiciona valor 5 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonSete_clicked()
{
    saida += '7'; // Adiciona valor 7 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonOito_clicked()
{
    saida += '8'; // Adiciona valor 8 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonNove_clicked()
{
    saida += '9'; // Adiciona valor 9 à saida
    resultado.setValores(saida);
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonMultiplicacao_clicked()
{
    if(!verificador)
    {
        try {
            contadorDePontos=0;
            if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE UMA OPERACAO POR VEZ.");
            saida += '*'; // adiciona o operador * à saida
            resultado.setValores(saida);
            contador++;
            ui->lineEditOperacoes->setText(saida);
            verificador = true;
        } catch (QString &erro) {
            QMessageBox::information(this,"ERRO DO SISTEMA",erro);
        }
    }
}


void MainWindow::on_pushButtonSubtracao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0 && saida[saida.size() - 1] != '/') throw QString ("O APLICATIVO NAO FAZ MAIS DE UMA OPERACAO POR VEZ.");
        saida += '-'; // adiciona o operador - à saida
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
    if(!verificador)
    {
        try {
            contadorDePontos=0;
            if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE UMA OPERACAO POR VEZ.");
            saida += '+'; // adiciona o operador + à saida
            resultado.setValores(saida);
            contador++;
            ui->lineEditOperacoes->setText(saida);
            verificador = true;
        } catch (QString &erro) {
            QMessageBox::information(this,"ERRO DO SISTEMA",erro);
        }
    }
}


void MainWindow::on_pushButtonParteDecimal_clicked()
{
    try {
    if(contadorDePontos > 0) throw QString ("HÁ MAIS DE UM PONTO FLUTUANTE EM UM DOS VALORES.");
    saida += '.'; // adiciona o ponto flutuante à saida
    if(saida.size() == 1) // caso o primeiro caractere a ser digitado seja um ponto flutuante, será emitido um alerta e zerado o que foi digitado
    {
        saida.clear();
        throw QString ("Digite algum valor");
    }
    resultado.setValores(saida);
    contadorDePontos++;
    ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonPotencializacao_clicked()
{
    if(!verificador)
    {
        try {
            contadorDePontos=0;
            if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE UMA OPERACAO POR VEZ.");
            saida += '^'; // adiciona o operador ^ à saida
            resultado.setValores(saida);
            contador++;
            ui->lineEditOperacoes->setText(saida);
            verificador = true;
        } catch (QString &erro) {
            QMessageBox::information(this,"ERRO DO SISTEMA",erro);
        }
    }
}


void MainWindow::on_pushButtonRadiciacao_clicked()
{
    if(!verificador)
        {
        try {
            contadorDePontos=0;
            if(contador > 0) throw QString ("O APLICATIVO NAO FAZ MAIS DE UMA OPERACAO POR VEZ.");
            saida += "√"; // adiciona o operador de raiz à saida
            resultado.setValores(saida);
            ui->lineEditOperacoes->setText(saida);
            verificador = true;
        } catch (QString &erro) {
            QMessageBox::information(this,"ERRO DO SISTEMA",erro);
        }
    }
}


void MainWindow::on_pushButtonDivisao_clicked()
{
    try {
        contadorDePontos=0;
        if(contador > 0 && saida[0] != '-') throw QString ("O APLICATIVO NAO FAZ MAIS DE UMA OPERACAO POR VEZ.");
        saida += '/'; // adiciona o operador / à saida
        resultado.setValores(saida);
        contador++;
        ui->lineEditOperacoes->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAC_clicked()
{
    saida.clear(); // apagará tudo presente na variavel saida
    verificador = false;
    resultado.setValores(saida);
    contador=0;
    contadorDePontos = 0;
    ui->lineEditOperacoes->setText(saida);
}


void MainWindow::on_pushButtonApagar_clicked()
{
    if(!saida.isEmpty()){
        contador=0;
        contadorDePontos=0;
        QString rad = "√"; // variavel usada para armazenar o simbolo de raiz para comparação
        QString copia = saida; // variavel de copia para apagar o ultimo caractere digitado
        int tam = saida.size(); // identifica o tamanho da string
        saida.clear(); // apaga todos os dados dela
        for(int i = 0; i < tam - 1; i++){
            saida += copia[i]; // realiza o apagamento do ultimo caractere
        }
        int i = tam - 1;
        if(copia[i] == '+' || copia[i] == '-' || copia[i] == '*' || copia[i] == '/' || copia[i] == '^' || copia[i] == rad)
        {
            contador--; // caso o caractere seja digitado e apagado, não irá alterar o contador de número de operadores
        }
        else
        {
            if(copia[i] == '.')
            {
                contadorDePontos--; // caso o caractere seja digitado e apagado, não irá alterar o contador de número de pontos flutuantes
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
            ui->lineEditResultado->setText(saida); // caso o usuario aperte igual sem digitar nenhum valor, o texto presente na variavel saida sera impresso novamente na tela
        }
        else
        {
            contador=0;
            QString rad = "√"; // variavel usada para armazenar o simbolo de raiz para comparação
            int i, k;
            for(i = 0; i < saida.size() && saida[i] != '+' && (saida[i] != '-' || i == 0) && saida[i] != '*' && saida[i] != '/' && saida[i] != rad && saida[i] != '^'; i++);
            // for utilizado para identificar operadores
            QString primeiroValor, segundoValor;
            for(k = 0; k < i; k++){
                primeiroValor += saida[k]; // for usado para buscar o primeiro valor
            }
            for(k = i + 1; k < saida.size(); k++){
                segundoValor += saida[k]; // for usado para buscar o segundo valor
            }
            resultado.setPrimeiroValor(primeiroValor.toDouble());
            resultado.setSegundoValor(segundoValor.toDouble());
            if(i == saida.size()) // caso seja digitado apenas um valor e não seja apresentado operador, ao apertar "=", o mesmo valor será retornado como resultado
            {
                ui->lineEditResultado->setText(saida);
            }
            else // identifica a operacao e chama o metodo correspondente
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
                                        if(i == 0)
                                        {
                                            saida = QString::number(resultado.calcularRadiciacao(segundoValor.toDouble()));
                                        }
                                        else
                                        {
                                            saida = QString::number(resultado.calcularRadiciacao(segundoValor.toDouble(), primeiroValor.toDouble()));
                                        }
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculadora.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInformacoes_clicked();

    void on_pushButtonZero_clicked();

    void on_pushButtonUm_clicked();

    void on_pushButtonDois_clicked();

    void on_pushButtonTres_clicked();

    void on_pushButtonSeis_clicked();

    void on_pushButtonQuatro_clicked();

    void on_pushButtonCinco_clicked();

    void on_pushButtonSete_clicked();

    void on_pushButtonOito_clicked();

    void on_pushButtonNove_clicked();

    void on_pushButtonMultiplicacao_clicked();

    void on_pushButtonSubtracao_clicked();

    void on_pushButtonAdicao_clicked();

    void on_pushButtonParteDecimal_clicked();

    void on_pushButtonPotencializacao_clicked();

    void on_pushButtonRadiciacao_clicked();

    void on_pushButtonDivisao_clicked();

    void on_pushButtonAC_clicked();

    void on_pushButtonApagar_clicked();

    void on_pushButtonExecutar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

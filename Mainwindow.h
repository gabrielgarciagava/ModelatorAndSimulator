#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simulador.h"
#include "sstream"
#include <iostream>

namespace Ui {
class MainWindow;
}

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:
    Simulador * sim;
    int nServidoresLocais;
    static const double ll_inf = 0.12;
    static const double lr_inf = 0.11;
    static const double ll_sup = 0.15;
    static const double lr_sup = 0.14;
    int taxa_suc_local;
    int taxa_frac_local;
    int nServidoresRemotos;
    static const double rl_inf = 0.10;
    static const double rr_inf = 0.13;
    static const double rl_sup = 0.12;
    static const double rr_sup = 0.15;
    int taxa_suc_remoto;
    int taxa_frac_remoto;
    int tempoDeSimulacao;
    void amostrarEstatisticas();
    //void *simThread(void *);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_botao_inicio_simulacao_clicked();

    void on_botao_parar_simulacao_clicked();

    void on_botao_pausar_simulacao_clicked();

    void on_botao_avancar_simulacao_clicked();

    void on_tamanho_passo_tela_textChanged();

    void on_tamanho_passo_valueChanged(int value);

    void on_edit_serv_local_textChanged(const QString &arg1);

    void on_edit_suc_local_textChanged(const QString &arg1);

    void on_edit_frac_local_textChanged(const QString &arg1);

    void on_edit_serv_remoto_textChanged(const QString &arg1);

    void on_edit_suc_remoto_textChanged(const QString &arg1);

    void on_edit_frac_remoto_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

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
    int nServidoresRemotos;
    int tempoDeSimulacao;
    //void *simThread(void *);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_botao_inicio_simulacao_clicked();

    void on_botao_parar_simulacao_clicked();

    void on_botao_pausar_simulacao_clicked();

    void on_botao_avancar_simulacao_clicked();

    void on_edit_serv_local_returnPressed();

    void on_edit_suc_local_returnPressed();

    void on_edit_frac_local_returnPressed();

    void on_edit_serv_remoto_returnPressed();

    void on_edit_suc_remoto_returnPressed();

    void on_edit_frac_remoto_returnPressed();

    void on_tamanho_passo_tela_textChanged();

    void on_tamanho_passo_sliderReleased();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

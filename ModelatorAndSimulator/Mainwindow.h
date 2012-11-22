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

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_botao_inicio_simulacao_clicked();

    void on_botao_parar_simulacao_clicked();

    void on_botao_pausar_simulacao_clicked();

    void on_botao_avancar_simulacao_clicked();

    void on_tamanho_passo_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

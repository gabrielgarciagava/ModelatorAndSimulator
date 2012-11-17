#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_botao_inicio_simulacao_clicked();

    void on_botao_parar_simulacao_clicked();

    void on_botao_pausar_simulacao_clicked();

    void on_botao_avancar_simulacao_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

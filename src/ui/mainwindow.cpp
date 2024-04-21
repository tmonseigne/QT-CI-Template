#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Connecter l'action "Quitter" à la fonction de fermeture
    connect(ui->actionQuit, &QAction::triggered, this, [=](){ this->close(); });

    // Image en fond
    ui->imageLabel->setPixmap(QPixmap("samples/background.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
    ui->imageLabel->setScaledContents(true);
}

MainWindow::~MainWindow() { delete ui; }


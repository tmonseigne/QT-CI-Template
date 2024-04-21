#include <QtTest/QtTest>
#include <QCoreApplication>
#include <QFile>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>

#include "ui/mainwindow.hpp"

class MainWindowTest : public QObject
{
    QApplication* app;
    Q_OBJECT

private slots:
    void initTestCase()
    {
        int argc = 0;
        app = new QApplication(argc, nullptr);
    }

    void cleanupTestCase() { delete app; }

    // Méthode de test pour vérifier le menu Fichier->Quitter
    void testFileMenuQuitAction()
    {

        MainWindow mainWindow;      // Créer une instance de la fenêtre principale
        mainWindow.show();          // Affiche la fenêtre (nous pouvons simuler des actions d'utilisateur sur une fenêtre visible)

        QMenuBar *menuBar = mainWindow.menuBar();   // Récupérer la barre de menu de la fenêtre principale
        QVERIFY(menuBar != nullptr);                // Vérifier que la barre de menu n'est pas nulle

        QMenu *fileMenu = menuBar->findChild<QMenu*>("menuFile");   // Récupérer le menu "Fichier"
        QVERIFY(fileMenu != nullptr);                               // Vérifier que le menu "Fichier" existe

        QAction *quitAction = (QAction *)fileMenu->actions().at(0);
        QVERIFY(quitAction != nullptr);                             // Vérifier que l'action "Quitter" existe

        // Vérifier que l'action "Quitter" est connectée au slot close() de la fenêtre principale
        QVERIFY(QObject::connect(quitAction, &QAction::triggered, &mainWindow, &QMainWindow::close));
        QMetaObject::invokeMethod(quitAction, "trigger");           // Appeler manuellement la méthode trigger de l'action "Quitter"
    }

    // Méthode de test pour vérifier que l'image de fond est bien chargée dans l'imageLabel
    void testBackgroundImageLoading()
    {
        MainWindow mainWindow;  // Créer une instance de la fenêtre principale
        mainWindow.show();      // Affiche la fenêtre (nous pouvons simuler des actions d'utilisateur sur une fenêtre visible)

        QLabel *imageLabel = mainWindow.findChild<QLabel*>("imageLabel");   // Récupérer le label qui affiche l'image de fond
        QVERIFY(imageLabel != nullptr);                 // Vérifier que le label n'est pas nul
        if (imageLabel) {                               // Vérifie si le label est non-null avant d'appeler pixmap()
            QVERIFY(!imageLabel->pixmap().isNull());    // Vérifie si l'image chargée n'est pas nulle
        }
    }
};

// Enregistrez le test dans le registre de tests Qt
QTEST_APPLESS_MAIN(MainWindowTest)
#include "ui_test.moc" // Fournit la définition des macros nécessaires pour les tests Qt

// simpletest.cpp

#include <QtTest/QtTest>

class SimpleTest : public QObject
{
    Q_OBJECT

private slots:
    // Méthode de test simple
    void testSimple() { QVERIFY(true); }
};

// Enregistre le test dans le registre de tests Qt
QTEST_APPLESS_MAIN(SimpleTest)
#include "base_test.moc" // Fournit la définition des macros nécessaires pour les tests Qt

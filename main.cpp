#include <QApplication>
#include "Controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller* c = new Controller();
    return a.exec();
}

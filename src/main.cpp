#include <iostream>
#include <QDebug>

#include "utils/OBCHelpers.hpp"

int main(int argc, char *argv[])
{
    std::cout << "hello world!" << std::endl;
    qDebug() << "hello QT5!";

    qDebug() << Base64Encode("hello world");

    return 0;
}

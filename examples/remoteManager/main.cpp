#include <QApplication>
#include <QJsonObject>

#include "utils/OBCHelpers.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QJsonObject config = JsonFromString(StringFromFile("C:/Users/bin/Desktop/x64/Debug/config_debug/components.json"));

    return app.exec();
}
#include <QApplication>
#include <QJsonObject>

#include "utils/OBCHelpers.hpp"
#include "3rdparty/QJsonStruct/QJsonIO.hpp"
#include "3rdparty/QJsonStruct/QJsonStruct.hpp"

#include <chrono>
using namespace std::chrono;
struct __OBCConfigObjectBase
{
    QString displayName;
    qint64 creationDate = system_clock::to_time_t(system_clock::now());
    qint64 lastUpdatedDate = system_clock::to_time_t(system_clock::now());
    JSONSTRUCT_REGISTER(__OBCConfigObjectBase, F(displayName, creationDate, lastUpdatedDate))
};

struct ComponentItemObject
{
    int type;
    QJsonObject settings;

    //ComponentItemObject(int _type, const QJsonObject _settings) : type(_type), settings(_settings){};

    JSONSTRUCT_COMPARE(ComponentItemObject, type, settings)
    JSONSTRUCT_REGISTER(ComponentItemObject, F(type, settings))
};

struct ComponentObject : __OBCConfigObjectBase
{
    QString addr = "127.0.0.1";//默认
    int port = 5556;

    ComponentObject() :__OBCConfigObjectBase() {};

    JSONSTRUCT_COMPARE(ComponentObject, addr, port)
    JSONSTRUCT_REGISTER(ComponentObject, F(addr, port), B(__OBCConfigObjectBase))
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QJsonObject config = JsonFromString(StringFromFile("C:/Users/bin/Desktop/x64/Debug/config_debug/components.json"));

    return app.exec();
}
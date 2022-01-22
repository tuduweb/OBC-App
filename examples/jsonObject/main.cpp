#include <QApplication>
#include <QDebug>
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

//need register to [toJson & fromJson] system
struct ComponentItemObject
{
    int meta = 123;
    int type;
    QJsonObject settings;

    //ComponentItemObject(int _type, const QJsonObject _settings) : type(_type), settings(_settings){};

    JSONSTRUCT_COMPARE(ComponentItemObject, type, settings)
    JSONSTRUCT_REGISTER(ComponentItemObject, F(type, settings, meta))
};

struct ComponentObject : __OBCConfigObjectBase
{
    QList<ComponentItemObject> components;

    ComponentObject() :__OBCConfigObjectBase() {};

    JSONSTRUCT_COMPARE(ComponentObject, components)
    JSONSTRUCT_REGISTER(ComponentObject, F(components), B(__OBCConfigObjectBase))
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QJsonObject config = JsonFromString(StringFromFile("C:/Users/bin/Desktop/x64/Debug/config_debug/components.json"));

    ComponentObject container;
    ComponentItemObject item;
    item.type = 1;
    item.settings = { {"type", 123}, {"other", "shuxing"} };
    item.meta = 2;

    qDebug() << JsonToString(item.toJson());
    
    container.components.append(item);
    container.components.append(item);
    container.components.append(item);
    container.components.append(item);
    container.components.append(item);

    qDebug() << container.components.count();
    qDebug() << JsonToString(container.toJson());
    

    return app.exec();
}
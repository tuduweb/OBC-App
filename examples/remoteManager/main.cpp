#include <QApplication>
#include <QDebug>
#include <QJsonObject>

#include "utils/OBCHelpers.hpp"
#include "3rdparty/QJsonStruct/QJsonIO.hpp"
#include "3rdparty/QJsonStruct/QJsonStruct.hpp"

/////////////////////////////////////////////////////////////////////
template<typename T>
class IDType
{
public:
    explicit IDType() : m_id("null") {};
    explicit IDType(const QString& id) : m_id(id) {};
    friend bool operator==(const IDType<T>& lhs, const IDType<T>& rhs)
    {
        return lhs.m_id == rhs.m_id;
    }
    friend bool operator!=(const IDType<T>& lhs, const IDType<T>& rhs)
    {
        return lhs.m_id != rhs.m_id;
    }
    //用作拓展QMap类型的key
    friend bool operator<(const IDType<T>& lhs, const IDType<T>& rhs)
    {
        return lhs.m_id < rhs.m_id;
    }
    const QString toString() const
    {
        return m_id;
    }
    void loadJson(const QJsonValue& d)
    {
        m_id = d.toString("null");
    }
    QJsonValue toJson() const
    {
        return m_id;
    }

private:
    QString m_id;
};

// extends hash
template<typename T>
inline uint qHash(IDType<T> key)
{
    return ::qHash(key.toString());
}


// Define several safetypes to prevent misuse of QString.
#define DECL_IDTYPE(type)                                                                                                                            \
    class __##type;                                                                                                                                  \
    typedef IDType<__##type> type

DECL_IDTYPE(ComponentId);

Q_DECLARE_METATYPE(ComponentId)

inline const static ComponentId NullComponentId;



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
    ComponentId id = NullComponentId;
    int meta = 123;
    int type;
    QJsonObject settings;
    

    //ComponentItemObject(int _type, const QJsonObject _settings) : type(_type), settings(_settings){};

    JSONSTRUCT_COMPARE(ComponentItemObject, type, settings, id)
    JSONSTRUCT_REGISTER(ComponentItemObject, F(type, settings, id, meta))
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
    //item.settings = { {"type", 123}, {"other", "shuxing"} };
    item.meta = 2;
    item.id = ComponentId{"myId"};

    qDebug() << JsonToString(item.toJson());
    
    container.components.append(item);
    container.components.append(item);
    container.components.append(item);
    container.components.append(item);
    container.components.append(item);

    qDebug() << container.components.count();
    //qDebug() << JsonToString(container.toJson());

    return app.exec();
}
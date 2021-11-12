#include "plugin/PluginInterface.hpp"

#include <QObject>


using namespace OBC::Plugin;

class MockPlugin : public QObject, OBC::Plugin::ObInterface
{
public:
    bool InitializePlugin(const QString &, const QJsonObject &) override;
};
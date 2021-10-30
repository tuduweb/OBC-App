#pragma once

#include <QString>

namespace OBC::core::settings
{
    void SaveGlobalSettings();
    bool LocateConfiguration();
    void SetConfigDirPath(const QString &path);
    bool CheckSettingsPathAvailability(const QString &_path, bool checkExistingConfig);
}

using namespace OBC::core::settings;
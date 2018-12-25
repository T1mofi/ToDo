#pragma once

#include <QString>
#include "specialtypes.h"

class Priority
{
public:
    Priority(importanceDegree newImportance = lightly);
    ~Priority() {}

    void setImportance(importanceDegree newImportance);
    QString getImportanceStyle() const;
    importanceDegree getImportanceDegree() const;

private:
    importanceDegree importance;
    QString color[3];
};

#include "priority.h"

Priority::Priority(importanceDegree newImportance) : importance(newImportance)
{
    color[lightly] = "background-color: rgb(100, 230, 100);";
    color[important] = "background-color: rgb(50, 150, 230);";
    color[veryImportant] = "background-color: rgb(230, 50, 50);";
}

void Priority::setImportance(importanceDegree newImportance)
{
    importance = newImportance;
}

QString Priority::getImportanceStyle() const
{
    return color[importance];
}

importanceDegree Priority::getImportanceDegree() const
{
    return importance;
}

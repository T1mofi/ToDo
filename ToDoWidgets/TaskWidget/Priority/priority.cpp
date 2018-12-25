#include "priority.h"

Priority::Priority(importanceDegree newImportance) : importance(newImportance)
{
    color[lightly] = "background-color: rgb(150, 250, 150);";
    color[important] = "background-color: rgb(170, 255, 255);";
    color[veryImportant] = "background-color: rgb(250, 150, 150);";
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

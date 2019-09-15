#ifndef ENHANCEDQMLAPPLICATIONENGINE_H
#define ENHANCEDQMLAPPLICATIONENGINE_H
#include <QQmlApplicationEngine>

class EnhancedQmlApplicationEngine:public QQmlApplicationEngine
{
    Q_OBJECT
public:
  EnhancedQmlApplicationEngine(QObject *parent=nullptr);

  Q_INVOKABLE void clearCache();
};

#endif // ENHANCEDQMLAPPLICATIONENGINE_H

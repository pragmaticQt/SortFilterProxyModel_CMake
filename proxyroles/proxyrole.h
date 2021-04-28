#ifndef PROXYROLE_H
#define PROXYROLE_H

#include "global.h"
#include <QObject>
#include <QMutex>

namespace qqsfpm {

class QQmlSortFilterProxyModel;

class SFPM_API_ ProxyRole : public QObject
{
    Q_OBJECT

public:
    using QObject::QObject;
    virtual ~ProxyRole() = default;

    QVariant roleData(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel, const QString& name);
    virtual void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel);

    virtual QStringList names() = 0;

protected:
    void invalidate();

Q_SIGNALS:
    void invalidated();
    void namesAboutToBeChanged();
    void namesChanged();

private:
    virtual QVariant data(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel, const QString& name) = 0;

    QMutex m_mutex;
};

void registerProxyRoleTypes();

}

#endif // PROXYROLE_H

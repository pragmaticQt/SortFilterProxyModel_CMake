#ifndef TESTROLES_H
#define TESTROLES_H

#include "proxyroles/singlerole.h"
#include <QVariant>

class SFPM_API_ StaticRole : public qqsfpm::SingleRole
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
public:
    using qqsfpm::SingleRole::SingleRole;

    QVariant value() const;
    void setValue(const QVariant& value);

Q_SIGNALS:
    void valueChanged();

protected:

private:
    QVariant data(const QModelIndex& sourceIndex, const qqsfpm::QQmlSortFilterProxyModel& proxyModel) override;
    QVariant m_value;
};

class SFPM_API_ SourceIndexRole : public qqsfpm::SingleRole
{
public:
    using qqsfpm::SingleRole::SingleRole;

private:
    QVariant data(const QModelIndex& sourceIndex, const qqsfpm::QQmlSortFilterProxyModel& proxyModel) override;
};

class SFPM_API_ MultiRole : public qqsfpm::ProxyRole
{
public:
    using qqsfpm::ProxyRole::ProxyRole;

    QStringList names() override;

private:
    QVariant data(const QModelIndex &sourceIndex, const qqsfpm::QQmlSortFilterProxyModel &proxyModel, const QString &name) override;
};

#endif // TESTROLES_H

#ifndef SortFilterProxyModel_PLUGIN_H
#define SortFilterProxyModel_PLUGIN_H

#include "global.h"
#include <QQmlExtensionPlugin>

/**
 * @brief The SortFilterProxyModelPlugin class.
 */

class SortFilterProxyModelPlugin: public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "SortFilterProxyModel/1.0")
public:

    /**
     * @brief registerTypes Overrided function that should register all
     * C++ classes exported by this plugin.
     * @param uri           Plugin uri.
     */
    void registerTypes(const char* uri) override;
};

#endif // SortFilterProxyModel_PLUGIN_H

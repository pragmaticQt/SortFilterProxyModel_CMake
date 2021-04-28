#include "sortfilterproxymodelplugin.h"

#include "qqmlsortfilterproxymodel.h"
#include "sorters/sorter.h"
#include "filters/filter.h"
#include "proxyroles/proxyrole.h"


void SortFilterProxyModelPlugin::registerTypes(const char* uri) {

    Q_ASSERT(uri == QLatin1String("SortFilterProxyModel"));

    qqsfpm::registerFiltersTypes();
    qqsfpm::registerProxyRoleTypes();
    qqsfpm::registerQQmlSortFilterProxyModelTypes();
    qqsfpm::registerSorterTypes();

}

#include "CustomSelectionModel.h"



CustomSelectionModel::CustomSelectionModel(QAbstractItemView *view, QAbstractItemModel *model)
	: QItemSelectionModel(model), m_view(view) {}

void CustomSelectionModel::select(const QItemSelection &selection, QItemSelectionModel::SelectionFlags command)
{
	qDebug("selecting");
}

#include "CustomStringListModel.h"


CustomStringListModel::CustomStringListModel(QObject *parent) : QStringListModel(parent)
{

}
QVariant CustomStringListModel:: data(const QModelIndex &index, int role) const
  {
	  if (role == Qt::UserRole+1)
	  {
		  return m_colors.value(index.row(), QColor(Qt::black));
	  }
	  return QStringListModel::data(index, role);
  }

  bool CustomStringListModel:: setData(const QModelIndex &index, const QVariant &value, int role)
  {
	  if (role == Qt::UserRole+1)
	  {
		  m_colors[index.row()] = value.value<QColor>();
		  emit dataChanged(index, index, {role});
		  return true;
	  }
	  return QStringListModel::setData(index, value, role);
  }

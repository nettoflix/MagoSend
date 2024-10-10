#ifndef CUSTOMSTRINGLISTMODEL_H
#define CUSTOMSTRINGLISTMODEL_H

#include <QColor>
#include <QStringListModel>


class CustomStringListModel : public QStringListModel
{
public:
	CustomStringListModel(QObject *parent = nullptr);
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	 bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
private:
	QHash<int, QColor> m_colors; // Store colors by row index
};

#endif // CUSTOMSTRINGLISTMODEL_H

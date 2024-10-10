#ifndef CUSTOMSELECTIONMODEL_H
#define CUSTOMSELECTIONMODEL_H


#include <QItemSelectionModel>
#include <QAbstractItemView>

class CustomSelectionModel : public QItemSelectionModel {
public:
	CustomSelectionModel(QAbstractItemView *view, QAbstractItemModel *model);

protected:
	void select(const QItemSelection &selection, QItemSelectionModel::SelectionFlags command) override;

private:
	QAbstractItemView *m_view;
};

#endif // CUSTOMSELECTIONMODEL_H

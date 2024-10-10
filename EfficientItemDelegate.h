#ifndef EFFICIENTITEMDELEGATE_H
#define EFFICIENTITEMDELEGATE_H
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QStyledItemDelegate>
#include <QAbstractItemView>

class EfficientItemDelegate : public QStyledItemDelegate {
public:
	using QStyledItemDelegate::QStyledItemDelegate;
	EfficientItemDelegate(QObject *parent = nullptr);
protected:
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // EFFICIENTITEMDELEGATE_H

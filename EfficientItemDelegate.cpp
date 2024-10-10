#include "EfficientItemDelegate.h"

EfficientItemDelegate::EfficientItemDelegate(QObject *parent): QStyledItemDelegate(parent)
{}

void EfficientItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	// Safely cast the widget to QAbstractItemView to access the viewport
	const QAbstractItemView *view = qobject_cast<const QAbstractItemView *>(option.widget);
	if (view) {
		// Use the viewport's rect for intersection checking
		if (!option.rect.intersects(view->viewport()->rect())) {
			return;  // Skip painting if not in the visible area
		}
	}
	QStyledItemDelegate::paint(painter, option, index);
}

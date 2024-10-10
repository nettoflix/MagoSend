#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QPainter>
#include <QStyleOptionViewItem>
#include <QStyledItemDelegate>


class HostListDelegate : public QStyledItemDelegate
{
public:
	HostListDelegate(QObject *parent = nullptr);
protected:
	Qt::GlobalColor textColor = Qt::black;
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};
#endif // CUSTOMDELEGATE_H


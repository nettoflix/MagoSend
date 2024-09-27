#include "HostListDelegate.h"

#include <QStyledItemDelegate>

HostListDelegate::HostListDelegate(QObject *parent): QStyledItemDelegate(parent) {

}
void HostListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
   {
	   QStyleOptionViewItem opt = option;
	   initStyleOption(&opt, index);
//	   // Set custom text color
//	   painter->save();
//	   opt.palette.setColor(QPalette::Text, textColor); // Change Qt::red
//	   QStyledItemDelegate::paint(painter, opt, index);
//	   painter->restore();

	// Retrieve the custom color from the model
	 QVariant colorData = index.data(Qt::UserRole+1);
	 if (colorData.isValid() && colorData.canConvert<QColor>())
	 {
		 QColor color = colorData.value<QColor>();
		 painter->save();
		 opt.palette.setColor(QPalette::Text, color); // Set the text color to the custom color
		 QStyledItemDelegate::paint(painter, opt, index);
		 painter->restore();
	 }
	 else
	 {
		 // If no custom color is set, use the default painting
		 QStyledItemDelegate::paint(painter, opt, index);
	 }
   }


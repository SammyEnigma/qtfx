#pragma once

#include "QAbstractItemModel"
#include "xo/container/prop_node.h"

class QPropNodeItemModel : public QAbstractItemModel
{
public:
	QPropNodeItemModel( QObject* parent = nullptr ) : QAbstractItemModel( parent ), props_() {}
	virtual ~QPropNodeItemModel() {}

	void setData( const xo::prop_node& pn );
	virtual QModelIndex index( int row, int column, const QModelIndex &parent = QModelIndex() ) const override;
	virtual QModelIndex parent( const QModelIndex &child ) const override;
	virtual int rowCount( const QModelIndex &parent = QModelIndex() ) const override;
	virtual int columnCount( const QModelIndex &parent = QModelIndex() ) const override;
	virtual QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const override;
	virtual QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const override;
	virtual bool setData( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole ) override;
	virtual Qt::ItemFlags flags( const QModelIndex &index ) const override;

private:
	xo::prop_node props_;
};

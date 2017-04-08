#include "chooselayerdialog.h"
#include "ui_chooselayerdialog.h"
#include "subdivlayer.h"

ChooseLayerDialog::ChooseLayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseLayerDialog),
    _listModel(nullptr), _data(nullptr)
{
    ui->setupUi(this);

    // create list view item model
    _listModel = new QStandardItemModel(ui->layerListView);
    ui->layerListView->setModel(_listModel);

    // register model item changed signal
    connect(_listModel, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(listItemChanged(QStandardItem*)));

    readSettings();
}

ChooseLayerDialog::~ChooseLayerDialog()
{
    saveSettings();
    delete ui;
}

void ChooseLayerDialog::initialize(ShipCAD::ChooseLayerDialogData& data)
{
    _data = &data;
    _listModel->clear();
    for (size_t i=0; i<data.layers.size(); i++) {
        QStandardItem* listItem = new QStandardItem(data.layers[i].first->getName());
        listItem->setCheckable(true);
        if (data.layers[i].second)
            listItem->setCheckState(Qt::Checked);
        else
            listItem->setCheckState(Qt::Unchecked);
        _listModel->setItem(i, listItem);
    }
}

void ChooseLayerDialog::retrieve(ShipCAD::ChooseLayerDialogData& /*data*/)
{
    // does nothing
}

// handles the checkbox indicator state
void ChooseLayerDialog::listItemChanged(QStandardItem *item)
{
    // Get current index from item
    const QModelIndex currentIndex =
            item->model()->indexFromItem(item);

    // set in data
    if (_data != nullptr) {
        Qt::CheckState state = item->checkState();
        if (state == Qt::Checked) {
            _data->layers[currentIndex.row()].second = true;
            emit layerSelected(_data->layers[currentIndex.row()].first);
        } else {
            _data->layers[currentIndex.row()].second = false;
            emit layerDeselected(_data->layers[currentIndex.row()].first);
        }
    }
}

void ChooseLayerDialog::closeEvent(QCloseEvent* event)
{
    saveSettings();
    QDialog::closeEvent(event);
}

void ChooseLayerDialog::readSettings()
{
    QSettings settings;
    restoreGeometry(settings.value("layerdialog-geometry").toByteArray());
}

void ChooseLayerDialog::saveSettings()
{
    QSettings settings;
    settings.setValue("layerdialog-geometry", saveGeometry());
}

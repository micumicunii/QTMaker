#include "inventory.h"
#include "ui_inventory.h"

Inventory::Inventory(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inventory)
{
    ui->setupUi(this);
    loadCategories();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Category" << "Item" << "Amount" << "Timestamp" << "ID" << "Description" << "Select");
}

Inventory::~Inventory()
{
    delete ui;
}

void Inventory::loadCategories() {
    categories.insert("Electronics", QStringList() << "Laptop" << "Television" << "Computer" << "Printer" << "Sound System" << "Aircon" << "Electric Fan" << "Water Dispenser" << "Projector" << "Fluorescent Light");
    categories.insert("Sports Equipment", QStringList() << "Football" << "Basketball" << "Volleyball" << "Shuttlecock" << "Court Ring" << "Net" << "Pole" << "Gym Mat" << "Tennis Table" << "Court Board");
    categories.insert("Lab Equipment", QStringList() << "Microscope" << "Test Tube" << "Beaker" << "Thermometer" << "Bunsen Burner" << "Safety Goggles" << "Funnel" << "Incubator" << "Calorimeter" << "Burette");
    categories.insert("Maintenance Supplies", QStringList() << "Mop" << "Broom" << "Dustpan" << "Trash Bag" << "Trash Can" << "Hand Soap" << "Paper Towel" << "Gloves" << "Floor Cleaner" << "Cleaning Cloth");
    categories.insert("Furniture", QStringList() << "Drafting Table" << "Computer Desk" << "Book Shelf" << "Drawing Stool" << "Bench" << "Monoblock" << "Library Desk" << "Long Table" << "Desk Chair" << "Tandem Seating");

    // Add categories to combo box
    ui->comboCategory->addItems(categories.keys());
}

void Inventory::on_btnAdd_clicked() {
    QString category = ui->comboCategory->currentText();
    QString item = ui->comboItem->currentText();
    QString amount = "1"; // For example, the amount can just be the row number
    QString timestamp = QDateTime::currentDateTime().toString("dd/MM/yy - HH:mm");
    QString id = QString("%1 %2").arg(category == "Electronics" ? "1111" : category == "Sports Equipment" ? "2222" :
                                                                           category == "Lab Equipment" ? "3333" : category == "Maintenance Supplies" ? "4444" : "5555").arg(++itemCounter[categories.keys().indexOf(category)]).rightJustified(4, '0');

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(category));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(item));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(amount));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(timestamp));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(id));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem("")); // Description cell
    ui->tableWidget->setCellWidget(row, 6, new QCheckBox()); // Checkbox for selection
}

void Inventory::on_btnLoad_clicked() {
    loadData();
}

void Inventory::loadData() {
    QFile file("data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    ui->tableWidget->setRowCount(0); // Clear existing data

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 6) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            for (int i = 0; i < fields.size(); ++i) {
                ui->tableWidget->setItem(row, i, new QTableWidgetItem(fields[i]));
                if (i == 6) { // Checkbox
                    ui->tableWidget->setCellWidget(row, 6, new QCheckBox());
                }
            }
        }
    }
    file.close();
}

void Inventory::on_btnRemove_clicked() {
    for (int i = ui->tableWidget->rowCount() - 1; i >= 0; --i) {
        QCheckBox* checkbox = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i, 6));
        if (checkbox && checkbox->isChecked()) {
            ui->tableWidget->removeRow(i);
        }
    }
}

void Inventory::on_btnSave_clicked() {
    saveData();
}

void Inventory::saveData() {
    QFile file("data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QStringList fields;
        for (int j = 0; j < 6; ++j) {
            fields << ui->tableWidget->item(i, j)->text();
        }
        out << fields.join(",") << "\n";
    }
    file.close();
}

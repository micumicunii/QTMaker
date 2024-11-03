#ifndef INVENTORY_H
#define INVENTORY_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QHash>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Inventory; }
QT_END_NAMESPACE

class Inventory : public QMainWindow
{
    Q_OBJECT

public:
    Inventory(QWidget *parent = nullptr);
    ~Inventory();

private slots:
    void on_btnAdd_clicked();
    void on_btnLoad_clicked();
    void on_btnRemove_clicked();
    void on_btnSave_clicked();

private:
    Ui::Inventory *ui;
    QHash<QString, QStringList> categories; // Category ID and corresponding items
    int itemCounter[5] = {0}; // For incrementing item IDs for each category
    void loadCategories();
    void saveData();
    void loadData();
};

#endif // INVENTORY_H

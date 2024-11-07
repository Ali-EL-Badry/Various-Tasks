#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QBrush>
#include <QColor>
#include <QHeaderView>
#include <QFont>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Memory->setStyleSheet(
        "QHeaderView::section {"
        "  background-color : #2a2e30; color: #3498db;"     // Text color for headers
        "}"
        );
    ui->Register->setStyleSheet(
        "QHeaderView::section {"
        "  background-color : #2a2e30; color: #3498db;"     // Text color for headers
        "}"
        );
    // Set the main window background color and text color
    this->setStyleSheet("background-color: #2a2e30; color: #3498db;");

    // Set the header background color and text color for tables
    ui->Memory->horizontalHeader()->setStyleSheet("background-color: #2a2e30; color: #3498db;");
    ui->Register->horizontalHeader()->setStyleSheet("background-color: #2a2e30; color: #3498db;");

    // Function to apply alternating row colors
    const QColor colorOdd("#3498db");  // Dark gray for odd rows
    const QColor colorEven("#2a2e30");  // Pink for even rows


    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < 16; col++) {
            QTableWidgetItem* item = ui->Memory->item(row, col);
            if (!item) {
                // If the item doesn't exist, create it
                item = new QTableWidgetItem("");
                ui->Memory->setItem(row, col, item);
            }

            // Set background color based on row index
            if (row % 2 == 0) {
                item->setBackground(QBrush(colorEven));
            } else {
                item->setBackground(QBrush(colorOdd));
                // Set vertical border color for odd rows to blue
                // item->setStyleSheet("border-right: 1px solid rgb(0, 0, 255);");
            }
        }
    }

    for (int row = 0; row < 16; row++) {
        QTableWidgetItem* item = ui->Register->item(row, 0);
        if (!item) {
            // If the item doesn't exist, create it
            item = new QTableWidgetItem("");
            ui->Register->setItem(row, 0, item);
        }

        // Set background color based on row index
        if (row % 2 == 0) {
            item->setBackground(QBrush(colorEven));
        } else {
            item->setBackground(QBrush(colorOdd));
            // Set vertical border color for odd rows to blue
            // item->setStyleSheet("border-right: 1px solid rgb(0, 0, 255);");
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bttnDecode_clicked()
{


}


void MainWindow::on_bttnInsert_clicked()
{

}


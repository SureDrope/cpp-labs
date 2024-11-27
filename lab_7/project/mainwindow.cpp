#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->isSortedAscending = true;
    ui->setupUi(this);

    m_db = QSqlDatabase::addDatabase("QSQLITE"); // соединение объекта базы данных с СУБД
    m_db.setDatabaseName("myDB.db");             // определение имени базы данных
    query = new QSqlQuery(m_db);                 // создание объекта для запроса

    if (!m_db.open())
    {
        QMessageBox::critical(this, "Error", "Can't open database");
    }

    if (!m_db.tables().contains("students")) // если в базе не существует таблица students,
    {                                        // то создание таблицы students и заполнение данными
        query->clear();                      // очистка запроса
        QString create_query =
            "CREATE TABLE IF NOT EXISTS students ("
            "id INTEGER PRIMARY KEY,"
            "surname VARCHAR(50) UNIQUE NOT NULL,"
            "university VARCHAR(50) NOT NULL,"
            "faculty VARCHAR(50) NOT NULL,"
            "year INTEGER NOT NULL"
            ")";

        if (!query->exec(create_query))
        {
            qDebug() << "Create table error:" << query->lastError().text();
            QMessageBox::critical(this, "Error", "Failed to create table");
        }
        query->clear();

        QString insert_query =
            "INSERT INTO students (surname, university, faculty, year) VALUES "
            "('Кушалиев', 'СПбГУТ', 'ИБ', 2),"
            "('Цыплаков', 'СПбГУТ', 'ИБ', 2),"
            "('Шалапаев', 'МГУ', 'ГИБ', 1),"
            "('Макрон', 'МГТУ', 'ИБ', 3),"
            "('Матвеев', 'АГТУ', 'АБОБА', 4);";

        if (!query->exec(insert_query))
        {
            qDebug() << "Insert error:" << query->lastError().text();
            QMessageBox::critical(this, "Error", "Failed to insert initial data");
        }
    }

    model = new QSqlTableModel(this, m_db); // создание редактируемой модели базы данных
    model->setTable("students");            // создание модели таблицы student
    model->select();                        // заполнение модели данными

    model->setEditStrategy(QSqlTableModel::OnFieldChange); // выбор стратегии сохранения изменений в базе данных
    // – сохранение происходит при переходе к другому полю
    ui->tableView->setModel(model); // соединение модели и ее табличного представления в форме

    ui->tableView->verticalHeader()->setVisible(false);                            // скрывает номер строки
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // расширяет столбцы горизонтально
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete query;
    delete model;
}

void MainWindow::on_allDataViewButton_clicked()
{
    model->setFilter("");
    model->select();
    ui->tableView->setModel(model);
}
void MainWindow::on_filterDataButton_clicked()
{
    model->setFilter("year > 2");
    model->select();
    ui->tableView->setModel(model);
}
void MainWindow::on_filterData2Button_clicked()
{
    model->setFilter("year <= 2");
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButtonAdd_clicked()
{
    if (ui->lineEditName->text().isEmpty() ||
        ui->lineEditUniversity->text().isEmpty() ||
        ui->lineEditFaculty->text().isEmpty() ||
        ui->lineEditYear->text().isEmpty())
        return;

    QString name = ui->lineEditName->text();
    QString university = ui->lineEditUniversity->text();
    QString faculty = ui->lineEditFaculty->text();
    QString year = ui->lineEditYear->text();

    QString insert_query = QString("INSERT INTO students (surname, university, faculty, year) VALUES ('%1', '%2', '%3', %4)")
                               .arg(name, university, faculty, year);

    query->clear();
    if (!query->exec(insert_query))
    {
        QMessageBox::critical(this, "Error", query->lastError().text());
    }
    model->select();
}

void MainWindow::on_pushButtonRem_clicked()
{
    if (ui->lineEditID->text().isEmpty())
        return;

    QString id = ui->lineEditID->text();
    query->clear();
    if (!query->exec(QString("DELETE FROM students WHERE id=%1").arg(id)))
    {
        QMessageBox::critical(this, "Error", QString("Failed to delete record with id=%1: %2").arg(id, query->lastError().text()));
    }
    model->select();
}

void MainWindow::on_pushButtonSort_clicked()
{
    if (isSortedAscending)
    {
        // Toggle between AscendingOrder and no order
        model->setSort(4, Qt::AscendingOrder);
    }
    else
    {
        // Set to no order
        model->setSort(0, Qt::SortOrder(0));
    }
    isSortedAscending = !isSortedAscending;
    model->select();
}

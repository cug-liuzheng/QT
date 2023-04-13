#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_newAction_triggered()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::on_openAction_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"选择一个文件",QCoreApplication::applicationFilePath(),"*.cpp");
    if (fileName.isEmpty()){
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else {
       // qDebug() << fileName;    //调试输出fileName
        QFile file(fileName);     //创建文件对象
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){   //打开文件
            QTextStream aStream(&file);     //使用文本流读取文件
            ui->textEdit->clear();
            while (!aStream.atEnd()){
                QString str = aStream.readLine();
                ui->textEdit->append(str);
            }

        }

    }
}

void MainWindow::on_saveAction_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"选择一个文件",QCoreApplication::applicationFilePath());
    if (fileName.isEmpty()){
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else{
        QFile aFile(fileName);
        if (aFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream aStream(&aFile);        //使用文本流读取文件
            aStream.setAutoDetectUnicode(true); //自动检测Unicode
            QString str = ui->textEdit->toPlainText();
            aStream << str;     //写入文本流
            aFile.close();
        }

    }
}

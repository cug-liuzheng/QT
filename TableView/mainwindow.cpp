#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QTextStream"

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


#define FixedColumnCount 6



void MainWindow::on_actOpenFile_triggered()
{
    //打开文件
    QString curPath = QCoreApplication::applicationDirPath();
    QString aFileName = QFileDialog::getOpenFileName(this,"打开一个文件",curPath,"井数据文件(*.txt*);;所有文件(*.*)");
    if (aFileName.isEmpty())
        return;

    QStringList fFileContent;
    QFile aFile(aFileName);
    if (aFile.open(QIODevice::ReadOnly | QIODevice::Text))  //打开文件
    {
        QTextStream aStream(&aFile);  //用文本流读取文件
        ui->plainTextEdit->clear();
        while (!aStream.atEnd()){
            QString str=aStream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fFileContent.append(str);
        }
        aFile.close();
    }

}

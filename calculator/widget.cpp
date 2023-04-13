#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("计算器");

    //在按钮中添加一个图片显示
    QIcon icon("E:\\SoftwareDevelopment\\QT\\C++\\calculator\\del.png");
    ui->delButton->setIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_oneButton_clicked()
{
    expression += '1';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_twoButton_clicked()
{
    expression += '2';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_threeButton_clicked()
{
    expression += '3';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_fourButton_clicked()
{
    expression += '4';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_fiveButton_clicked()
{
    expression += '5';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sixButton_clicked()
{
    expression += '6';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sevenButton_clicked()
{
    expression += '7';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_eightButton_clicked()
{
    expression += '8';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_nineButton_clicked()
{
    expression += '9';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_addButton_clicked()
{
    expression += '+';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_subButton_clicked()
{
    expression += '-';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_mulButton_clicked()
{
    expression += '*';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_divideButton_clicked()
{
    expression += '/';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_leftButton_clicked()
{
    expression += '(';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_zeroButton_clicked()
{
    expression += '0';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_rightButton_clicked()
{
    expression += ')';
    ui->mainLineEdit->setText(expression);
}

void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainLineEdit->clear();
}

void Widget::on_delButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}

void Widget::on_equalButton_clicked()
{
    QStack<int> s_num,s_opt;
    char opt[128] = {0};
    int i = 0;
    int tmp = 0;
    int num1;
    int num2;

    //把QString转换为char *
    QByteArray ba;
    ba.append(expression);  //把QString 转换为QByteArray
    strcpy(opt,ba.data());  //data可以把QByteArray转换成const char *

    while (opt[i] != '\0' && s_opt.empty() != true){
        if (opt[i] >= '0' && opt[i] <= '9'){
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if (opt[i] < '0' || opt[i] > '9'){
                s_num.push(tmp);
                tmp = 0;
            }
        }
        else{   //操作符


        }
    }



}

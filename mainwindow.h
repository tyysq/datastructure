﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define TR(str)   (QString::fromLocal8Bit(str))
#include <QMainWindow>
#include <QListWidgetItem>
#include <algorithm>
#include <vector>
#include <QtDebug>
#include <QDir>
#include <QMessageBox>

#include "address.h"
#include "openadress.h"
#include "openartical.h"
#include "hashmap.h"
#include "changeinfopage.h"

static QString EMAIL;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:   //槽函数
    void Press_AdressList();
    void Press_Text();
    void Press_AllAdress();
    void Press_GroupAdress();
    void Press_QueryAdress();
    void Press_TextInfo();
    void Press_DiffHashfun();
    void Press_DiffConflict();

    void Press_OpenAddressBook();
    void Press_AddMember();
    void Press_DeleteMember();
    void Press_ChangeMember();
    void Press_SortName();
    void Press_SortPhone();
    void Press_SortUp();
    void Press_SortDown();

    void Press_CreateGroup();
    void Press_ManageGroup();
    void Input_CreateGroup();
    void Press_MemberInGroup(QListWidgetItem* item);

    void Press_QueryMember();
    void Input_QueryMember();
    void Press_QueryInfo();

    void Press_AdressBook(QListWidgetItem* item);
    void Press_AdressFilename(QListWidgetItem* item);

    void Press_OpenArtical();
    void Press_ArticalFileName(QListWidgetItem* item);

    void Press_HashLinear();
    void Press_HashQsr();
    void Press_HashRandom();
    void Press_HashLink();
    void Press_HashNewRule();

    void Press_DiffSqr();
    void Press_DiffMod();
    void Press_DiffRandom();
    void Input_SetHashSIZE();

    void on_lineEdit_name_textChanged(const QString &arg1);
    void on_lineEdit_phone_textChanged(const QString &arg1);
    void on_lineEdit_address_textChanged(const QString &arg1);
    void on_lineEdit_remark_textChanged(const QString &arg1);
    void on_lineEdit_email_textChanged(const QString &arg1);
    void on_pushButton_clicked();



public:

    friend class OpenAdress;
    friend class OpenArtical;
    friend class ChangeInfoPage;

    bool PassEmail(QString email);

    explicit MainWindow(QWidget *parent = nullptr);

    void Set_LinkList();
    ~MainWindow();

private slots:
    void on_PB_ChangeMember_pressed();

private:
    Ui::MainWindow *ui;

    OpenAdress *openad;
    OpenArtical *openartical;
    ChangeInfoPage *changeinfopage;

    //数据链表
    AddressList addresslinklist;
    //数据二叉树
    AddressBTree addressBTree;

    QStringList article;
    HashMap hashMap;

    int type;
    int basis;
};

#endif // MAINWINDOW_H

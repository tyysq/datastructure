#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_openadress.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), openad(new OpenAdress)
{
    ui->setupUi(this);

    //设置文本框仅读
    ui->Text_MemberInfo->setReadOnly(true);
    ui->Text_OverallInfo->setReadOnly(true);

    //界面默认按钮
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->List_AddressBook->hide();
    ui->Text_MemberInfo->hide();
    ui->Text_OverallInfo->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();

    //按钮连接
    connect(ui->PB_AddressList, SIGNAL(clicked()), this, SLOT(Press_AdressList()));
    connect(ui->PB_Text, SIGNAL(clicked()), this, SLOT(Press_Text()));
    connect(ui->PB_AllAdress, SIGNAL(clicked()), this, SLOT(Press_AllAdress()));
    connect(ui->PB_GroupAdress, SIGNAL(clicked()), this, SLOT(Press_GroupAdress()));
    connect(ui->PB_QueryAdress, SIGNAL(clicked()), this, SLOT(Press_QueryAdress()));
    connect(ui->PB_TextInfo, SIGNAL(clicked()), this, SLOT(Press_TextInfo()));
    connect(ui->PB_DiffHashfun, SIGNAL(clicked()), this, SLOT(Press_DiffHashfun()));
    connect(ui->PB_DiffConflict, SIGNAL(clicked()), this, SLOT(Press_DiffConflict()));

    connect(ui->List_AddressBook, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_AdressBook(QListWidgetItem*)));

    connect(ui->PB_OpenAdressBook, SIGNAL(clicked()), this, SLOT(Press_OpenAddressBook()));
    connect(ui->PB_AddMember, SIGNAL(clicked()), this, SLOT(Press_AddMember()));
    connect(ui->PB_DeleteMember, SIGNAL(clicked()), this, SLOT(Press_DeleteMember()));
    connect(ui->PB_ChangeMember, SIGNAL(clicked()), this, SLOT(Press_ChangeMember()));
    connect(ui->PB_SortName, SIGNAL(clicked()), this, SLOT(Press_SortName()));
    connect(ui->PB_SortPhone, SIGNAL(clicked()), this, SLOT(Press_SortPhone()));
    connect(ui->PB_SortUp, SIGNAL(clicked()), this, SLOT(Press_SortUp()));
    connect(ui->PB_SortDown, SIGNAL(clicked()), this, SLOT(Press_SortDown()));

    connect(ui->PB_CreateGroup, SIGNAL(clicked()), this, SLOT(Press_CreateGroup()));
    connect(ui->PB_ManageGroup, SIGNAL(clicked()), this, SLOT(Press_ManageGroup()));
    connect(ui->Input_CreateGroup, SIGNAL(returnPressed()), this, SLOT(Input_CreateGroup()));
    connect(ui->List_MemberInGroup, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_MemberInGroup(QListWidgetItem*)));

    connect(ui->PB_QueryMember, SIGNAL(clicked()), this, SLOT(Press_QueryMember()));
    connect(ui->Input_QueryMember, SIGNAL(returnPressed()), this, SLOT(Input_QueryMember()));
    connect(ui->PB_QueryInfo, SIGNAL(clicked()), this, SLOT(Press_QueryInfo()));

    connect(openad->ui->List_AddressList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_AdressFilename(QListWidgetItem*)));
}

void MainWindow::Press_AdressList()
{
    //界面默认按钮
    ui->PB_AllAdress->show();
    ui->PB_GroupAdress->show();
    ui->PB_QueryAdress->show();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

    //通讯录-全部-控件
    ui->PB_OpenAdressBook->show();
    ui->List_AddressBook->show();
    ui->Text_MemberInfo->show();
    ui->Text_OverallInfo->show();
    ui->PB_AddMember->show();
    ui->PB_DeleteMember->show();
    ui->PB_ChangeMember->show();
    ui->PB_SortName->show();
    ui->PB_SortPhone->show();
    ui->PB_SortUp->show();
    ui->PB_SortDown->show();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();
}

void MainWindow::Press_Text()
{
    //界面默认按钮
    ui->PB_TextInfo->show();
    ui->PB_DiffHashfun->show();
    ui->PB_DiffConflict->show();
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();

    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->List_AddressBook->hide();
    ui->Text_MemberInfo->hide();
    ui->Text_OverallInfo->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();
}

void MainWindow::Press_AllAdress()
{
    //通讯录-全部-控件
    ui->PB_OpenAdressBook->show();
    ui->PB_AddMember->show();
    ui->PB_DeleteMember->show();
    ui->PB_ChangeMember->show();
    ui->PB_SortName->show();
    ui->PB_SortPhone->show();
    ui->PB_SortUp->show();
    ui->PB_SortDown->show();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    Set_LinkList();
}

void MainWindow::Press_GroupAdress()
{
    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->show();
    ui->PB_ManageGroup->show();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    //设置列表
    ui->List_AddressBook->clear();
    for (int i=0; i<addresslinklist.getGroupNum(); i++){
        QString str = addresslinklist.group[i];
        ui->List_AddressBook->addItem(str);
    }
}

void MainWindow::Press_QueryAdress()
{
    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->show();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->show();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    //创建平衡二叉树
    Node_L *p = addresslinklist.getHead();
    p = p->next;

    while (p){
        bool nametaller=false, phonetaller=false;
        addressBTree.insert(addressBTree.getNameRoot(), p->data, nametaller, 1);
        addressBTree.insert(addressBTree.getEmailRoot(), p->data, phonetaller, 2);
        p = p->next;
    }

    Set_LinkList();
}

void MainWindow::Press_TextInfo()
{

}

void MainWindow::Press_DiffHashfun()
{

}

void MainWindow::Press_DiffConflict()
{

}

void MainWindow::Press_OpenAddressBook()
{
    openad->show();
    openad->set_List();
}

void MainWindow::Press_AddMember()
{

    addresslinklist.Add();
    Set_LinkList();
}

void MainWindow::Press_DeleteMember()
{

}

void MainWindow::Press_ChangeMember()
{

}

void MainWindow::Press_CreateGroup()
{
    ui->Input_CreateGroup->clear();
    ui->Input_CreateGroup->show();
    ui->Input_CreateGroup->setPlaceholderText("请在此处输入新分组的名称：");
    ui->List_MemberInGroup->hide();
}

void MainWindow::Input_CreateGroup()
{
    ui->Input_CreateGroup->hide();
    ui->Text_OverallInfo->clear();

    addresslinklist.addGroup(ui->Input_CreateGroup->text());
}

void MainWindow::Press_ManageGroup()
{
    ui->List_MemberInGroup->show();
    ui->Input_CreateGroup->hide();

    ui->Text_OverallInfo->clear();
    ui->Text_OverallInfo->append("该分组内成员：");
}

void MainWindow::Press_MemberInGroup(QListWidgetItem* item)
{
    qDebug() << item->text() << endl;
}

void MainWindow::Press_QueryMember()
{
    //设置查询输入框
    ui->Input_QueryMember->clear();
    ui->Input_QueryMember->show();
    ui->Input_QueryMember->setPlaceholderText("请在输入查询内容：（按姓名查找1-；按邮箱查找2-）");
}

void MainWindow::Input_QueryMember()
{
    //查找输入内容
    ui->Text_MemberInfo->clear();
    ui->Input_QueryMember->hide();

    QString order = ui->Input_QueryMember->text();
    order = order.trimmed();

    qDebug() << order << endl;

    BSTree p=nullptr;
    int cnt;
    if (order[0] == '1')    p = addressBTree.find(addressBTree.getNameRoot(), 1, order.right(order.size()-2), cnt);
    else if (order[0] == '2')    p = addressBTree.find(addressBTree.getEmailRoot(), 0, order.right(order.size()-2), cnt);
    else    return;

    if (p){
        ui->Text_MemberInfo->append("姓名：" + p->data.name);
        ui->Text_MemberInfo->append("电话号码：" + p->data.phone);
        ui->Text_MemberInfo->append("电子邮箱：" + p->data.email);
        ui->Text_MemberInfo->append("地址：" + p->data.address);
        ui->Text_MemberInfo->append("备注：" + p->data.remark);
        ui->Text_MemberInfo->append("分组：" + addresslinklist.group[p->data.groupIndex]);
    }
}

void MainWindow::Press_QueryInfo()
{
    //计算查找信息
    double sum_name=0, sum_email=0;

    Node_L *p=addresslinklist.getHead();
    p = p->next;

    while (p)
    {
        int cnt_name=0, cnt_email=0;
        addressBTree.find(addressBTree.getNameRoot(), 1, p->data.name, cnt_name);
        addressBTree.find(addressBTree.getEmailRoot(), 1, p->data.email, cnt_email);
        sum_name += cnt_name;
        sum_email += cnt_email;
        p = p->next;
    }

    ui->Text_OverallInfo->clear();
    ui->Text_OverallInfo->append("\n用户数：" + QString::number(addresslinklist.getLen()) + "条");
    ui->Text_OverallInfo->append("ASL（平均查找次数）：");
    ui->Text_OverallInfo->append("\n\t\t\t按姓名查找：" + QString::number(sum_name/addresslinklist.getLen()) + "次");
    ui->Text_OverallInfo->append("\n\t\t\t按邮箱查找：" + QString::number(sum_email/addresslinklist.getLen()) + "次");

    qDebug() << sum_name << sum_email << endl;
}
static int type=0,basis=0;
void MainWindow::Press_SortName()
{
    type=1,basis=0;
    addresslinklist.AddressList_sort(type,basis);

    Set_LinkList();

}

void MainWindow::Press_SortPhone()
{
    type=1,basis=1;
    addresslinklist.AddressList_sort(type,basis);
    Set_LinkList();
}

void MainWindow::Press_SortUp()
{
    type=1;
    addresslinklist.AddressList_sort(type,basis);
     Set_LinkList();
}

void MainWindow::Press_SortDown()
{
    type=0;
    addresslinklist.AddressList_sort(type,basis);
    Set_LinkList();
}

void MainWindow::Press_AdressBook(QListWidgetItem* item)
{
    ui->Text_MemberInfo->clear();

    qDebug() << item->text() << endl;
    QStringList strlist=item->text().split("\t");
    if (item->text().contains('@')){    //处理全部界面
        QString str=strlist[1];

        Node_L *p=addresslinklist.getHead();
        p = p->next;
        while (p && p->data.email!=str) p=p->next;

        ui->Text_MemberInfo->append("姓名：" + p->data.name);
        ui->Text_MemberInfo->append("电话号码：" + p->data.phone);
        ui->Text_MemberInfo->append("电子邮箱：" + p->data.email);
        ui->Text_MemberInfo->append("地址：" + p->data.address);
        ui->Text_MemberInfo->append("备注：" + p->data.remark);
        ui->Text_MemberInfo->append("分组：" + addresslinklist.group[p->data.groupIndex]);
    }
    else if (strlist.size() > 1){       //处理分组界面-用户部分

    }
    else {      //处理分组界面-分组部分
        QString groupname=strlist[0];
        ui->Text_MemberInfo->append("分组名称：" + groupname);
    }
}

void MainWindow::Press_AdressFilename(QListWidgetItem* item)
{
    qDebug() << item->text() << endl;

    addresslinklist.init(item->text());

    Set_LinkList();

    openad->hide();
}

void MainWindow::Set_LinkList()
{
    ui->List_AddressBook->clear();

    Node_L *p=addresslinklist.getHead();
    p = p->next;

    while (p)
    {
        QString thistext=p->data.name + "\t" + p->data.email;
        ui->List_AddressBook->addItem(thistext);
        p = p->next;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

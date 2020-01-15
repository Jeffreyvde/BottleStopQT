#include "fillpage.h"
#include "ui_fillpage.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

FillPage::FillPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FillPage)
{
    ui->setupUi(this);

}

FillPage::~FillPage()
{
    delete ui;
}

void FillPage::on_backBtn_clicked()
{
    MainWindow *mainWindow;
    mainWindow->show();
    //this->hide();
}

void FillPage::on_favoriteBtn_clicked()
{
    if (isFavorite){
        QString url = "/user/favorite/delete/" + uid + "/" + bid;
        DeviceManager::getInstance()
                .getApi()->deleteRequestApi("/user/favorite/delete/");

        isFavorite = false;
        changeFavBackground(isFavorite);

        return;
    }

    QJsonObject body;
    body.insert("userId", uid);
    body.insert("beverageId", bid);
    DeviceManager::getInstance().getApi()->postRequestApi("/user/add", body);

    isFavorite = true;
    changeFavBackground(isFavorite);
}

bool FillPage::favoriteStatusCheck(QString uid, QString bid)
{
    QString url = "/user/favorite/" + uid + "/" + bid;

    QJsonObject isFav = DeviceManager::getInstance()
            .getApi()->getRequestApi(url).object();

    qDebug() << uid;

    return isFav.isEmpty();
}

void FillPage::setBeverage(Beverage *value)
{
    beverage = value;
    ui->beverageLbl->setText("PRESS TO FILL "+ beverage->getName());

    uid = QString::number(DeviceManager::getInstance().getActiveUser()->getID());
    bid = QString::number(beverage->getId());

    isFavorite = favoriteStatusCheck(uid, bid);

    changeFavBackground(isFavorite);
    qDebug() << isFavorite;
}

void FillPage::changeFavBackground(bool value)
{
    QPixmap backImg(value ? ":/Images/FillPageImage/FavouriteSelected.png" : ":/Images/FillPageImage/FavouriteNotSelected.png");
    ui->favoriteBtn->setIcon(backImg);
}

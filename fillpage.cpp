#include "fillpage.h"
#include "ui_fillpage.h"

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
    mainWindow->show();
    this->hide();
}

void FillPage::on_favoriteBtn_clicked()
{
    QString uid = QString::number(DeviceManager::getInstance().getActiveUser()->getID());
    QString bid = QString::number(beverage->getId());

    if (favoriteStatusCheck(uid, bid)){
        QString url = "/user/favorite/delete/" + uid + "/" + bid;
        QJsonArray statusCode = DeviceManager::getInstance()
                .getApi()->deleteRequestApi("/user/favorite/delete/").array();

        QPixmap backImg(":/Images/FillPageImage/FavouriteNotSelected.png");
        ui->favoriteBtn->setIcon(backImg);

    } else {
        QJsonObject body;
        body.insert("userId", uid);
        body.insert("beverageId", bid);

        QJsonArray statusCode = DeviceManager::getInstance()
                .getApi()->postRequestApi("/user/add", body).array();

        QPixmap backImg(":/Images/FillPageImage/FavouriteSelected.png");
        ui->favoriteBtn->setIcon(backImg);
    }
}

bool FillPage::favoriteStatusCheck(QString uid, QString bid)
{
    QString url = "/user/favorite/" + uid + "/" + bid;

    QJsonObject isFavorite = DeviceManager::getInstance()
            .getApi()->getRequestApi(url).object();

    return !isFavorite.isEmpty(); // Returns false if the object is empty.
}

void FillPage::setBeverage(Beverage *value)
{
    beverage = value;
    ui->beverageLbl->setText("PRESS TO FILL "+ beverage->getName());
}

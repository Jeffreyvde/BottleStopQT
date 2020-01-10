#ifndef FILLPAGE_H
#define FILLPAGE_H

#include <QDialog>

namespace Ui {
class FillPage;
}

class FillPage : public QDialog
{
    Q_OBJECT

public:
    explicit FillPage(QWidget *parent = nullptr);
    ~FillPage();

private:
    Ui::FillPage *ui;
};

#endif // FILLPAGE_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    void checkMoney();
    void returnCoin(int n);
    int money {0};
    int fivehundredcoin {0};
    int onehundredcoin {0};
    int fiftycoin {0};
    int tencoin {0};


private slots:
    void on_PB_10_clicked();

    void on_PB_50_clicked();

    void on_PB_100_clicked();

    void on_PB_500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbCoke_clicked();

    void on_pbreturnCoin_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

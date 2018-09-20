#ifndef USER_H
#define USER_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // USER_H

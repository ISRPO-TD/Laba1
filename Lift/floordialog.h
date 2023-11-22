#ifndef FLOORDIALOG_H
#define FLOORDIALOG_H

#include <QDialog>

namespace Ui {
class FloorDialog;
}

class FloorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FloorDialog(QWidget *parent = nullptr);
    ~FloorDialog();
    int getFloorNumber();
private:
    Ui::FloorDialog *ui;
};

#endif // FLOORDIALOG_H

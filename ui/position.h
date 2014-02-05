#ifndef POSITION_H
#define POSITION_H

#include <QDialog>

namespace Ui {
class position;
}
class usrAiNode;
class QStringListModel;

class position : public QDialog
{
    Q_OBJECT
public:
    explicit position(usrAiNode *Node, QWidget *parent = 0);
    ~position();
signals:
    void xTransitionChanged(double value, const char *RootName);
    void yTransitionChanged(double value, const char *RootName);
    void zTransitionChanged(double value, const char *RootName);
public slots:
    void setXTransition(double value);
    void setYTransition(double value);
    void setZTransition(double value);
    void modelUpdate();
private slots:
    void on_xPosition_valueChanged(double value){ emit xTransitionChanged(value, qPrintable(globel)); }
    void on_yPosition_valueChanged(double value){ emit yTransitionChanged(value, qPrintable(globel)); }
    void on_zPosition_valueChanged(double value){ emit zTransitionChanged(value, qPrintable(globel)); }
    void on_comboBox_currentIndexChanged(const QString & text) {
        globel = text;
        setXTransition(1.); setYTransition(1.); setZTransition(1.);
    }
private:
    usrAiNode *root;//结点根指针
    QString globel;//on_comboBox_currentIndexChanged 中，局部变量在作用域外释放不用。
    const char * currentRootName;
    QStringListModel *nodeModel;
    Ui::position *ui;
};

#endif // POSITION_H

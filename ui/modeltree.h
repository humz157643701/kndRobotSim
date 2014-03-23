#ifndef MODELTREE_H
#define MODELTREE_H

#include <QDialog>
class QMenu;
class QDialogButtonBox;
class QSettings;
class QTreeWidget;
class QTreeWidgetItem;
class UsrAiNode;
namespace Ui {
class modelTree;
}

class modelTree : public QDialog
{
    Q_OBJECT
    
public:
    explicit modelTree(UsrAiNode *Node, QWidget *parent) ;
    ~modelTree();
signals:
    void sigModelPosition();
    void modelChanged();
public slots:
    void showModelTree(UsrAiNode *Node);
private slots:
    void accept();
    void slotAddChildrenModel();
    void slotHiddenModel();
    void slotShowModel();
    void slotHiddenModelFromNode();
    void slotShowModelFromRoot();

private:
    void addChildModels(UsrAiNode *Node, QTreeWidgetItem *parent);
    void contextMenuEvent(QContextMenuEvent * event);
    void creatModelTreeActions();

    QString organization;
    QString application;
    Ui::modelTree *ui;
    QMenu *qMenu;
    QAction* AddChildrenModel;
    QAction* ModelPosition;
    QAction* HiddenModel;
    QAction* HiddenModelFromNode;
    QAction* ShowModel;
    QAction* ShowModelFromRoot;
    UsrAiNode *NodeFromOut;//结点指针
    QTreeWidgetItem *curItem;//鼠标右键时指定的item
};


#endif // MODELTREE_H

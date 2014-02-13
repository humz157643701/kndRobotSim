#ifndef USRAINODE_H
#define USRAINODE_H
//#include"assimp/scene.h" 使用新的数据结构 Matrix4。
#include "Matrices.h"
#include<list>
class UsrAiNode
{
public:
    enum NodeType { AXIS, MODULE };
    UsrAiNode() { // set all members to zero by default
        mParent = NULL;
        mName = NULL; fileName = NULL; ishidden = false; nodeType = MODULE;
        mTransformation.identity();//init with identity
    }

    /** Construction from a specific name */
    UsrAiNode(NodeType type, const char *name) { // set all members to zero by default
        mParent = NULL;
        mName = name;
        fileName = NULL; ishidden = false; nodeType = type;
        mTransformation.identity();//init with identity
    }

    ~UsrAiNode();

    inline void setFileName(char * file_Name) {
        fileName = file_Name;
    }
    inline const char * getmName() { return mName;}
    inline std::list<UsrAiNode *> getChildrenList() {return childrenList;}

    void addNodeToTree(const char *inobjname, UsrAiNode* Node);
    void addShowListToNode(const char *inobjname,int addlist);
    void addNodeFileToNode(const char *inobjname,const char *addlist);
    void delNodeFromTree(const char *objname, UsrAiNode* Node);
    void rmShowList(const char *objname, int showlist);
    void callShowList(NodeType type = MODULE);
    void setTranslationMatrix(const char *objname, const Matrix4& m);
    void printAllNode();
    void setHidden(bool hiddenflag) { ishidden = hiddenflag;}
    bool getHidden() { return ishidden = 0;}
    UsrAiNode* FindNode(const char* name);//可以私有化。
public:
    void setXTransition(float xposition) { mTransformation.setPositionX(xposition); }
    void setYTransition(float yposition) { mTransformation.setPositionY(yposition); }
    void setZTransition(float zposition) { mTransformation.setPositionZ(zposition); }
    void translateXYZ(const char *inobjname, float xposition, float yposition, float zposition);

    float getXPosition(){ return mTransformation.getPositionX(); }
    float getYPosition(){ return mTransformation.getPositionY(); }
    float getZPosition(){ return mTransformation.getPositionZ(); }
    void setRotation(double angle, float x, float y, float z) { return mTransformation.setRotation(angle,x,y,z);}

    void setXRotation(int angle) { mTransformation.rotateX(angle); }
    void setYRotation(int angle) { mTransformation.rotateY(angle); }
    void setZRotation(int angle) { mTransformation.rotateZ(angle); }

protected:
    Matrix4 mTransformation;
private:
    void setXYZTransition(float xposition, float yposition, float zposition);

    UsrAiNode* mParent; //父结点
    std::list<UsrAiNode *> childrenList; //字结点
    NodeType nodeType;//结点类型

    const char *fileName;//
    const char *mName;//结点名字
    bool ishidden; //true表示隐藏，false显示

    std::list<unsigned int*> meshList;
    std::list<int> showList;//结点下挂的显示列表
};

#endif // USRAINODE_H


#if 0
class usrAiNode
{
public:
    /** Constructor */
    usrAiNode()
    {
        // set all members to zero by default
        mParent = NULL;
        mNumChildren = 0; mChildren = NULL;
        mNumMeshes = 0; mMeshes = NULL;
    }

    /** Construction from a specific name */
    usrAiNode(const std::string& name)
    {
        // set all members to zero by default
        mParent = NULL;
        mNumChildren = 0; mChildren = NULL;
        mNumMeshes = 0; mMeshes = NULL;
        mName = name;
    }

    /** Destructor */
    ~usrAiNode()
    {
        // delete all children recursively
        // to make sure we won't crash if the data is invalid ...
        if (mChildren && mNumChildren)
        {
            for( unsigned int a = 0; a < mNumChildren; a++)
                delete mChildren[a];
        }
        delete [] mChildren;
        delete [] mMeshes;
    }

    /** Searches for a node with a specific name, beginning at this
     *  nodes. Normally you will call this method on the root node
     *  of the scene.
     *
     *  @param name Name to search for
     *  @return NULL or a valid Node if the search was successful.
     */
    inline usrAiNode* FindNode(const aiString& name)
    {
        return FindNode(name.data);
    }

    /** @override
     */
    inline usrAiNode* FindNode(const char* name)
    {
        if (!::strcmp( mName.data,name))return this;
        for (unsigned int i = 0; i < mNumChildren;++i)
        {
            usrAiNode* p = mChildren[i]->FindNode(name);
            if (p)return p;
        }
        // there is definitely no sub node with this name
        return NULL;
    }
    void addNodetoTree(const std::string &objname, usrAiNode *Node);
    void addShowList(int showList);
    void callShowList();
private:
    aiString mName;
    aiMatrix4x4 mTransformation;
    usrAiNode* mParent;
    unsigned int mNumChildren;
    usrAiNode** mChildren;
    unsigned int mNumMeshes;
    unsigned int* mMeshes;
    std::list<int> showList;
};

class usrAiNode : public aiNode
{
public:
    usrAiNode():aiNode(){}
    usrAiNode(const std::string& name):aiNode(name){}
    ~usrAiNode();
    void addNodeToTree(const std::string& inobjname, usrAiNode* Node);
    void addShowListToNode(const std::string& inobjname,int addlist);
    void printShowListsFromNode();
    void delNodeFromTree(const std::string& inobjname, usrAiNode* Node);
    void delNodeReclusive(usrAiNode* Node);
    void delShowList(int showlist);
    void callShowList();
    void setTranslationMatrix(const std::string& inobjname, const aiMatrix4x4& m);

private:

    std::list<int> showList;
};
#endif

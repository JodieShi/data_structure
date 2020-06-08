const int defaultSize=100;
template<class E,class K>
struct ChainNode{ //各桶中同义词子表的链接点定义
    E data;  //元素
    ChainNode<E,K> *link;  //链指针
};
template<class E,class K>
class HashTable{ //散列表(表头指针向量)定义
public:
    HashTable(int d,int sz=defaultSize);  //散列表的构造函数
    ~HashTable(){delete []ht}  //析构函数
    bool Search(const K k1,E&e1);  //搜索
    bool Insert(const E&e1);  //插入
    bool Remove(const K k1,E&e1);  //删除
private:
    int divisor;  //除数(必须是质数)	
    int TableSize;  //容量(桶的个数)
    ChainNode<E,K>**ht;  //散列表定义
    ChainNode<E,K>*FindPos(const K k1);   //散列
};

template<class E,class K>
HashTable<E,K>::HashTable(int d,int sz){  //构造函数
    divisor=d; TableSize=sz;
    ht=new ChainNode<E,K>*[sz];  //创建头节点
    assert(ht!=NULL);  //断言：判断存储分配是否成功
};
template<class E,class K>
ChainNode<E,K>*HashTable<E,K>::FindPos(const K& k1){
//在散列表ht中搜索关键码为k1的元素。函数返回一个指向散列表中某位置的指针；若元素不存在，则返回NULL.
    int j=k1%divisor;  //计算散列地址
    ChainNode<E,K> *p=ht[j];  //扫描第j链的同义词子表
    while (p!=NULL&&p->data!=k1) p=p->link;
    return p;  //返回
}; 

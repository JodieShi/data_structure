class List;            //复合类定义

 class ListNode {        //链表结点类
 friend class List;        //链表类为其友元类
 private:
     int data;        //结点数据, 整型
     ListNode *link;        //结点指针
 };

 class List {                  //链表类
 public:
      //链表公共操作
 private:
     ListNode *first, *last;    //表头和表尾指针
 };
int List::Insert ( const int x, const int i ) {
//在链表第i个结点处插入新元素x
    ListNode *p = first;  int k = 0;
    while ( p != NULL && k< i -1 ) 
         { p = p→link;  k++; }   //找第i-1个结点 
    if ( p == NULL && first != NULL ) {
        cout << “Invalid position for
                 Insertation!\n”;  return 0;
    }
     ListNode *newnode= new ListNode(x);
     //创建新结点,其数据为x,指针为0
      if ( first == NULL || i == 0 ) {  //插在表前
         newnode→link = first;
         if ( first == NULL ) last = newnode;
         first = newnode;
      }
      else {                       //插在表中或末尾
         newnode→link = p→link;
         if ( p→link == NULL ) last = newnode;
         p→link = newnode;
      }
      return 1;
 }
int List::Remove ( int i, int &x) {
//在链表中删除第i个结点
    ListNode *p = first, *q;  int k = 0;
    while ( p != NULL && k< i-1 )
       { p = p→link;  k++; }    //找第i-1个结点
    if ( p == NULL ) {
       cout << “Invalid position for Deletion!\n”;
       return false;
    }    
    if ( i == 0 ) {             //删除表中第1个结点
        q = first;               //q保存被删结点地址
        p = first = first→link;      //修改first  
    } 
    else {                        //删除表中或表尾元素
       q = p→link;  
       p→link = q→link;            //重新链接
    }
    if ( q == last ) last = p; //可能修改last
    x = q→data;   delete q;       //删除q
    return true;
}

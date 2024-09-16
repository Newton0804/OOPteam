#include<iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


/************************һ����һ����**********************************/
// Data�ṹ�壬������ײ�����ݣ���ɫ+��Ӧ��ԭʯ����
struct Data
{
    string name;
    int stones;
};

// Node���󣬰�����Data����һ��ָ��
class Node
{
    private:
        Data data;
        Node *next;
    
    public:
        Node(const Data &data):data(data),next(NULL){};    
        friend class Hero;    
};

// Hero���󣬳������������ࡣ
class Hero
{
    private:
        Node *head;
        int num;
    
    public:
        //1. ��������
        Hero(int n,const Data *datas):head(NULL),num(0){
            num=n;
            for(size_t i=0;i<n;i++){
                Node *temp=new Node(datas[i]);
                temp->next=head;
                head=temp;
            }
        }

        //2. �������
        void showList(){
            cout<<"���˺�ӵ�еĽ�ɫ�Լ������ĵ�ԭʯΪ��"<<endl;
            cout<<"----------------------"<<endl;
            for(Node *p=head;p!=NULL;p=p->next){
                cout<<p->data.name<<" --> "<<p->data.stones<<endl;
                cout<<"   "<<"|"<<endl;
                cout<<"   "<<"|"<<endl;
            }
            cout<<"  "<<"NULL"<<endl;
            cout<<"----------------------"<<endl;
            cout<<endl;
        }

        //3. �������
        void freeList(){
            cout<<"�����Ѿ�ȫ����ա�"<<endl;
            while(head!=NULL){
                Node *temp=head;
                head=head->next;
                delete temp;
            }
            cout<<endl;
        }

        //4. ������
        void append(const Data &data){
            Node *_new=new Node(data);
            num++;
            _new->next=head;
            head=_new;
        }
        
        //5. ��ѯ�Ƿ���ĳ����ɫ
        bool find(const string & name){
            for(Node *temp=head;temp!=NULL;temp=temp->next){
                if(temp->data.name==name){
                    cout<<"���Ѿ�ӵ�н�ɫ��"<<name<<"����ȡ�˽�ɫ����ԭʯ "<<temp->data.stones<<endl;
                    return true;
                }
            }
            cout<<"����δӵ�д˽�ɫ"<<endl;
            return false;
        }

        //6. ������ǽ�ɫ�ĸ���
        int heronums()const{
            cout<<"��ӵ�����ǽ�ɫ�ĸ���Ϊ��"<<num<<endl;
            return num;
        }
};


/************************************�����ڶ�����********************* */
int main(){
    // ����Data����
    Data datas[]{
        {"��ά����",70},
        {"����",143},
        {"ܽ����",2},
    };
    int n=sizeof(datas)/sizeof(*datas);

    Hero hero1(n,datas);
    hero1.showList();

    //append�ĵ���
    /*
    string name;
    cin>>name;
    int stone;
    cin>>stone;
    Data data{name,stone};
    hero1.append(data);
    hero1.showList();
    */
    hero1.heronums();
    //find�ĵ���
    hero1.find("����");
    
    return 0;
}
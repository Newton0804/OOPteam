#include<iostream>

template<class T>
class Vector{
    protected:
    //size����������С
        size_t size;

    //data��������
        T *data;

    public:
    /******************���캯������д���鹹����**********/
    //1.��ʼ�����캯��
        Vector(size_t size):size(size),data(new T[size]){}

    //2. ���������캯��
        Vector(size_t size,const T *arr):size(size),data(new T[size]){
            std::copy(arr,arr+size,data);
        }

/*
    //2. �ƶ����캯��
        Vector(Vector && other)noexcept:size(other.size),data(other.data){
            /*Ҫ��otherȫ����� ���other����ʱ���ԭ�������������*/
/*
            other.size=0;
            other.data=nullptr;
        }
*/

    //3. ����������
        virtual ~Vector(){
            //std::cout<<"�����˻���Ĵ��麯��"<<std::endl;
            delete []data;
        }

    //4. ���ƶ���ֵ�����
        virtual Vector& operator=(Vector && other){
            if(size!=other.getSize()){
                throw "ά�Ȳ�ͬ�����޷���ֵ";
            }
            delete[]data;
            size=other.size;
            data=other.data;
            other.size=0;
            other.data=nullptr;
            return *this;
        }

    //5. �������������+
        virtual Vector<T>& operator+(const Vector<T> & other)=0;
        //�õ�size
        size_t getSize()const{
            return size;
        }

    //6. ���麯��set: ����ĳ��������Ԫ��
        //�������޾ͱ���
        virtual void set(size_t index,const T & value)=0;

    //7. ���麯��get���õ�ĳ��������Ԫ��
        virtual T get(size_t index)const=0;

    //8. �麯��display��չʾ����
        virtual void display()const{
            for(size_t i=0;i<size;++i){
                std::cout<<data[i]<<" ";
            }
            std::cout<<std::endl;
        }

};

template<class T>
class DerivedVector:public Vector<T>{
    public:
        DerivedVector(size_t size, const T *arr) : Vector<T>(size, arr) {}
        //ʵ���麯��
        void set(size_t index,const T & value)override{
            if(index>=this->size){
                throw "�������ޣ������ò��ˣ�";
            }
            else{
                this->data[index]=value;
            }
        }

        T get(size_t index)const override{
            if(index>=this->size){
                throw "�������ޣ���û�����ݣ�";
            }
            return this->data[index];
        }

        DerivedVector<T>& operator+(const Vector<T> & other) override{
            if(this->size!=other.getSize()){
                throw "ά�Ȳ�һ���������������";
            }
            for(size_t i=0;i<other.getSize();++i){
                this->data[i]+=other.get(i);
            }
            return *this;
            //return DerivedVector()
        }
};

//�ַ������Ѿ����ַ�����
class String:public Vector<std::string>{
    public:
        String(size_t size, const std::string *arr) : Vector<std::string>(size, arr) {}
        void set(size_t index,const std::string & value)override{
            if(index>=this->size){
                throw "�������ޣ����������ã�";
            }
            this->data[index]=value;
        }
        std::string get(size_t index)const override{
            if(index>=this->size){
                throw "�������ޣ���û�����ݣ�";
            }
            return this->data[index];
        }

        String & operator+(const Vector<std::string>& other)override{
            size_t newsize=this->size+other.getSize();
            std::string* newdata=new std::string[newsize];

            for(size_t i=0;i<this->size;++i){
                newdata[i]=this->data[i];
            }
            for(size_t i=0;i<other.getSize();++i){
                newdata[i+this->size]=other.get(i);
            }
            this->size=newsize;
            this->data=newdata;
            return *this;
            /*
            //String* result = new String(this->size + other.getSize());
            delete this->data;
            //size_t s=this->size;
            this->size=this->size+other.getSize();
            this->data=new std::string[this->size];
            for(size_t i=0;i<this->size;++i){

            }
            */
            
        }
};
void menu1();
void menu2();
void menu3();
int main(){
    menu1();
    return 0;
}
void menu1(){
    
    //�˵�1
    while (true){
        std::cout<<std::endl<<std::endl;
    std::cout<<"***************������ʾ*************"<<std::endl;
    std::cout<<"*****1.������ʾ*******"<<std::endl;
    std::cout<<"*****2.�ַ�����ʾ*****"<<std::endl;
    std::cout<<"===================================="<<std::endl;
    std::cout<<"*******���������(��0�˳�): ";
    int judge;
    std::cin>>judge;
    if(judge==0){
        break;
    }
    if(judge==1){
        menu2();
        continue;
    }
    if(judge==2){
        menu3();
        continue;
    }
    }
}

void menu2(){
    /*
    int arr1[3]{10,20,30};
    int arr2[3]{20,30,40};
    int arr3[4]{10,20,30,40};
    DerivedVector<int> vec1(3,arr1);    
    DerivedVector<int> vec3(4,arr3);
    DerivedVector<int> vec2(3,arr2);
    */
    while(true){
        int arr1[3]{10,20,30};
        int arr2[3]{20,30,40};
        int arr3[4]{10,20,30,40};
        DerivedVector<int> vec1(3,arr1);    
        DerivedVector<int> vec3(4,arr3);
        DerivedVector<int> vec2(3,arr2);
        std::cout<<std::endl<<std::endl;
        std::cout<<"~~˵�������˵��ǲ�������������ģ��~~"<<std::endl;
        std::cout<<"~~���������У�~~"<<std::endl;
       // DerivedVector<int> vec1(3,arr1);
        std::cout<<"��������1��3ά������: ";
        vec1.display();
       // DerivedVector<int> vec2(3,arr2);
        std::cout<<"��������2��3ά������: ";
        vec2.display();
       // DerivedVector<int> vec3(4,arr3);
        std::cout<<"��������3��4ά������: ";
        vec3.display();
        std::cout<<"**********����������������ʾ**********"<<std::endl;
        std::cout<<"*****1.�������=��������ʾ*******"<<std::endl;
        std::cout<<"*****2.�������+��������ʾ*******"<<std::endl;
        std::cout<<"*****3.������get��������ʾ*******"<<std::endl;
        std::cout<<"*****4.������set��������ʾ*******"<<std::endl;
        std::cout<<"*****5.�������=���쳣����������ʾ"<<std::endl;
        std::cout<<"*****6.�������+���쳣����������ʾ"<<std::endl;
        std::cout<<"*****7.������get���쳣����������ʾ"<<std::endl;
        std::cout<<"*****8.������set���쳣����������ʾ"<<std::endl;
        std::cout<<"===================================="<<std::endl;
        std::cout<<"*******���������(��0�˳�): ";
        int judge;
        std::cin>>judge;        
        if(judge==0){
            break;
        }
        if(judge==1){
            //std::cout<<"����"<<std::endl;
            std::cout<<std::endl<<"������и�ֵ�����=�Ĳ���"<<std::endl;
            try{
                std::cout<<"����������2��ֵ����������1"<<std::endl;
                vec1=std::move(vec2);
                std::cout<<"�����������1"<<std::endl;
                vec1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
        if(judge==2){
            std::cout<<std::endl<<"������и�ֵ�����+�Ĳ���"<<std::endl;
            try{
                std::cout<<"����������2���������1���"<<std::endl;
                int result_arr[3]{0,0,0};
                DerivedVector<int> result(3,result_arr);
                result=std::move(vec1+vec2);
                std::cout<<"�����Ӻ������"<<std::endl;
                result.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
        if(judge==3){
            std::cout<<std::endl<<"������к���get�Ĳ���"<<std::endl;
            std::cout<<"����getʵ�ֵĹ�����������������ֵ��"<<std::endl;
            std::cout<<"������������3���õ�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1�з�������Ϊ2������:"<<std::endl;
                std::cout<<vec1.get(2)<<std::endl;
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
        if(judge==4){
            std::cout<<std::endl<<"������к���set�Ĳ���"<<std::endl;
            std::cout<<"����setʵ�ֵĹ��������������޸�ֵ��"<<std::endl;
            std::cout<<"������������3���޸�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1���޸�����Ϊ2������Ϊ1:"<<std::endl;
                vec1.set(2,1);
                vec1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
        if(judge==5){
            std::cout<<std::endl<<"������и�ֵ�����=���쳣����"<<std::endl;
            try{
                std::cout<<"����������3��ֵ����������1"<<std::endl;
                vec1=std::move(vec3);
                std::cout<<"�����������1"<<std::endl;
                vec1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
        if(judge==6){
            std::cout<<std::endl<<"������и�ֵ�����+�쳣�Ĳ���"<<std::endl;
            try{
                std::cout<<"����������3���������1���"<<std::endl;
                int result_arr[3]{0,0,0};
                DerivedVector<int> result(3,result_arr);
                result=std::move(vec1+vec3);
                std::cout<<"�����Ӻ������"<<std::endl;
                result.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
        }
        if(judge==7){
            std::cout<<std::endl<<"������к���get���쳣����"<<std::endl;
            std::cout<<"����getʵ�ֵĹ�����������������ֵ��"<<std::endl;
            std::cout<<"������������3���õ�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1�з�������Ϊ3������:"<<std::endl;
                std::cout<<vec1.get(3)<<std::endl;
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
        if(judge==8){
            std::cout<<std::endl<<"������к���set���쳣����"<<std::endl;
            std::cout<<"����setʵ�ֵĹ��������������޸�ֵ��"<<std::endl;
            std::cout<<"������������3���޸�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1���޸�����Ϊ3������Ϊ1:"<<std::endl;
                vec1.set(3,1);
                vec1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
    }
}

void menu3(){
 std::string arr1[5]{"h","e","l","l","0"};
    std::string arr2[5]{"w","o","r","l","d"};
    std::string arr3[3]{"C","+","+"};
    while (true){
        String str1(5,arr1);
        String str2(5,arr2);
        String str3(3,arr3);
        std::cout<<std::endl<<std::endl;
        std::cout<<"~~˵�������˵��ǲ����������ַ���~~"<<std::endl;
        std::cout<<"~~���������У�~~"<<std::endl;
        std::cout<<"��������1��hello��: ";
        str1.display();
        std::cout<<"��������2��world��: ";
        str2.display();
        std::cout<<"��������3��C++��: ";
        str3.display();
        std::cout<<"**********�����ַ�����������ʾ**********"<<std::endl;
        std::cout<<"*****1.�������=��������ʾ*******"<<std::endl;
        std::cout<<"*****2.�������+��������ʾ*******"<<std::endl;
        std::cout<<"*****3.������get��������ʾ*******"<<std::endl;
        std::cout<<"*****4.������set��������ʾ*******"<<std::endl;
        std::cout<<"*****5.�������=���쳣����������ʾ"<<std::endl;
        //std::cout<<"*****6.�������+���쳣����������ʾ"<<std::endl;
        std::cout<<"*****6.������get���쳣����������ʾ"<<std::endl;
        std::cout<<"*****7.������set���쳣����������ʾ"<<std::endl;
        std::cout<<"===================================="<<std::endl;
        std::cout<<"*******���������(��0�˳�): ";
        int judge;
        std::cin>>judge;        
        if(judge==0){
            break;
        }
        if(judge==1){
            std::cout<<std::endl<<"������и�ֵ�����=�Ĳ���"<<std::endl;
            try{
                std::cout<<"����������2��ֵ����������1"<<std::endl;
                str1=std::move(str2);
                std::cout<<"�����������1"<<std::endl;
                str1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
        if(judge==2){
            std::cout<<std::endl<<"������и�ֵ�����+�Ĳ���"<<std::endl;
                std::cout<<"����������2���������1���"<<std::endl;
                std::string result_arr[10]{};
                String result(10,result_arr);
                result=std::move(str1+str2);
                std::cout<<"�����Ӻ���ַ���"<<std::endl;
                result.display();
            continue;
        }
         if(judge==3){
            std::cout<<std::endl<<"������к���get�Ĳ���"<<std::endl;
            std::cout<<"����getʵ�ֵĹ�����������������ֵ��"<<std::endl;
            std::cout<<"������������3���õ�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1�з�������Ϊ2������:"<<std::endl;
                std::cout<<str1.get(2)<<std::endl;
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
         if(judge==4){
            std::cout<<std::endl<<"������к���set�Ĳ���"<<std::endl;
            std::cout<<"����setʵ�ֵĹ��������������޸�ֵ��"<<std::endl;
            std::cout<<"������������3���޸�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1���޸�����Ϊ2������ΪX:"<<std::endl;
                str1.set(2,"X");
                str1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
         if(judge==5){
            std::cout<<std::endl<<"������и�ֵ�����=�쳣�Ĳ���"<<std::endl;
            try{
                std::cout<<"����������1��ֵ����������3"<<std::endl;
                str3=std::move(str1);
                std::cout<<"�����������1"<<std::endl;
                str1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        
        }
         if(judge==6){
            std::cout<<std::endl<<"������к���get�쳣�Ĳ���"<<std::endl;
            std::cout<<"����getʵ�ֵĹ�����������������ֵ��"<<std::endl;
            std::cout<<"������������3���õ�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1�з�������Ϊ5������:"<<std::endl;
                std::cout<<str1.get(5)<<std::endl;
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
         if(judge==7){
            std::cout<<std::endl<<"������к���set�Ĳ���"<<std::endl;
            std::cout<<"����setʵ�ֵĹ��������������޸�ֵ��"<<std::endl;
            std::cout<<"������������3���޸�����a[3]"<<std::endl;
            try{
                std::cout<<"�ڲ�������1���޸�����Ϊ5������ΪX:"<<std::endl;
                str1.set(5,"X");
                str1.display();
            }catch(const char*e){
                std::cerr<<e<<std::endl;
            }
            continue;
        }
    }
}
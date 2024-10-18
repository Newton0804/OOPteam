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
            std::cout<<"�����˻���Ĵ��麯��"<<std::endl;
            delete []data;
        }

    //4. ���ƶ���ֵ�����
        virtual Vector& operator=(Vector && other){
            delete[]data;
            size=other.size;
            data=other.data;
            other.size=0;
            other.data=nullptr;
        }

    //5. �������������+
        /*virtual Vector<T> operator+(const Vector<T> & other)=0;*/

    //6. ���麯��set: ����ĳ��������Ԫ��
        //�������޾ͱ���
        virtual void set(size_t index,const T & value)=0;

    //7. ���麯��get���õ�ĳ��������Ԫ��
        virtual T get(size_t index)const=0;

    //8. �麯��display��չʾ����
        virtual void display()const{
            for(size_t i=0;i<size;++i){
                std::cout<<data[i]<<",";
            }
            std::cout<<std::endl;
        }

};

template<class T>
class DerivedVector:public Vector<T>{
    public:
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
    /*
        DerivedVector<T> operator+(const Vector<T> & other)const override{
            return 
        }
    */
};

//�ַ������Ѿ����ַ�����
class String:public Vector<std::string>{
    public:
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
};
int main(){
    std::cout<<0<<std::endl;
    return 0;
}
// main.cpp
#include "Accout.h"

//���Ժ�������ʼ������������
Accout create(){
    //�ڶ��������һ��
    Data datas1[]{
        {"��ά����", 70},
        {"����", 143},
        {"ܽ����", 2},
    };
    int n = sizeof(datas1) / sizeof(*datas1);
    Hero hero1(n,datas1);

    //�ڶ�������ڶ���
    Data datas2[]{
        {"��ά����", 122},
        {"������ŵ", 89},
        {"��ά�", 72},
        {"�����",36},
        {"������",110}
    };
    n = sizeof(datas2) / sizeof(*datas2);
    Hero hero2(n,datas2);

    //�ڶ������������
    Data datas3[]{
        {"ܽ����", 12},
        {"ҹ��", 66},
        {"����", 119},
        {"����",88},
        {"��ԭ��Ҷ",36},
        {"������",155}
    };
    n = sizeof(datas3) / sizeof(*datas3);
    Hero hero3(n,datas3);

    //�ڶ���������ĸ�
        Data datas4[]{
        {"ܽ����", 22},
        {"�����", 55},
        {"����", 136},
        {"����",133},
    };
    n = sizeof(datas4) / sizeof(*datas4);
    Hero hero4(n,datas4); 

//��һ������
    AccoutData datas[]{
        {hero1,196026632},
        {hero2,304929684},
        {hero3,225318414},
        //{hero3,197567333},
        {hero4,167033637}
    };
    n=sizeof(datas)/sizeof(*datas);
    Accout accout(datas,n);
    return accout;
}

int main() {
//9.17
    Accout accout=create();
    accout.showAccoutList();
    return 0;
//9.15
    // ����Data����
    /*
    Data datas[] = {
        {"��ά����", 70},
        {"����", 143},
        {"ܽ����", 2},
    };
    int n = sizeof(datas) / sizeof(*datas);


    Hero hero1(n, datas);
    hero1.showList();
    */
    // append�ĵ���
    /*
    string name;
    cin >> name;
    int stone;
    cin >> stone;
    Data data{name, stone};
    hero1.append(data);
    hero1.showList();
    */
   /*
    hero1.heronums();
    // find�ĵ���
    hero1.find("����");
    */

}
//T_PLAN�Ľ��������ϣ������Ƶ���ر���л��thanks
//����˼·��string��ȡ���벢��ȡ�ַ�����->���intΪstring���char��һ���ţ���Ϊstring��char���鷳�����ȱ�int�ٱ�char��->���char�Ի�ȡascii��
//������ʱ���� d( ^ W ^ )/ ===
#include <windows.h>
#include <iostream>
#include <string>//���а���.length()
#define KEYDOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
int main(){
	cout<<"ˢ��;�У�����Esc���˳������ⲻ��Ҫ������"<<endl;
	int a,b;
	string c;//��Ϊstring��
	cout<<"������Ҫˢ���ļ���������Ժ�����㣬1000����=1���ӣ�:";
	cin>>a;
if_return:
	cout<<"��������Ҫˢ�������֣�1�����֣�:";
	cin>>c;
	if(c.length()>=2){//�� ������.length() ��ʽ��ȡ����
		cout<<"���ܳ�����λ����"<<endl;
		Sleep(1000);
		system("cls");
		goto if_return;
	}
	b = atoi(c.c_str());//��string�����cת����intֵ
	char ascii = b + '0';//��Խ�罫int�����bת����char��
	cout<<"��ȴ�3��..."<<endl;
	cout<<"3"<<endl;
	Sleep(1000);
	cout<<"2"<<endl;
	Sleep(1000);
	cout<<"1"<<endl;
	Sleep(1000);
	cout<<"��ʼ"<<endl;
	while(1){
	    keybd_event(static_cast<int>(ascii),0, 0 ,0);//static_cast<int>(char�����)���Ի�ȡascii��
        keybd_event(VK_RETURN,0,0,0);
        keybd_event(static_cast<int>(ascii),0, KEYEVENTF_KEYUP,0);
        keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);
        Sleep(a);
        if(KEYDOWN(VK_ESCAPE)){
    	    exit(0);
	    }
    }
}
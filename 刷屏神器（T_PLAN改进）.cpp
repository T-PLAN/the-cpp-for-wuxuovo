//T_PLAN改进，如采纳希望在视频中特别鸣谢，thanks
//总体思路：string获取输入并获取字符长度->变成int为string变成char搭一座桥（因为string变char很麻烦所以先变int再变char）->变成char以获取ascii码
//不懂随时问我 d( ^ W ^ )/ ===
#include <windows.h>
#include <iostream>
#include <string>//其中包含.length()
#define KEYDOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
int main(){
	cout<<"刷屏途中，请点击Esc键退出，避免不必要的意外"<<endl;
	int a,b;
	string c;//改为string类
	cout<<"输入你要刷屏的间隔秒数（以毫秒计算，1000毫秒=1秒钟）:";
	cin>>a;
if_return:
	cout<<"请输入你要刷屏的数字（1个数字）:";
	cin>>c;
	if(c.length()>=2){//用 变量名.length() 格式获取长度
		cout<<"不能超过两位数！"<<endl;
		Sleep(1000);
		system("cls");
		goto if_return;
	}
	b = atoi(c.c_str());//将string类变量c转换成int值
	char ascii = b + '0';//不越界将int类变量b转换成char类
	cout<<"请等待3秒..."<<endl;
	cout<<"3"<<endl;
	Sleep(1000);
	cout<<"2"<<endl;
	Sleep(1000);
	cout<<"1"<<endl;
	Sleep(1000);
	cout<<"开始"<<endl;
	while(1){
	    keybd_event(static_cast<int>(ascii),0, 0 ,0);//static_cast<int>(char类变量)可以获取ascii码
        keybd_event(VK_RETURN,0,0,0);
        keybd_event(static_cast<int>(ascii),0, KEYEVENTF_KEYUP,0);
        keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);
        Sleep(a);
        if(KEYDOWN(VK_ESCAPE)){
    	    exit(0);
	    }
    }
}
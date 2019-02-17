#include"gtest\gtest.h"
#include "sting.h"
#include<sstream>
#include<vector>
#include<string>
#include<cstring>
#jsjsjsjjsjjjjs
TEST(testCase0,Squarebracketsandconstructors){
	Sting a="123",b;	
EXPECT_EQ('1',a[0]);
EXPECT_EQ('2',a[1]);
EXPECT_EQ('3',a[2]);
}
TEST(testCase1,Cin){
	stringstream test;
	streambuf *cinbuff=cin.rdbuf();
	cin.rdbuf(test.rdbuf());
	test<<"HELLO\n";
	Sting a;
	cin>>a;
	cin.rdbuf(cinbuff);
	EXPECT_EQ('H',a[0]);
	EXPECT_EQ('E',a[1]);
	EXPECT_EQ('L',a[2]);
	EXPECT_EQ('L',a[3]);
	EXPECT_EQ('O',a[4]);
}
TEST(testCase2,getsize){
	Sting a="12345",b,c="123";
	EXPECT_EQ(5,a.getsize());
	EXPECT_EQ(0,b.getsize());
	EXPECT_EQ(3,c.getsize());
}
TEST(testCase3,assignment){
Sting a="HELLO",b;
	b=a;
	EXPECT_EQ(a[0],b[0]);
	EXPECT_EQ(a[1],b[1]);
	EXPECT_EQ(a[2],b[2]);
	EXPECT_EQ(a[3],b[3]);
	EXPECT_EQ(a[4],b[4]);
	EXPECT_EQ(a.getsize(),b.getsize());

}
TEST(testCase4,equality){
Sting a="HELLO",b,c="HOWLOW";
a=b;
EXPECT_EQ(true,a==b);
EXPECT_EQ(false,a==c);
//actually the same :D
EXPECT_EQ(a,b);
}
TEST(testCase5,Insert){
Sting a="YOU SHALL PASS";
a.insert(10,'N');
a.insert(11,'O');
a.insert(12,'T');
a.insert(13,' ');
EXPECT_EQ('N',a[10]);
EXPECT_EQ('O',a[11]);
EXPECT_EQ('T',a[12]);
EXPECT_EQ(' ',a[13]);
}
TEST(testCase6,remove){
Sting a="YOU SHALL NOT PASS";
Sting b="YOU SHALL PASS";
a.remove(10);
a.remove(10);
a.remove(10);
a.remove(10);
EXPECT_EQ(true,a==b);
}
TEST(testCase7,clear){
Sting a="YOU SHALL NOT PASS";
Sting b;
a.clear();
EXPECT_EQ(true,a==b);
}
TEST(testCase8,cout){
Sting a="YOU SHALL NOT PASS";
stringstream test;
streambuf *coutbuff = cout.rdbuf();
cout.rdbuf(test.rdbuf());
cout<<a;
cout.rdbuf(coutbuff);
EXPECT_EQ("YOU SHALL NOT PASS",test.str());
}
TEST(testCase9,substring){
Sting a="Hiding in plain sight",b,c="Hiding";
b=a.substring(0,6);
EXPECT_EQ(true,c==b);
}
TEST(testCase10,concatenateoperator){
Sting a="YOU SHALL NOT PASS",b="YOU SHALL NOT ",c="PASS";
Sting f=b+c;
EXPECT_EQ(a,f);
}
TEST(testCase11,searching1){
Sting a="YOU SHALL NOT PASS",n="SHALL";
int pos=a.islocated(n);
EXPECT_EQ(4,pos);
EXPECT_EQ(-1,a.islocated(n+n));
}
TEST(testCase12,patternmatch){
Sting a="YOU SHALL NOT PASS",b="[a-A][a-A][TXUU]";
vector<Sting> v=a.patternmatch(b);
EXPECT_EQ(2,v.size());
}
TEST(testCase13,cppstring_1){
string t;
Sting v="The testing word";
v.stdstring(t);
EXPECT_EQ("The testing word",t);
}
TEST(testCase14,cppstring_2){
string t;
Sting v="The testing word";
t=v.stdstring();
EXPECT_EQ("The testing word",t);
}
TEST(testCase15,cppstring_1){
char a[30];
Sting v="The testing word";
v.cstring(a);
EXPECT_EQ(0,strcmp(a,"The testing word"));
}
TEST(testCase16,cstring_2){
char *a;
Sting v="The testing word";
a=const_cast<char *>(v.cstring());
EXPECT_EQ(0,strcmp(a,"The testing word"));
}
TEST(testCase17,extend){
Sting v="The testing word",e=",actually , sentence",m=v+e;
v+=e;
EXPECT_EQ(m,v);
}
TEST(testCase18,reverse){
Sting v="drow",e="word";
v.reverse();
EXPECT_EQ(e,v);
}
TEST(testCase19,tolower){
Sting v="ALL THE chImPZ%s @134",k="all the chimpz%s @134";
v.tolower();
EXPECT_EQ(v,k);
}
TEST(testCase20,toupper){
Sting v="ALL THE chImPZ%s @134",k="ALL THE CHIMPZ%S @134";
v.toupper();
EXPECT_EQ(v,k);
}
TEST(testEnd,EndandPause){
system("pause");
}

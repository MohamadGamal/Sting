#include <iostream>
using namespace std;
template<typename chartype>
class charpattern{
public:
	bool operator==(chartype c){
		for(int i=0;i<list.size();i++){
			if(isin(c,list[i].second)&&list[i].first==true)
			{
				return true;
			}
		}
		return false;
	}
	void addrange(int start,int end,bool in){
		if(start>end){
		int swap=end;
		end=start;
		start=swap;
		
		}
		pair<bool,pair<int,int>> listelem;
		listelem.first=in;
		listelem.second=pair<int,int>(start,end);
		list.push_back(listelem);
	}
private:
	bool isin(chartype v,pair<int,int> c){
		if((int)v>=c.first&&(int)v<=c.second)
		return true;
	return false;
	}
	vector<pair<bool,pair<int,int>>> list;
};

template<typename chartype>
class Sting_node{
public:
	chartype elemc;
	Sting_node<chartype> * next;
};
/*
template<typename chartype>
class Sting_part{
public:
	Sting_part(Sting_node<chartype> ** firstptr)
	{
		Sting_part::firstptr=firstptr
	}

void operator=(chartype * chars)
{


}
void operator=(chartype chara){



}
		
private:
	void inline clear(){
	firstptr=NULL;
	}
Sting_node<chartype> ** firstptr;
};*/
template<typename chartype,chartype nullchar=(chartype)(0)>
class Sting_List_Generic{
	friend std::istream & operator>><chartype,nullchar>(istream &input,Sting_List_Generic<chartype,nullchar> & target );
	friend std::ostream & operator<<<chartype,nullchar>(ostream &output,Sting_List_Generic<chartype,nullchar> &target );
public:
Sting_List_Generic(){

	init();
	
}

Sting_List_Generic(chartype *str){

	init();
	for(int i=0;str[i]!=nullchar;insert(i,str[i++]));

	}

Sting_List_Generic(std::basic_string<chartype> str){

	init()
	for(int i=0;i<str.size();insert(i,str[i++]));


}
/*
The copy constructor , it facilitate making more than version of the Sting class without sharing pointers
between the Sting object bodies , it make use of the private function copy

*/
Sting_List_Generic(const Sting_List_Generic & source){
		init();
	copy(source);
	}
	/*
	The function that returns the size of the current sting;
	*/
	int getsize()const{

		return size;
	
	}
	/*
	The function that allows inserting a character in a random position in the string , if the position is larger than the current size ,
	it will append the character
	
	*/
	void insert(int pos,chartype c){
		Sting_node<chartype>** cur=&top;
		while(*cur!=nullchar&&pos--!=0)
			cur=&((*cur)->next);
		Sting_node<chartype> * cp=new Sting_node<chartype>;
		cp->elemc=c;
		cp->next=*cur;
		*cur=cp;
		last=*cur;
		size++;
	}
	/*the square bracket operator that allow accessing a random character in the Sting object it allow modification 
	(since it return it's reference)*/
	chartype & operator[](int pos)const{
		Sting_node<chartype>* cur=top;
	for(int i=0;i<pos&&cur!=NULL;i++,cur=cur->next);
	return cur->elemc;
	
	}
	/*The function that allows inserting a character in a random position in the string */
	void remove(int pos){
	Sting_node<chartype>** cur=&top;
	while(*cur!=NULL&&pos--!=0)
			cur=&((*cur)->next);
	Sting_node<chartype> * cp= (*cur)->next;
	delete *cur;
	*cur =cp;
	size--;
	}
	/*the assignment operator , it allows an object of type Sting to be assigned to another object of the same type without risking 
	the shared referencing by pointers */
	Sting_List_Generic<chartype,nullchar> & operator=(Sting_List_Generic<chartype,nullchar>& dest){
		clear();
		copy(dest);
		return (*this);
	}
	/*The function that clear the Sting object and return it to its empty state*/
	void clear(){
		for(Sting_node<chartype>* cur=top;cur!=NULL;){
			Sting_node<chartype>* next=cur->next;
			delete cur;
			cur=next;
		}
		 top=NULL;
		 prev=NULL;
		 last=NULL;
		 size=0;
	}
	/*The equality operator to compare two string objects and identify whether they are equal or not*/
	bool operator ==(const Sting_List_Generic<chartype,nullchar>&  right)const{
		if(size!=right.size)
			return false;
		Sting_node<chartype> * cur=top;
		Sting_node<chartype> * cur2=right.top;
	for(;cur!=NULL;cur=cur->next,cur2=cur2->next)
		if(cur2->elemc!=cur->elemc)
			return false;
		return true;
		
	}
Sting_List_Generic<chartype,nullchar>substring(int start,int end){
	Sting_List_Generic<chartype,nullchar> Ssub;
	Sting_node<chartype> *ptr1=top ;
	for(int i=0;i<start;i++,ptr1=ptr1->next);
	for(int i=0;i<end;i++,ptr1=ptr1->next){
		Ssub.insert(Ssub.getsize(),ptr1->elemc);
	}
	return Ssub;
	
	}
Sting_List_Generic<chartype,nullchar> operator +(Sting_List_Generic<chartype,nullchar>& other){
	Sting_List_Generic<chartype,nullchar> Strd;
	Sting_node<chartype> *ptr1=top ;
	for(int i=0;i<getsize();i++,ptr1=ptr1->next){
		Strd.insert(Strd.getsize(),ptr1->elemc);
	}
	ptr1=other.top ;
	for(int i=0;i<other.getsize();i++,ptr1=ptr1->next){
		Strd.insert(Strd.getsize(),ptr1->elemc);
	}
	return Strd;
	
	}

int islocated(Sting_List_Generic<chartype,nullchar>& word){
	if(word.getsize()>getsize()||word.getsize()==0)
		return -1;
	Sting_node<chartype> *ptr1=top ;
	Sting_node<chartype> *ptr2=word.top ;
	for(int i=0;i<getsize();i++,ptr1=ptr1->next){
		if(ptr1->elemc==ptr2->elemc)
			ptr2=ptr2->next;
		else ptr2=word.top;
		if(ptr2==NULL)
			return i-word.getsize()+1;
	}
	return -1;

}
vector<Sting_List_Generic<chartype,nullchar>> patternmatch(Sting_List_Generic<chartype,nullchar>& word){
	
	Sting_node<chartype> *ptr1=top ;
	int vecptr=0;
	vector<Sting_List_Generic<chartype,nullchar>> vecs;
	Sting_List_Generic<chartype,nullchar> wordcur;
	vector<pair<bool,charpattern<chartype>>> wordvec=parseregex(word,0,255);
	//cout<<wordvec.size();
	for(int i=0;i<getsize();i++,ptr1=ptr1->next){
		if(wordvec[vecptr].second==ptr1->elemc){
			vecptr++;
			wordcur.insert(wordcur.getsize(),ptr1->elemc);
		}
		else {
			vecptr=0;
			wordcur.clear();
		}
		if(vecptr==wordvec.size()){
		vecs.push_back(wordcur);
		vecptr=0;
		}
	//cout<<vecptr<<ptr1->elemc<<endl;
	}
	
	return vecs;

}

basic_string<chartype> stdstring() const{
basic_string<chartype> strret;
stdstring(strret);
return strret;
}
void stdstring(basic_string<chartype>& stdstringref) const{
	Sting_node<chartype> * cur=top;
	for(int i=0;i<getsize();i++,cur=cur->next)
		stdstringref.push_back(cur->elemc);

}
chartype * cstring() const{
	 chartype * cnew= new chartype[getsize()+1];
	cstring(cnew);
	return cnew;
}
 void cstring(chartype *cstr) const{
	 int i;
	 Sting_node<chartype> * cur=top;
	 for(i=0;i<getsize()&&(cstr[i]=cur->elemc);i++,cur=cur->next);
	 cstr[i]=nullchar;
 }
 void reverse(){
	 Sting_node<chartype> *prev=NULL;
	 Sting_node<chartype> * cur=top;
	 while(cur){
	Sting_node<chartype> * temp=cur->next;
	cur->next=prev;
	 prev=cur;
	 cur=temp;
	 }
top=prev;
 }
 void operator+=(Sting_List_Generic<chartype,nullchar>& exsting){
	 for(int i=0;i<exsting.getsize();i++)
		 insert(getsize(),exsting[i]);
 }
 void tolower(){
 pair<chartype,chartype> rangelow;
 pair<chartype,chartype> rangehigh;
 rangelow.first=chartype('a');
 rangelow.second=chartype('z');
 rangehigh.first=chartype('A');
 rangehigh.second=chartype('Z');
 Sting_node<chartype> * temp=top;
 for(;temp;temp=temp->next){
	 if(temp->elemc>=rangehigh.first&&temp->elemc<=rangehigh.second)
			temp->elemc+=chartype('a')-chartype('A');
 }
 
 }
 void toupper(){
 
  pair<chartype,chartype> rangelow;
 pair<chartype,chartype> rangehigh;
 rangelow.first=chartype('a');
 rangelow.second=chartype('z');
 rangehigh.first=chartype('A');
 rangehigh.second=chartype('Z');
 Sting_node<chartype> * temp=top;
 for(;temp;temp=temp->next){
	 if(temp->elemc>=rangelow.first&&temp->elemc<=rangelow.second)
			temp->elemc+=chartype('A')-chartype('a');
 }
 
 }
 
private:


vector<pair<bool,charpattern<chartype>>> parseregex(Sting_List_Generic<chartype,nullchar> v,int start,int end){
vector<pair<bool,charpattern<chartype>>> p;
	
for(int i=0;i<v.getsize();){
	if(v[i]=='['){
		if(v[i+2]=='-')
		{
		charpattern<chartype> chari;
		chari.addrange((int)v[i+1],(int)v[i+3],true);
		p.push_back(pair<bool,charpattern<chartype>>(false,chari));
		i+=5;
		}
		else{
			charpattern<chartype> chari;
			i++;
			for(;v[i]!=']';i++){
			//	cout<<v[i];
			chari.addrange((int)v[i],(int)v[i],true);
			}
			p.push_back(pair<bool,charpattern<chartype>>(false,chari));
		
			i++;
		}
		}
		else if(v[i]=='_'){
		charpattern<chartype> chari;
		chari.addrange(start,end,true);
		p.push_back(pair<bool,charpattern<chartype>>(false,chari));
		i++;
		}
		else {
		charpattern<chartype> chari;
		chari.addrange((int)v[i],(int)v[i],true);
		p.push_back(pair<bool,charpattern<chartype>>(false,chari));
		i++;
		}

		

}
return p;
	}
void inline init(){
	 top=NULL;
		 prev=NULL;
		 last=NULL;
		 size=0;
	}

	/*a simple function to copy a sting object to another*/
void inline copy (const Sting_List_Generic<chartype,nullchar> &source){
	Sting_node<chartype>** curp=&top;
	for(Sting_node<chartype>* cur=source.top;cur!=NULL;cur=cur->next)
	{	
		Sting_node<chartype> * cp=new Sting_node<chartype>;
		cp->elemc=cur->elemc;
		*curp=cp;
		curp=&cp->next;
		
	}
	*curp=NULL;
	size=source.size;
	}
	Sting_node< chartype> * top;
	Sting_node< chartype> * prev;
	Sting_node< chartype> * last;
	int size;
};
/*The overloading of the binary left shift operator with class ostream (basic_ostream<char>) to allow objects of the mentioned 
class to deal with the Sting object*/
template<typename chartype,chartype nullchar>
std::ostream & operator<<(ostream &output,Sting_List_Generic<chartype,nullchar> &target ){
	
	for(Sting_node<chartype>* cur=target.top;cur!=NULL;cur=cur->next)
		output<<cur->elemc;
return output;
}
/*The overloading of the binary right shift operator with class istream (basic_istream<char>) to allow objects of the mentioned 
class to deal with the Sting object*/
template<typename chartype,chartype nullchar>
std::istream & operator>>(istream &input,Sting_List_Generic<chartype,nullchar> & target ){
target.clear();
chartype k;
input.get(k);
int pos=0;
while(k!='\n')
{
	target.insert(pos++,k);
	input.get(k);
}
return input;
}
/* A type defenetion to facilitate usage of the common Sting (a Sting of charachters) */
typedef Sting_List_Generic<char> Sting;
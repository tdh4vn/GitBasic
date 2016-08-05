#include <iostream>
using namespace std;

class Rational
{
	private:
		int tuso, mauso;
	public:
		Rational()
		{
			tuso=0;
			mauso=1;
		}
		Rational(int t, int m) {
			tuso = t;
			mauso = m;
		}
		friend ostream &operator<<(ostream &out, const Rational& r);
		friend istream &operator>>(istream &, Rational&);
		void Rutgon();
		Rational operator + (Rational);
		Rational operator - (Rational);
		Rational operator * (Rational);
		Rational operator / (Rational);
		void setts(int ntuso);
		void setms(int nmauso)
		{
			mauso=(mauso!=0) ? nmauso:1;
		}
		int getts()
		{
			return tuso;
		}; 
		int getms()
		{
			return mauso;
		};
		void floatingPoint();
};

ostream& operator<< (ostream &out, const Rational &Phanso)
{
	if (Phanso.tuso==0){	
		out<<"0";
	} else if (Phanso.mauso==1){
		out<<Phanso.tuso;
	} else {
		out<< Phanso.tuso <<"/"<< Phanso.mauso;
	}
	
	return out;
}


istream &operator >>(istream &in, Rational &Phanso)
{
	cout<<"Nhap tu so: ";
	in>>Phanso.tuso;
	cout<<"Nhap mau so: ";
	in>>Phanso.mauso;
	while (Phanso.mauso==0)
	{
		cout<<"Nhap sai! Moi nhap lai: ";
		in>>Phanso.mauso;
	}
	Phanso.Rutgon();
	return in;
}

int UCLN(int a, int b)
{
	while (b!=0)
	{
		int r=a%b;
		a=b;
		b=r;	
	}
	return a;
}

void Rational::Rutgon()
{
	int tu=this->tuso;
	int mau=this->mauso;
	if(UCLN(tu, mau)==1)
	cout<<"Phan so da toi gian!";
	else
	{
		this->tuso=tu / UCLN(tu,mau);
		this->mauso=mau / UCLN(tu,mau);
		cout<<"Phan so toi gian la: "<<tuso<<"/"<<mauso;
	}
}

Rational Rational::operator +(Rational b)
{
	Rational res;
	res.tuso = this->tuso*b.mauso + b.tuso*this->mauso;
	res.mauso= this->mauso*b.mauso;
	res.Rutgon();
	return res;
}

Rational Rational::operator /(Rational b)
{
	Rational res;
	res.tuso = this->tuso*b.mauso;
	res.mauso= this->mauso*b.tuso;
	res.Rutgon();
	return res;
}

Rational Rational::operator -(Rational b)
{
	Rational res;
	res.tuso = this->tuso*b.mauso - b.tuso*this->mauso;
	res.mauso= this->mauso*b.mauso;
	res.Rutgon();
	return res;
}

Rational Rational::operator *(Rational b)
{
	Rational res;
	res.tuso = this->tuso*b.tuso;
	res.mauso= this->mauso*b.mauso;
	res.Rutgon();
	return res;
}

void Rational::floatingPoint()
{
	float x = (float) tuso/mauso;
	cout<<x;
}

main()
{
	Rational phanso1, phanso2, kq;
	cin>>phanso1; cout<<phanso1;
	cin>>phanso2; cout<<phanso2;
	cout<<"Tong: "; kq=phanso1+phanso2;
	kq.Rutgon();
	kq.floatingPoint();
	cout<<"Hieu: "; kq=phanso1-phanso2;
	kq.Rutgon();
	kq.floatingPoint();
	cout<<"Nhan: "; kq=phanso1*phanso2;
	kq.Rutgon();
	kq.floatingPoint();
	cout<<"Chia: "; kq=phanso1/phanso2;
	kq.Rutgon();
	kq.floatingPoint();
}

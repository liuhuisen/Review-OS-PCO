
2.30
int tadd_ok(int x,int y)//判断有符号整数加法是否溢出
{
    int neg_over=x<0&&y<0&&x+y>=0;
    int pos_over=x>0&&y>0&&x+y<0;
    return !neg_over&&!pos_over;
}
int tadd_ok(int x,int y)
{
	int sum=x+y;
	return !((x<0==y<0)&&(sum<0!=x<0));
}
2.32
tsub_ok(int x,int y)//判断减法是否溢出
{
	int sub=x-y;
	int neg_over=x<0&&y>0&&(sub>=0);
	int pos_over=x>=0&&y<0&&(sub<0);
	return !neg_over&&!pos_over;
}
2.35
int tmult_ok(int x,int y)//判断乘法是否溢出
{
	int p=x*y;
	return !x||p/x==y;
}
2.36
int tmult_ok(int x,int y)//判断乘法是否溢出
{
	long long p=(long long)x*y;
	long long over=p&(~0xffffffffll);//与乘积和p相与的数要声明为ll(long long)类型
	return !over;
}
int tmult_ok(int x,int y)//判断乘法是否溢出
{
	long long pll=(long long)x*y;
	return pll==(int)pll;
}

2.55
2.56
2.57
void show_bytes(unsigned char* p,size_t len)
{
    for (size_t i=0;i<len;i++)
    {
        cout<<hex<<(int)p[i]<<" ";
    }
    cout<<endl;
    return;
}
void show_short(short s)
{
    show_bytes((unsigned char*)&s,sizeof(s));
    return;
}
void show_int(int i)
{
    show_bytes((unsigned char*)&i,sizeof(i));
    return;
}
void show_long(long l)
{
    show_bytes((unsigned char*)&l,sizeof(l));
    return;
}
void show_double(double d)
{
    show_bytes((unsigned char*)&d,sizeof(d));
    return;
}
2.58
int is_little_endian()
{
    long l=LONG_MAX;
    unsigned char* p=(unsigned char*)&l;
    //cout<<hex<<(long)*p<<endl;
    if ((long)*p==0xffl)
    {
        return 1;
    }
    return 0;
}
2.59
(x&0xff)|(y&~0xff)
2.60
unsigned replace_byte(unsigned x,int i,unsigned char b)
{
    return (~(0xff<<(i*8))&x)|((unsigned)b<<(i*8));
}
2.61
A !(((~0x0)&x)-(~0x0))或者!(~x)//x先和一个全1的数相与，再减去全1的数
B !(x-(0x0))或者!!(~0x0)//x减去全0的数
C !((0xff&x)-(0xff))//将x除低字节以外的位置零，再减去0xff
D !(x>>((sizeof(int)-1)<<3)-0x0)
2.64
int any_odd_one(unsigned x)//判断x的任意奇位是否为1
{
    return !(x^0xaaaaaaaa);
}
2.67
B C
int int_size_is_32()//判断int类型是否为32位
{
    return !((sizeof(int)<<3)-0x20);
}

3.22
int max_int_n_factorial()
{
    int n=1;
    int factorial_n_decrement=1;
    int factorial_n=1;
    do
    {
        factorial_n_decrement*=n;
        ++n;
       factorial_n*=n;
        if (!(factorial_n/n==factorial_n_decrement))//判断n!是否溢出
        {
            break;
        }
    } while(1);
    return n-1;
}
3.29
A
long sum=0;
long i=0;
while (i<10)
{
	if (i&1)
	{
		continue;
	}
	sum+=i;
	i++;
}
存在的问题：会陷入死循环。当i=1时，开始陷入死循环。
B
long sum=0;
long i=0;
while (i<10)
{
	if (i&1)
	{
		goto increment;
	}
	sum+=i;
  increment:
    i++;
}
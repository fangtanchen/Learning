class Singleton{
    static Singleton s;
    int i;
    Singleton(int x):i(x){};
    Singleton &operator=(Singleton&);
    Singleton(const Singleton&);
    public:
    static Singleton& instance(){return s;}
    int getVal(){return i};
    int setVal(int x){i=x;}
}

Singleton Singleton::s(47);

int main(){
    Singleton &s=Singleton::instance();
    cout<<s.getVal()<<endl;
    return 0;
}

    double g_bb = 11.2;
    void foo1()
    {
        auto f_add = [&](int a,int b)->int{return a+b;};
        std::cout<<f_add(1,2);//3
        std::cout<<std::endl;
        
        double aa = 5.0;
        auto fun = [aa]()->double{return aa+3;};//此时aa不能进行赋值操作如：aa=7;
        std::cout<<fun();
        std::cout<<"  aa:"<<aa<<std::endl;//8 aa:5
        auto fun2 = [&aa]()->double{aa = 7.0;return aa+3;};//此时aa以引用方式传入，可以进行赋值操作如：aa=7,同时修改aa的值;
        std::cout<<fun2();
        std::cout<<"  aa:"<<aa<<std::endl;//10  aa:7
        auto fun3 = [&]()->double{aa = 8.0;g_bb = 15;return aa+3;};//此时aa可以进行赋值操作如：aa=7;,其他在作用域范围的变量都可以以引用方式调用
        std::cout<<fun3();
        std::cout<<"  aa:"<<aa<<" g_bb:"<<g_bb<<std::endl;//11  aa:8
    }
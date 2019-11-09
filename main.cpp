
#include <iostream>
#include "WzSharememory.h"

void testWriteRead();
void testReusable();

int main(int argc,char** argv)
{
    printf("=========WzSharememory Test============\n");

    testWriteRead();

    testReusable();

	printf("Please enter any key to quit!\n");
	getchar();

    return 0;
}

void testWriteRead()
{
    printf("=========testWriteRead==begin========\n");
    // ouyagnwei: test write && read
    // write
    WzSharememory ouyangwei1,ouyangwei2;
    ouyangwei1.setName("ouyangwei");
    if(ouyangwei1.create(10))
    {
        int* data = (int*)ouyangwei1.open();
        printf("data: %p\n",data);
        if(NULL != data)
        {
            *data = 12345;
        }
    }
    // read
    ouyangwei2.setName("ouyangwei");
    if(ouyangwei2.create(20))
    {
        // test create an existed sharememory
        // if correct that it should create failed 
    }
    else
    {
        int* data = (int*)ouyangwei2.open();
        printf("data: %p\n",data);
        if(NULL != data)
        {
            printf("ouyangwei2 read *data : %d\n",*data);
        }
    }
    ouyangwei2.destroy();
    printf("=========testWriteRead==end==========\n");
}

void testReusable()
{
    printf("=========testReusable==begin==========\n");
    // zhangsan: test reusable
    // use for zhangsan1
    WzSharememory zhangsan("zhangsan1");
    if(zhangsan.create(10))
    {
        int* data = (int*)zhangsan.open();
        printf("data: %p\n",data);
        if(NULL != data)
        {
            *data = 678910;
            printf("zhangsan1 read *data : %d\n",*data);
        }
        zhangsan.destroy();
    }
    // use for zhangsan2
    zhangsan.setName("zhangsan2");
    if(zhangsan.create(10))
    {
        int* data = (int*)zhangsan.open();
        printf("data: %p\n",data);
        if(NULL != data)
        {
            *data = 109876;
            printf("zhangsan2 read *data : %d\n",*data);
        }
        zhangsan.destroy();
    }
    printf("=========testReusable==end==========\n");
}
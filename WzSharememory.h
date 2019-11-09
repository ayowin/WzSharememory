/**
 * @author ouyangwei (ouyang_wei_112@126.com)
 * @brief WzSharememory is a cross-platform sharememory library
 * @version 1.1
 * @date 2019-11-10
 * @copyright Copyright (c) 2019
 */

#ifndef __WZSHAREMEMORY_H__
#define __WZSHAREMEMORY_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include<sys/types.h>
#include<sys/shm.h>
#endif

struct WzSharememoryHandle;

class WzSharememory
{
public:
    WzSharememory();
    WzSharememory(std::string name);
    ~WzSharememory();

    std::string getName();

    void setName(std::string name);

    bool create(unsigned int size);

    void* open();

    void destroy();

private:
    void init();
    void release();
    void resetHandle();

private:
    std::string name;
    WzSharememoryHandle *handle;
};

#endif
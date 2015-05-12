#include <stdio.h>
/**
 * 如果printf的字符串参数中包含了未知的转义序列，
 * 编译时编译器会给出警告，但程序可以编译成功。
 * 该程序的输出为：
 * hello, world
 * c
 */
main()
{
    printf("hello, world\n\c");
}

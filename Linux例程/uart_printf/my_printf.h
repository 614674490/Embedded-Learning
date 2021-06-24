#ifndef _MY_PRINTF_H
#define _MY_PRINTF_H
#include "uart.h"

typedef char * va_list;  //���ڶ����ַ�ָ�� ָ��format���ڵ�ַ Ȼ�������ջ
#define _INTSIZEOF(n)    ((sizeof(n) + sizeof(int) -1) &  ~(sizeof(int) - 1))   //ָ��ǰ���ֽڵĳ���(�����ǰ�������ƶ�����һ������
#define va_start(ap,v)      ( ap = (va_list)&v + _INTSIZEOF(v))//��ap�ƶ���v���ڵ�λ��
#define va_arg(ap,t)        ( *(t *)(ap=ap + _INTSIZEOF(t) , ap - _INTSIZEOF(t)))  //���ݲ������ͣ��Ƚ�p�ƶ�����һ������������Ȼ���ȡָ��p�ϴ�ָ���ֵ
#define va_end(ap)      ( ap =(va_list)0) //p=NULL ����Ұָ��

#define  __out_putchar  send_char
#define MAX_NUMBER_BYTES 64 //��ӡ�ַ�����󳤶�
extern int my_printf_test(void);
int printf(const char *fmt, ...);
#endif // _MY_PRINTF_H

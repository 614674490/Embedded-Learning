#include "my_printf.h"

unsigned char hex_tab[] = {'0','1','2','3','4','5','6','7',\
                           '8','9','a','b','c','d','e','f'
                          };
//����uart.c�е��ַ���ӡ����
static int outc(int c)
{
    __out_putchar(c);
    return 0;
}

static int outs(const char *s)
{
    while(*s)
        __out_putchar(*s++);
    return 0;
}

/*
 * n :  ��������
 * base : ���� 10 8 16
 * lead : ǰ���ַ��� ͨ��Ϊ�ֽڶ���Ŀո�
 * maxwidth : �ֽڶ�����  %100d  ����100���ո����
 */
static int out_num(long n, int base, char lead, int maxwidth)
{
    unsigned long m = 0; //���ڻ���n
    char buf[MAX_NUMBER_BYTES] ;
    char *s = buf + sizeof(buf);  //�����ַ����ռ�
    int count = 0,i = 0;
    *--s = '\0'; //�ӽ�����

    if(n<0)
        m=-n;    //�ȰѸ���������� ����ټӸ���
    else
        m=n;
    do
    {
        *--s = hex_tab[m%base];
        count++;
    }
    while((m/=base)!=0);  //ͨ�������ʮ������ת����Ŀ�������
    if( maxwidth&&count<maxwidth) //���ǰ���ַ���
    {
        for(i = maxwidth - count ; i ; i--)
            *--s = lead;
    }
    return outs(s); //��ӡ������
}
/*reference :   int vprintf(const char *format, va_list ap); */
static int my_vprintf(const char *fmt, va_list ap)
{
    char lead = ' ';
    int maxwidth  = 0;

    for(; *fmt!='\0'; fmt++)
    {
        if(*fmt!='%')
        {
            outc(*fmt);    //������ͨ�ַ������ӡ
            continue;
        }
        //format : %08d, %8d,%d,%u,%x,%f,%c,%s ������ʽ�ַ�����н���
        fmt++;  //�Թ�%���÷���ֻ�Ǹ�ʽ�ַ��ı�־
        if(*fmt == '0') //�������
        {
            lead = '0';
            fmt++;
        }
        lead = ' ';
        maxwidth = 0;
        while(*fmt>'0' && *fmt<='9')//��/�Ҷ����ֽ���
        {
            maxwidth *= 10; //eg: 102 �����λ1 ʮλ0 ��λ2 Ȼ����� �Ӷ�����������ֽ���
            maxwidth += (*fmt- '0'); //���ַ���ת��������
            fmt++;
        }
        switch(*fmt)
        {
        case 'd' :
            out_num(va_arg(ap,int),10,lead,maxwidth);
            break;
        case 'o' :
            out_num(va_arg(ap,unsigned int),8,lead,maxwidth);
            break;
        case 'u' :
            out_num(va_arg(ap,unsigned int),10,lead,maxwidth);
            break;
        case 'x' :
            out_num(va_arg(ap,unsigned int),16,lead,maxwidth);
            break;
        case 'c' :
            outc(va_arg(ap,char));
            break;
        case 's' :
            outs(va_arg(ap,char *));
            break;
        default :
            outc(*fmt);  //�����Ϊ��ͨ�ַ���
            break;
        }
    }
    return 0;
}
//reference :  int printf(const char *format, ...);
int printf(const char *fmt, ...)
{
    va_list ap;             //�ȴ���һ��ָ���ջ��ָ��
    va_start(ap,fmt);        //�ƶ�����һ���̶�������������λ��
    my_vprintf(fmt,ap);     //������ջ���� ���Ҵ�ӡ����
    va_end(ap);            //���ָ��ap ����Ұָ��
    return 0;             //��ӡ���� ����0
}

int my_printf_test(void)
{
    printf("This is www.100ask.org   my_printf test\n\r") ;
    printf("test char           =%c,%c\n\r", 'A','a') ;
    printf("test decimal number =%d\n\r",    123456) ;
    printf("test decimal number =%d\n\r",    -123456) ;
    printf("test hex     number =0x%x\n\r",  0x55aa55aa) ;
    printf("test string         =%s\n\r",    "www.100ask.org") ;
    printf("num=%08d\n\r",   12345);
    printf("num=%8d\n\r",    12345);
    printf("num=0x%08x\n\r", 0x12345);
    printf("num=0x%8x\n\r",  0x12345);
    printf("num=0x%02x\n\r", 0x1);
    printf("num=0x%2x\n\r",  0x1);

    printf("num=%05d\n\r", 0x1);
    printf("num=%5d\n\r",  0x1);

    return 0;
}

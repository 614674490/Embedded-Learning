#include "s3c2440_soc.h"
#include "uart.h"

void uart0_init(int baudrate)
{
    /* �����������ڴ��� GPH2->TXD0 GPH3->RXD1 */
    GPHCON &= ~((3<<4)|(3<<6)); //������
    GPHCON |= (2<<4)|(2<<6);        //����λ
    GPHUP &=  ~((1<<2)|(1<<3));  //ʹ���ڲ���������

    UFCON0=0x00;  //��ʹ��FIFO
    UMCON0=0x00; //��ʹ������

    /* �������ݸ�ʽ 8n1: ����żУ��λ 8������λ 1��ֹͣλ*/
    ULCON0 = 0x03;

    /* UBRDIVn = (int)( UART clock / ( buad rate x 16) ) �C1
     * UART clock=PCLK (PCLK����Ϊ50MHz)
     * UBRDIVn=(50000000/(115200*16))-1 = 26
     */
    UCON0 = 0x05 ;  //PCLK �жϲ�ѯģʽ �ر�DMA�Լ�һЩ����Ĵ���

    /* ���ò�����Ϊ115200 */
    UBRDIV0 =  (PCLK/(baudrate*16))-1;     //26  0x1a
}

//����һ���ֽ�
int send_char(int c)
{
    while( !(UTRSTAT0 & TXD0READY) ); //�ȴ����ͻ�����Ϊ��
    UTXH0 = c;
}
//����һ���ֽ�
int receive_char(void)
{
    while( !(UTRSTAT0 & RXD0READY) ); //�ȴ����ջ������յ�����
    return URXH0;
}

int print_string(const char *s)
{
    while(*s)
    {
        send_char(*s++);
    }
    return 0;
}

/*
 * ����GPR5
 */

 .text
 .global _start

 _start:

 /* ����GPB5Ϊ�������
  * GPBCON : 0x56000010  = 0x00000400
  */
  LDR R1 , =0x56000010
  MOV R0 , #0X400
  STR R0 , [R1]

 /* ����GPB5����͵�ƽ 00 0000 0000
  * GPBDATA : 0x56000014 = 0x0
  */
  LDR R1 , =0x56000014
  MOV R0 , 0
  STR R0 , [R1]

/* ��ѭ�� */
halt:
    b halt

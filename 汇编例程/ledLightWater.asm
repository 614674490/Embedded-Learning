        ORG 0000H   ;��֤Ŀ�������0000H��ִ��
MIAN:   MOV SP ,#60H
        MOV B , #01H  ;����ֵ
MLP:    MOV A,B
        MOV P1,A
        RL  A       ;�ۼ���ѭ������
        MOV B,A
        LCALL   DELAY
DELAY:  MOV R5,#200
DLP��   DJNZ R5,DLP   ;�Ĵ�����һ ��Ϊ����ת��
        RET  ;�ֳ��򷵻� ������ת��->MLP

        END ;�������


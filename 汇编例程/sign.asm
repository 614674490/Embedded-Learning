;X�����40H Y�����41H ������ź���
SIGNFUC:
            MOV     A       ,40H        ;��ȡX��ֵ �����ۼ���A��
            CJNE    A       ,#00H,NZEAR ;������������������
            AJMP    NEGT                ;��������ֱ�Ӹ�ֵ  x=0 y=0
NZEAR:                                  ;JB:ֱ��ѰַλΪ1��ת��
            JB      Acc.7   ,POSI       ;���ݷ���λ�ж����� <0����ת��POSI
            MOV     A,      #01H        ;x>0 y=1
            AJMP    NEGT
POSI:
            MOV     A       ,#81H       ;x<0 y=-1
            AJMP    NEGT
NEGT:
            MOV     41H     ,A
            END

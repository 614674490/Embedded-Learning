        ORG     0000H
        MOV     A   ,#02H
        MOV     SP  ,#42H
        MOV     41H ,#FFH
        MOV     42H ,#FFH
MAIN:   POP     DPH         ;��ջ  DPH=(42H)=FFH SP-1=41H DPH��DPTR�ĸ�8λ
        POP     DPL         ;��ջ  DPL=(41H)=FFH SP-1=40H DPL��DPTR�ĵ�8λ
        MOV     DPTR,#3000H
        RL      A           ;A<<1 (A)=04H
        MOV     B   ,A      ;(B)=04H
        MOVC    A   ,@A+DPTR;A=(3000H+04H)=(3004H)=50H
        PUSH    Acc         ;��ջ SP+1=41H (41H)=(Acc)=50H �˴�Acc����дΪA
        MOV     A   ,B      ;(A)=(B)=04H
        INC     A           ;(A)=04H+1=05H
        MOVC    A   ,@A+DPTR   ;(A)=(3005H)=80H
        PUSH    Acc         ;��ջ SP+1=42H (42H)=(Acc)=80H
        RET                 ;���򷵻أ���SP��ջ�����ݴ洢��PC��     PC=8050H
        ORG     3000H       ;����׵�ַ
        DB: 10H,80H,30H,80H,50H,80H
        END


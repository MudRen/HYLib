// �鷿 shufang.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "�鷿");
        set("long", @LONG
�������������鷿�������������������ضѷ��źܶ��顣�����
һ����Ⱦ����Ȼ�����˾��������鼮���������ż������ɵ���������
��������͸��������ˡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ 
            "west" : __DIR__"dating",
]));

        setup();
        replace_program(ROOM);
}

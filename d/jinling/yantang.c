//jinling  yantang.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ｨ�����ӵ��ţ���������������л�������������˲��ϣ���һ����
�����˻��ŵ�һ�����ڡ�
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"wuyigang",

]));
        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/wangwei" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
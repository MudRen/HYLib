// qianting.c ǰ��
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
�����ǹ�Ĺ��ǰ����������ģ��㼸��ʲôҲ�����塣ȫ������
���м������������һ��ҹ���飬ӳ��������Ļƹ⡣����������˶
���ʯ�����ɵģ������ƺ���д��һЩʲô��--����ôҲ��������ˡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"xiaoting",
                "north" : __DIR__"mumen",
                "west" : __DIR__"xiuxishi",
        ]));
        set("objects", ([
           __DIR__"npc/gumudizi" : 3,
                   ]));

        setup();
        replace_program(ROOM);
}

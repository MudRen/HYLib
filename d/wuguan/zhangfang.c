#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
����������ڵ�һ���ʷ�������һ���ʷ���������������������ʡ�
�����µ�����Χ���ʷ���������������ѻ���������Ǯ��������ǽ
�Ϲ���һ������(paizi)��
LONG);
        set("exits", ([
                "north" : __DIR__"shilu-1",
        ]));
        set("objects", ([
                __DIR__"npc/fan" : 1,
        ]) );
        set("item_desc", ([ 
            "paizi" : "������д����
����ʷ���
        ��Ǯ(cun)��
        ȡǮ(qu)��
        ����(check)��
        �һ�(duihuan)��
        \n"
        ]));    
        setup();
        replace_program(ROOM);
}



#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ϰ����");
        set("long", @LONG
����������ڵ�һ��ϰ���ã�����һ����ͷ�ڽ����书����������������
��ͷѧϰ�����������Ϸ����Ÿ��ң�����д�š��Եÿ��п࣬��Ϊ�����ˡ���
LONG);
        set("exits", ([
                "north" : __DIR__"shilu-2",
        ]));
        set("objects", ([
                __DIR__"npc/jiaotou2" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}


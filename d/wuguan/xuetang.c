#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ѧ��");
        set("long", @LONG
����������ڵ�һ��Сѧ�ã������������ʶ�������һ��������
��������Ľ��ţ�������������Ӻ����ӣ��������Ǳ�ǽ��д�˼���
���֡���׳��Ŭ�����ϴ�ͽ�˱�����
LONG);
        set("exits", ([
                "south" : __DIR__"shilu-1",
        ]));
        set("objects", ([
                __DIR__"npc/fang" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}



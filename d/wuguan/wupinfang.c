#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��Ʒ��");
	set("long", @LONG
������Ʒ����һ������ӡ�����ŵ��������룬��������Ĺܼ���
�����渺��ģ�һЩ�����ڸ�����Ʒ���ߵĹܼ�˵��ʲô��
LONG);
        set("exits", ([
	       "south" : __DIR__"lang4",
	       "north" : __DIR__"lang6",
	       "west" : __DIR__"shilu-1",
	]));
     set("no_fight",1);
        set("objects", ([
           __DIR__"npc/laoli" : 1,
           __DIR__"npc/tlsdizi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}


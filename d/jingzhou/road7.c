// Room: /d/jingzhou/road7.c
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "С·" NOR);
        set("long", @LONG
һ����᫵Ļ���С·��·���Ӳݴ��������߿��Կ������ݵĹ�
������ȥ���һ�������ݡ�
LONG
        );
        set("exits", ([
  "east" : __DIR__"road6",
  "west" : __DIR__"guandao1",
  ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


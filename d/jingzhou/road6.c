// Room: /d/jingzhou/road5.c
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "С·" NOR);
        set("long", @LONG
һ����᫵Ļ���С·��·���Ӳݴ���������ֻ�������������������
�ٵ�����������һ����ɽ��ɽ����ľï�ܡ�
LONG
        );
        set("exits", ([
  "east" : __DIR__"road5",
  "west" : __DIR__"road7",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


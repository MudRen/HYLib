// Room: /d/jingzhou/road5.c
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "��ɽ" NOR);
        set("long", @LONG
ɽ����ľï�ܣ�������䣬���ϸ������������ɽϪ��ˮ����������
����ҳ����������ͬһ�״���Ȼ���������������
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"qingshan1",
  "west" : __DIR__"road6",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


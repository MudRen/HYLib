// Room: /d/jingzhou/road4.c
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "��ɽ" NOR);
        set("long", @LONG
ɽ����ľï�ܣ�������䣬����羰������С���������У���
�����ҳ�ķ�϶���ս������γ���ʵİ�쵣�������鲻�ɵĸ���
����������С��ĸ�������ǰ��ȥ��

LONG
        );
        set("exits", ([
  "southeast" : __DIR__"road3",
  "westup" : __DIR__"qingshan2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


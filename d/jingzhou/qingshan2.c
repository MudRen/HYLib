// Room: /d/jingzhou/qingshan2.c
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "��ɽ" NOR );
        set("long", @LONG
˳ɽ���ߣ�ɽ�ƽ��������������Ӳݾ��������� ʹ���������ߡ�
LONG
        );
        set("exits", ([
  "westup" : __DIR__"qingshan",
  "eastdown" : __DIR__"road4",
  ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


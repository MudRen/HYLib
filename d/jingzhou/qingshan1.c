// Room: /d/jingzhou/qingshan1.c
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
  "southwest" : __DIR__"road5",
  "eastup" : __DIR__"qingshan",
  "west" : "/d/baling/shulin1",	
  ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


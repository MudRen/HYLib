// Room: /d/jingzhou/qingshan.c
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "ɽ��" NOR );
        set("long", @LONG
����ɽ����ֻ���������£��Ǹ���Զ���Ŀ�����������ȥ��ֻ��
���޳�����һ��С�ڵ㣬��Ŀ������ȴãã�����������棬ֻ��һ����
����ʴ�һ�㣬�Ǿ��ǳ����ˣ�
LONG
        );
        set("exits", ([
  "eastdown" : __DIR__"qingshan2",
  "westdown" : __DIR__"qingshan1",
  "southdown" :__DIR__"chibi1"
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


// Room: d/kyoto/longandao3.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "������");
set("long", @LONG
�������������Ǿ����Ǳ��Ľ�ͨҪ�壬���������ò��������˵���
�����¶�������
LONG );
set("exits",  ([
        "north"  : __DIR__"longandao2",
        "south"  : __DIR__"heyuan1",
      ]));
        setup();
        replace_program(ROOM);
}
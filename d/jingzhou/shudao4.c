// Room: /d/chengdu/shudao4
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "����С·" NOR );
        set("long", @LONG
�����ڳ������ϵ�һ��С·�ϣ��������ߣ��ͽ�����
������Ĵ�ɽ���ˣ����Ϸ�������С·����֪��ͨ�����
LONG
        );
        set("exits", ([
  "east" :  __DIR__"shudao3",
  "west" : __DIR__"shudao5",
  //"southeast": __DIR__"xiaolu1"
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}


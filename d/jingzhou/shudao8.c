// Room: /d/chengdu/shudao8
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "�ͱ�" NOR );
        set("long", @LONG
��������һ����Σ�յ��ͱ��ϣ��㻹�ǿ��߰ɣ���һ��С�ĵ�����ȥ��
LONG
        );
        set("exits", ([
  "down" :  __DIR__"shudao7",
  "up" : __DIR__"shudao9",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}


// Room: /d/chengdu/shudao9
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "ɽ��" NOR );
        set("long", @LONG
һ����ɽ��ɽ�����ٽ�һ���Ƕ��͵����£���ϸ������һЩʯ�ѿ�
����ţ�����ȥ��ֻ���������к����м������ӡ�
LONG
        );
        set("exits", ([
  "down" :  __DIR__"shudao8",
  "west" : __DIR__"baidicheng",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}


// Room: /d/chengdu/shudao10
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "ʯ��" NOR );
        set("long", @LONG
һ��Сʯ�ף��е��������ã���ݴ�ʯͷ�ķ�϶�г��˳�������Щ�ط���
ʯ�����������Զ���Ѿ�ĥ�Ĺ⻬�羵�����Ͽ�ȥ��ֻ���������м������ӡ�
LONG
        );
        set("exits", ([
  "northup" :  __DIR__"baidicheng",
  "west" : __DIR__"sanxia1",
  "east" : "/d/tangmen/chapu",
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}



#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������С·��һ��紵������������������ʱ��������������
���Գ۹���������ȥ��������Լ����һ�������Ĵ������
LONG);

  set("exits", ([
 "northwest":__DIR__"xiaolu1",
 "south":"/d/taiyuan/road6",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}


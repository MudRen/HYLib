
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
 "westup":__DIR__"shanlu3",
 "southeast":__DIR__"xiaolu2",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}


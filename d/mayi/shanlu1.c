
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。北边是就是长城，南面一眼望去是一片树林，树
林看起来很大。这里已经是山西的境地了。四周怪石嶙峋，几乎辨认不
出前面的道路。
LONG);

  set("exits", ([
 "northeast":__DIR__"changcheng14",
 "southdown":__DIR__"shanlu2",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}


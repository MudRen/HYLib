// Room: d/kyoto/dongmen
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "东门");
set("long", @LONG
这里就是京都的东门，在这里已经可以感受京都的繁华。高耸的城门
两边站着全副武装的守卫，时刻提醒着人们，这里曾经是天皇的都城。从
这里西行就是京都最繁华的街区千本町。

LONG );
set("exits",  ([
        "west"  : __DIR__"qianbending6",
        "east" : __DIR__"pathe",
      ]));
        setup();
        replace_program(ROOM);
}
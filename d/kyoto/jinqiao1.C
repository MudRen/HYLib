// Room: d/kyoto/jinqiao1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����");
set("long", @LONG
ԭ��������һ��ľ�ţ��������ܹ��ɽ������������ĸ�ʯ�ؽ�������
�⻬�����һ�㣬�ʵ������š�������������ׯ�����µĻʹ��۾���������
�������Ǿ����������ҵ��������ԭ��
LONG );
set("exits",  ([
        "north"  : __DIR__"yusuogate",
        "south"  : __DIR__"shangyuan1",
        "west"  : __DIR__"huchenghe3",
        "east"  : __DIR__"huchenghe4",
      ]));
        setup();
        replace_program(ROOM);
}
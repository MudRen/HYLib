// Room: d/kyoto/dangpu
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����");
set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������
ǰ����̨�ϰ���һ������(paizi)����̨��������ɼ�ϰ壬һ˫����
���������´������㡣
LONG );
set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "��������õ����������£�
value  ����
pawn ������
redeem ��ض���
sell ������
",
]));
set("exits",  ([
        "south"  : __DIR__"qianbending4",
      ]));
set("objects",  ([
        "d/kyoto/npc/shangshan.c" : 1
        ]));
        setup();
        replace_program(ROOM);
}
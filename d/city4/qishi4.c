#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��������");
set("long", "�����ǳ����ַ��ķ������ҡ���ҹĻ���ٺ�
����͸������֡����������Ŀ����д�ٹ��ˣ��������������ã�
�˼����ĵ����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ�
���ɮ�˻��ʿ��\n");

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"qishi1",
]));
    set("objects",  ([
    "clone/game/fxq"  :  1,
    ]));
set("no_fight",1);
set("no_npc",1);
  setup();
}


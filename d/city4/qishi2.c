#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "21������");
set("long", "�����ǳ����ַ���21�����ҡ���ҹĻ���ٺ�
����͸������֡����������Ŀ����д�ٹ��ˣ��������������ã�
�˼����ĵ����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ�
���ɮ�˻��ʿ��\n");

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"club",
]));
    set("objects",  ([
    "clone/game/pai21"  :  1,
    ]));
set("no_fight",1);
set("no_npc",1);
  setup();
}


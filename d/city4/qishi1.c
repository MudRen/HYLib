#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��ս����");
set("long", "�����ǳ����ַ��ĺ�վ���ҡ���ҹĻ���ٺ�
����͸������֡����������Ŀ����д�ٹ��ˣ��������������ã�
�˼����ĵ����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ�
���ɮ�˻��ʿ��\n");

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"club",
  "south" : __DIR__"qishi4",
  "north" : __DIR__"qishi5",
]));
    set("objects",  ([
    "clone/game/seaf"  :  1,
    ]));
set("no_fight",1);
set("no_npc",1);
  setup();
}


// Room: /d/feitian/jiedao2.c
inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
������һ����ͨ�Ľֵ������ұ��߲��˶�Զ�Ϳ��Լ���һ���ܴ�������ˡ�
�ڽֵ������и���ͨ�������ꡣ
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jiedao1",
  "south" : __DIR__"wuqidian",
  "east" : __DIR__"jiedao3",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}

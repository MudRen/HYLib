// Room: /d/feitian/xuanguan.c
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
������ȥ�Ϳ쵽�˻������ĵ����ˡ����������Ҫ����Ь�Ӳ���
��ȥ�ˣ��ձ���ͨ��������Ϊ���ء���ߵ�ǽ�߷���һЩľ�졣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhongting",
  "north" : __DIR__"zoulang",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/muji.c" : 1,
]));
  setup();
  replace_program(ROOM);
}

// Room: /d/pingan/pinganlu2
inherit ROOM;

void create ()
{
  set ("short", "ƽ�������");
  set ("long", @LONG
�����Ĵ�֣������ľ��񣬴�����һƬ��ƽ����ƽ���ǵĴ���ͺ���
������һ��������ƽʵ�ĸо���
LONG);

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("outdoors", "pingan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pinganguangchang",
  "south" : __DIR__"pinganlu1",
]));

  setup();
  replace_program(ROOM);
}

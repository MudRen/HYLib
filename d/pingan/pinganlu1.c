// Room: /d/pingan/pinganlu1
inherit ROOM;

void create ()
{
  set ("short", "ƽ�����һ");
  set ("long", @LONG
�����Ĵ�֣������ľ��񣬴�����һƬ��ƽ����ƽ���ǵĴ���ͺ���
������һ��������ƽʵ�ĸо���
LONG);

  set("outdoors", "pingan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pinganlu2",
  "south" : __DIR__"pinganmen",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);

  setup();
  replace_program(ROOM);
}

// Room: /d/huizhu/huanglu1
inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG
��������ҰС·��·�ϼ���������ʲô�ˡ���������������ú�
��������
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west":__DIR__"to_ts",
  "east":__DIR__"shamo2",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

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
  "west":__DIR__"shamo2.c",
  "southeast" : __DIR__"huanglu1",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

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
  "northwest" : __DIR__"huanglu2",
  "southeast" : __DIR__"guanwai",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

// Room: /d/huizhu/shamo
inherit ROOM;

void create()
{
  set ("short", "ɳĮ");
  set ("long", @LONG
����ɫ��ɳ�����࣬��������һƬ�������У����ϲ������񣬵��ϲ�
�����ޡ�ֻ��ɳĮ�е��е�����ʬ�������㣬�����й������ĺۼ���
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east":__DIR__"huanglu2",
  "west":__DIR__"huanglu3",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

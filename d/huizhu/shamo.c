// Room: /d/huizhu/shamo
inherit ROOM;

void create()
{
  set ("short", "ɳĮ");
  set ("long", @LONG
����ɫ��ɳ�����࣬��������һƬ�������У����ϲ������񣬵��ϲ�
�����ޡ�ֻ��ɳĮ�е��е�����ʬ�������㣬�����й������ĺۼ���Զ��
������һĨ���͡�
LONG);

  set("exits", ([ /* sizeof() == 2 */
"southwest":__DIR__"xingxing",
  "northeast" : __DIR__"guanwai",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

// Room: /d/japan/zhongxin
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
�������񻧵�����.�������ֵ��Ӵ˷ֱ�ͨ���ĸ�����.��һ����ȥ.
�ֵ����ߵ��̵����Ƹߵ����.�����һ�����صķ羰.
LONG);

  set("outdoors", "japan");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiedaos2",
  "east" : __DIR__"jiedaoe1",
]));

  setup();
       replace_program(ROOM);
}

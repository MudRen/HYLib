// Room: /d/japan/jiedaos2
inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
�ֵ����������˺ܶ�,��������Ǵ��ſ��ͷ�������.�ֵ����ߵ�
�̵�߸ߵ͵͵������˽ֵ�.�Ӵ���ȥ,�㶫���м�����,������ſ�վ
������������,��֪���Ǹ�ʲô��.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhongxin",
  "south" : __DIR__"jiedaos",
  "west" : __DIR__"xiangpu",
  "east" : __DIR__"shuwu",
]));
  set("outdoors", "japan");
  setup();
}

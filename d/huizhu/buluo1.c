// Room: /d/huizhu/buluo1
inherit ROOM;

void create()
{
  set ("short", "���岿��");
  set ("long", @LONG
�˴����������֣�һ��б��ֱ�������ԭ�������ڴ����ڼ���������
֮�䣬���ߵ�һ���������ر�Ĵ�һ�㡣�ϱ�����С·ͨ������֮�С�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhangpeng",
  "west" : __DIR__"zhangpeng1",
  "north" : __DIR__"buluo2",
  "south" : __DIR__"buluo",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

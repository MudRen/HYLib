// Room: /d/yanjing/didao
inherit ROOM;

void create()
{
  set ("short", "�ص���");
  set ("long", @LONG
��ص����ڵ���֮���������,ȴû��Щ��ʪ������,����������ˮ
�Ĺܵ�,˫��������,����Ӳ����.������Ǻںڵ�һ��.һ�����ӱ��洵
��,��������Ѫ��֮��.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"didao1",
  "south" : __DIR__"cave",
]));
  setup();
  replace_program(ROOM);
}

// Room: /d/menggu/road3
inherit ROOM;

void create()
{
  set ("short", "Ӫ�ʼ� ");
  set ("long", @LONG
��Ŀ����,�Ƕ������������Ӫ��,һ������һ��,�ɹŲ�������Ϊ��,
ƽʱ��ס�����ɹŰ�,��ⷽ��.�����е�ͨ�򼸸���Ļ,�ֱ��������ʹ�
�ǵ�ס��.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road1",
  "north" : __DIR__"boershu",
  "south" : __DIR__"qinwei2",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}

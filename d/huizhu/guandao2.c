// Room: /d/huizhu/guandao1
inherit ROOM;

void create()
{
  set ("short", "�ٵ�");
  set ("long", @LONG
���������Ӿ���������صĹٵ��������Ǿ��Ƿ�������ͨ������
�ء�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east":__DIR__"guandao3",
  "west":__DIR__"guandao1",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

// Room: /d/huizhu/guandao1
inherit ROOM;

void create()
{
  set ("short", "�ٵ�");
  set ("long", @LONG
���������Ӿ���������صĹٵ��������Ǿ��Ƿ������߾�������
�����ļ������ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east":__DIR__"guandao2",
  "west":__DIR__"jiayuguan",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}

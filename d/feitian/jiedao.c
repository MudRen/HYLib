// Room: /d/feitian/jiedao
inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
�����Ľֵ����ֱ��������Ų���ӣ����������ǰ�߲��˶�Զ�Ϳ��Կ���
��Ż������ĵ����ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiedao1",
  "northup" : __DIR__"damen",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}

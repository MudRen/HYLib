// Room: /d/feitian/jiedao1
inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
�ֵ��������߶����̵꣬�����߾��Ǿ����㳡�ˡ�ǰ����Զ��ͨ����Ż���������
�·���һ��ҩ�̣���˵���������һ��������
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yaopu",
  "east" : __DIR__"jiedao2",
  "north" : __DIR__"jiedao",
  "west" : __DIR__"guangchang",
]));
  set("outdoors", "feitian");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baixing" : 1,
]));
  setup();
  replace_program(ROOM);
}

// Room: /d/feitian/luorencun
inherit ROOM;

void create()
{
  set ("short", "���˴�");
  set ("long", @LONG
�������õĵط���ǽ�Ǳ߶���һЩ�������õ��ˣ�һ������������ó�޵��������㡣
�ڴ�ׯ������һ������ɾ���С·ͨ���±ߣ���Լ�����������˽�����������
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luoren.c" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jiedao3",
  "south" : __DIR__"changlewu",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}

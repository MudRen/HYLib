//yanglingdong2

inherit ROOM;

void create ()
{
  set ("short", "ƽ������");
  set ("long", @LONG
����ƽ���ǵ�һ����·ƽ�����֡����ϱ����ƽ���ǡ�����
�����ź��سǱ�Ӫ�����ڵء�
LONG);

  set("outdoors", "pingan");
  set("no_beg", 1);
//  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/man3" : 1,
//  __DIR__"npc/man4" : 1,
//]));
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan", 1);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yamen",
  "north" : __DIR__"bei2.c",
  "west" : __DIR__"bingyin",
  "south" : __DIR__"guangchang",
]));
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}

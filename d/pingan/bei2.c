//yanglingdong2

inherit ROOM;

void create ()
{
  set ("short", "ƽ������");
  set ("long", @LONG
����ƽ���ǵ�һ����·ƽ�����֡����ϱ����ƽ���ǡ�����
�ǲ�԰��ƽ����������ڵء�ǰ��ı��ź���û�п���.
LONG);

  set("outdoors", "pingan");
  set("no_beg", 1);
//  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/man1" : 1,
//  __DIR__"npc/man2" : 1,
//]));
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan", 1);
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"caidi",
  "west" : __DIR__"wumiao",
  "south" : __DIR__"bei1",
"in" : "/clone/quarry/dong01"
]));
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}

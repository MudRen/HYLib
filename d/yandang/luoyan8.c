// Room: /d/yandang/luoyan8.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
������ׯ���д���͵ĵط�,����װ�����ʵ��������,ȴ��������
�����²���,�����������������ɫ�Ĵ���ʯ,������һ�ź�ľ������
�Ա��ź���Ǽ���Ѿ��.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yahuan.c" : 2,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luoyan11",
  "south" : __DIR__"luoyan7",
  "north" : __DIR__"luoyan12",
]));

  setup();
}

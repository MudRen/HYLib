// Room: /d/yandang/luoyan13.c

inherit ROOM;

void create ()
{
  set ("short", "�鷿");
  set ("long", @LONG
����һ���鷿,�����������ϰ����ķ��ı�,����һ��ûд�����̯
������,��ǽ�������,�����ǽ�Ϲ���һ����,�����һȺ����չ������
��������,�ݽǵ�һֻ��̩¯��ð������.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuan.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luoyan14",
  "north" : __DIR__"luoyan15",
  "south" : __DIR__"luoyan39",
]));

  setup();
}

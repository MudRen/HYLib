// Room: /d/feitian/changlewu.c
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
��֮���ļҾ��������ˣ��������оۼ���һȺ�������µ��ˡ�
��Ҷ���ߺ���Ž����ŶĲ�����������վ��һ�������£�
����ӡ��һ�����ֵ��ˣ��Ǵ�ž�����֮���ˡ�
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zuo.c" : 1,
  __DIR__"npc/dugun.c" : 4,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luorencun",
]));
  setup();
  replace_program(ROOM);
}

// Room: /d/yanjing/tiejiang.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
ǽ�����˸���¯��,Сѧͽ�����������ŷ���.һ��ǽ�����ż��Ѵ�
С��ͬ�Ĵ���,һֻ��ƤͰ��װ�˰�Ͱˮ,������˼�������,��δ����,��
������ʲô.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhang.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"street4",
]));

  setup();
}

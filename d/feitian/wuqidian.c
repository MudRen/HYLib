// Room: /u/diabio/feitian/feitian/wuqidian.c
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
����ʱ�����������ֵ�������,����ά��ʱ�ڹ���ʵ���˷ϵ���.
����Ҳֻ�ù�����,����������һ����Ҳû�о����ĵ�.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiedao2",
]));
  setup();
  replace_program(ROOM);
}

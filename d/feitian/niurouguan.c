// Room: /u/diabio/feitian/feitian/niurouguan.c
inherit ROOM;

void create()
{
  set ("short", "ţ���");
  set ("long", @LONG
����������ӵ�������������������һʱ�ľ���ţ���.��������һƬ
����,�Աߵ��˸�����,��������Ϊ�ϰ���ǣ������糴彣�ĵ�ս��
�����ݻ���.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"beijie",
]));
	set("objects",([
	__DIR__"npc/xiaoyan":1,
]));
  setup();
  replace_program(ROOM);
}

// Room: /u/diabio/feitian/feitian/jingbeisu
inherit ROOM;

void create()
{
  set ("short", "����������");
  set ("long", @LONG
ά����������ľ�����,����������������ʩ��������.����֮��
һƬ��æ,��Ҷ���Ŭ���Ĺ�����.
LONG);

  set("no_clean_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beijie",
]));
  set("no_magic", 1);
  set("no_fight", 1);
	set("objects",([
	__DIR__"npc/shuzhang":1,
	__DIR__"npc/xunbu":3,
	__DIR__"npc/xunjing":3,
]));
  setup();
  replace_program(ROOM);
}

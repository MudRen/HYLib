// Room: /d/yanjing/hualou1.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
��¥�ϱ�һ���λ��ĸ�,�������������,���ۻ���,���Ŵ��Ĳ�Զ��
����С����,һ����δ�깤�Ĺ���ĵ��̯��������,ǽ�Ϲ���֧������.��
������ɽˮ,����ռ����ʣ�µ�ǽ��.
LONG
	);
//	set("objects", ([ /* sizeof() == 1 */
//..  __DIR__"npc/clone/clothbaiyuxiao.c" : 1,
//]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hualou",
]));

	setup();
	replace_program(ROOM);
}

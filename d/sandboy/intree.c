// Room: /d/sandboy/intree.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�ڷ�ï��֦Ҷ��,���ܿ���Զ������ĵ���,������һ��һľ,ͷ������
ȸ�������,������֦Ҷ��Ʈ������.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"undertree",
]));

	setup();
	replace_program(ROOM);
}

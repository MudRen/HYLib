// Room: /d/huizhu/zhangpeng3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ⶥ��ţƤ�������ܾ�û��ɨ�ˣ��ڿ�������Ĳ��֣��кü�����
����ҧ����С����һ������Ƥƴ������̺�Ӱ�����������ģ���ڹ��ŵ�
�����Կ��Űѳ���������˷�����ɫ�����⡣
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huoayi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"buluo2",
]));

	setup();
	replace_program(ROOM);
}

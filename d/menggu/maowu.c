// Room: /d/menggu/maowu.c

inherit ROOM;

void create()
{
	set("short", "Сé��");
	set("long", @LONG
�����ֲڵ�ľͷ����һ������,�������Ƥ����û����.������ԭ����
��é�ݸ�����ľͷ��,������Сé��.�����һ�ж��ǽ���ģʽ,��ľͷ�ݲ�
����Ĵ�,һ���Ǹ�������,һ�ߵ�ǽ�ϻ����˸�С��.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liping.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"caodui",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

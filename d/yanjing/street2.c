// Room: /d/yanjing/street2.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
�ֵ������������������Ƶ���,��������Χ�Ÿ����˵�С�����ּۻ�
��,һ���ƹ�����ֻ�ռ����˹�ȥ,������Ÿ����������Ĵ�����,�ֵ�����
���Ǽҿ�ջ,����Χ��һ��Ȧ��,��֪�ڸ�ʲô.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/person.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"gaosheng",
  "north" : __DIR__"street",
  "south" : __DIR__"street3",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}

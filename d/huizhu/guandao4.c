// Room: /d/huizhu/guandao4.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������Ӿ���������صĹٵ��������Ǿ��Ƿ�������ͨ������
�ء���·�ı�����Ƭ����,һ�ߺ�����Щ����ע����.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"guandao3",
  "northeast" : __DIR__"to_bj",
]));

	setup();
	replace_program(ROOM);
}

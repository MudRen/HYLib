// Room: /d/menggu/menggubao.c

inherit ROOM;

void create()
{
	set("short", "�ɹŰ�");
	set("long", @LONG
�ɹ���������Ϊ��,����ס�ľ�����ëձ����������,ͨ����Ϊ�ɹŰ�.
�����жѷ��˼�������,һ���Ǻ�����,�������׳�������,�����Ǿ����ٲ�
�õ�.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mumin.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"buluo1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

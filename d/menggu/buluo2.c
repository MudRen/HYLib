// Room: /d/menggu/buluo2.c

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
  __DIR__"npc/zhebie.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"buluo",
]));

	setup();
	replace_program(ROOM);
}

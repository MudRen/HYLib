// Room: /d/menggu/menggubao1.c

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
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"buluo1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /d/menggu/buluo1.c

inherit ROOM;

void create()
{
	set("short", "��ľ�沿��");
	set("long", @LONG
��ľ�沿���ǵ����Į��ǿʢ��һ��,����һͳ�ɹ�֮��.�������
����������,�������������ж���������,��ȥ����ԯ��.�������߶�
�ǲ������˾�ס���ɹŰ�.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/menggukid.c" : 2,
]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"menggubao1",
  "west" : __DIR__"menggubao",
  "north" : __DIR__"yuanmen",
  "south" : __DIR__"buluo",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

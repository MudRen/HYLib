// Room: /d/menggu/caoyuan3.c

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
Į������Ƭ��ԭ,����ƶ�,ֻ��������Ϊ��,��������Ƭ�����ϵ�
�ɹŸ�������֮��Ϊ����ţ��,ū��,����,�Ʋ���������ɱ,��ľ�����
������ǿʢ��һ������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/heijiu.c" : 2,
]));
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"caoyuan2",
  "east" : __DIR__"river",
  "south" : __DIR__"mobei",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

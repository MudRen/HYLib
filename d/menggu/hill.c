// Room: /d/menggu/hill.c

inherit ROOM;

void create()
{
	set("short", "С��ɽ");
	set("long", @LONG
ֻ�����������һ������,ȴ����Ƭ�������ߵ�һ��,�����ϱ�����
�ޱߵ��ɹŲ�ԭ,Χ��������ĳ��˼���С·��,���ǵͰ��Ĺ�ľ��,����
ɢ����һЩ���ѵļ���,ɭɭ�İ׹Ǻ�һЩ��ȱ�Ĳ���.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guojing.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"guanmu",
]));
	set("outdoors", "menggu");

	setup();
	replace_program(ROOM);
}

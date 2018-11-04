// Room: /d/yandang/luoyan7.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
ת������,���������䳡,���߹���ʱ,���м��������ڰ�ȭŪ��,��
�������ڲ�����ϰ����.�������Ŀ��˱Ƚ϶�,��ʱ���º�,Ҳ���ڴ�¶
����,������Ҷ���ɽׯ����,�ж�ԩһ�㲻���ڴ˽��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"luoyan10",
  "east" : __DIR__"luoyan9",
  "south" : __DIR__"luoyan6",
  "north" : __DIR__"luoyan8",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi.c" : 3,
]));

	setup();
	replace_program(ROOM);
}

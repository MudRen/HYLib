// Room: /d/hainan/cave4.c

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
����ʶ����Ե�һ��С��������,���滳���Լ��ߴ��˵ط�,�����
��ֻ����ǿ����ͨ��,��ת����������,����ʮ�ֺڰ���ʪ,ʱ�л�����
�Ķ������߼���.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"cave3",
  "northeast" : __DIR__"cave5",
]));
	set("objects",([
		__DIR__"npc/man3":1,
	]));
	setup();
	replace_program(ROOM);
}

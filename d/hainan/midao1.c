// Room: /d/hainan/midao1.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
ɽ���е�һ���ܵ�,ʮ�ֶ�б,ͷ����ɽʯ�ƺ���ѹ�����Դ���,����
����ɽʯ����ɵ�ʯ��,��֪����˭��ɽ���п���������ɽ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"midao",
  "northup" : __DIR__"midao2",
]));

	setup();
	replace_program(ROOM);
}

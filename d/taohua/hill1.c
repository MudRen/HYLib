// Room: /u/jpei/thd/hill1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ������һת���۶��򱱾Ϳɵִ�ɽ������Զ������һƬ�һ������дУ�
��һ�����Զ���󺣣���Ŀ���콻�Ӵ����ƺ���Щ��Ӱ�������ƺ��ǻþ���
LONG
	);
	set("exits", ([ 
		"westdown" : __DIR__"hill",
		"northup" : __DIR__"hill2",
	]) );
	set("no_clean_up", 0);
	set("outdoors","�һ���");

	setup();
	replace_program(ROOM);
}

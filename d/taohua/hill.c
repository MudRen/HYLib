// Room: /u/jpei/thd/hill.c

inherit ROOM;

void create()
{
	set("short", "Сɽ");
	set("long", @LONG
һ����ɽͷ����ͷ�����ǰ��Ȼ���ʣ�����ɽ������һ��Ƭ���һ��ԣ���
�ڻ�������Լ¶���˼���ͥԺ�ķ��ܣ��ƺ�����һƬ���ŵĽ������Ǳߡ���
����һ����ȥ��������ɽʱ��ŵ���ʯ�Ѿ����ŵ��ˣ�����Ҳ�ز��������ˡ�
�������߸���һ��Сɽ�壬
LONG
	);
	set("exits", ([ 
		"eastup" : __DIR__"hill1",
		"east" : __DIR__"mudi",
	]) );
	set("no_clean_up", 0);
	set("outdoors","�һ���");

	setup();
	replace_program(ROOM);
}

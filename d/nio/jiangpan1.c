// Room: /u/jpei/thd/jiangpan1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ���󽭺�ب����ǰ����ˮ�ƺƣ�����ҹҹ�������ݵر���󺣡�������
һ���ڰ�����Ҷ���ƻ��հ�졣���ô���������Χ��һ�Ѵ��񣬾۾��������
��һ������������˵����
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"njroad5.c",
		"southeast": __DIR__"jiangpan2.c",
	]) );

	setup();
	replace_program(ROOM);
}


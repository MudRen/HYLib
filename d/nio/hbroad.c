// Room: /u/jpei/thd/hbroad.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ��ͨ�����ߵ���·�����߾��Ǻ��ߵ�С����ˣ���ʱ���Ǳߴ�������
����·�ı�����һ���ϾɵĿ�ջ�����˽��������д��"������ջ"�����֡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"kezhan.c",
		"east": __DIR__"bay.c",
		"southwest": __DIR__"njeast.c",
	]) );

	setup();
	replace_program(ROOM);
}


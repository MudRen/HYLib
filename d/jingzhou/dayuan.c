// Room: dayuan.c
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�״��ʯͷ����˵�ǵ��껨
ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�������һ�û����������дУ��ڸ��˴���
Ժ�ӡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"wanghouse",
		"west" : __DIR__"xting",
		"east" : __DIR__"dting",
		"north" : __DIR__"whouyuan",
	]));

	setup();
	replace_program(ROOM);
}


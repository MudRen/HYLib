inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���ǳǶ���һ����·��·�����ҵĳ�����ϥ�ĻĲݣ�Զ���Ĳݣ�Զ
������һ�ˡ����Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�
Ұ��ԶԶ��ȥ��һ�������ľ���
LONG );
	set("exits", ([
		"southwest" : __DIR__"dongcheng",
		"northeast" : __DIR__"huandi2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "dingxiang");
	setup();
	replace_program(ROOM);
}


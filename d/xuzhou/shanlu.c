inherit ROOM;
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ�����·����ǿ����ͨ��һ���󳵣�����Խ��ǰ�ߵ�·��Խ
խ����ʼ���ܿ���·�ϵĳ���ӡ������ӡ������ֻ�����ߵĺۼ��ˣ���
˵�������������ˡ�	
LONG );
	set("exits", ([
		"west"     : __DIR__"weixian",
		"northeast" : __DIR__"dadao10",
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}


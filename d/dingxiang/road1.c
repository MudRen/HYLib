inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ���������
����������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬
Ϊƽ̹�Ĵ�������˼�����͵����ߡ�·�����˽���ϡ��������
LONG );
	set("exits", ([
		"northwest" : __DIR__"dadao2",
                "northeast" : __DIR__"caoyuan5",
                "north" : __DIR__"caoyuan",
	]));
 	set("outdoors", "dingxiang");
	setup();
	replace_program(ROOM);
}


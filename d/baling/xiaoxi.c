// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ��СϪ");
	set("long", @LONG
��ɽ·���Ա߳�����һ��СϪ����Χ�������ˣ�ֻ��С����ˮ����
�����졣һЩ�ڿʵ�������Ϫ�ߺ�ˮ��Զ��������һЩ������ģ���Ķ�
��Ҳ��Ϫ�����֡�������һ����ɽ��·�������涼�Ǿ����Ͱ��ݹ�ľ��
��������һ���Ữ�����塣
LONG
	);

	set("exits", ([
               "northup" : __DIR__"shanding",
               "southdown" : __DIR__"shanlu3",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}





inherit ROOM;


void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
����һ����·�����������������ӵ����̣����Ŵ󳵵��������
�������ǳ����֡���ʱ����������������߷ɳ۶���������һ·����
��������ͨ�������صĹٵ���
LONG
	);
	
	set("exits", ([
                "northwest" : __DIR__"eroad1",
                "east" : __DIR__"yincheng",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}



inherit ROOM;


void create()
{
	set("short", "�ǿ���");
	set("long", @LONG
����һ����·�����������������ӵ����̣����Ŵ󳵵��������
�������ǳ����֡���ʱ����������������߷ɳ۶���������һ·����
��������ͨ�������صĹٵ���
LONG
	);
	
	set("exits", ([
                "northwest" : __DIR__"eroad3",
                "east" : __DIR__"eroad5",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}

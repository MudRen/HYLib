

inherit ROOM;


void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����·��·���������������ַǷ����������߾͵�����ı�
���ˡ�������ͨ������ͨ�Ĺٵ�������������һ��С��·��
LONG
	);
	
	set("exits", ([
		"north" : __DIR__"anle",
                "south" : __DIR__"beimen",
                "east" : __DIR__"eroad1",
                "northeast" : __DIR__"tulu1",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}

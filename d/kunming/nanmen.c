// nanmen  by netkill

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������������ţ��߸ߵĳ�¥��д�Ŵ���"����"�����֣�
�ɴ���ȥ�����ǰ����ˣ��������ŵ��˺��٣�ֻ��Щ����ʱ��
�����ʵ�����������������������ǿ�����ϣ����ر��ˡ�  
LONG
	);

	set("exits", ([
		"south" : "/d/yanping/gudao1",
		"north" : __DIR__"nandajie2",
		"southwest" : "/d/annan/shulin9",	
		
	]));

	
	setup();
	replace_program(ROOM);
}


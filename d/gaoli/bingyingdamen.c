

inherit ROOM;

void create()
{
	set("short", "��Ӫ����");
	set("long", @LONG
����վ�ڱ�Ӫ���ſڣ������һ�ż�ª��Ӫ�������Կ��������Ʒ�
�Ĺٱ����ڲ�������ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ��ģ���
��û��ǸϿ��߿�Ϊ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"qinglong-1",
		"south" : __DIR__"bingying",
	]));
           set("objects", ([
		"/d/gaoli/npc/bing" : 2,
	]));
 setup();
	replace_program(ROOM);
}	

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǿ��������ڱ���֣�ǰ����Ǳ����ˡ�������һ�Ҿ�¥���ұ�һ����
������Ҳ�в������
LONG );
        set("exits", ([
                "north" : __DIR__"beimen",
		"south" : __DIR__"stbeijie1",
		"west" : __DIR__"xianjialou",
		"east" : __DIR__"dizangmiao",
        	
	]));
	set("outdoors", "����");
	setup();
}
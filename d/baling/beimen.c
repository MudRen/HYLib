// baling/beimen
// Room in ���� 
// laowuwu 99/04/11


inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ��걱���ţ���Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں����ģ����
��ֽ���ֵĹٸ���ʾ���Ե��ر����ۡ�
LONG
	);
	
	set("exits", ([
		"south" : __DIR__"beidajie1",
                "north" : __DIR__"eroad",
	]));
    
	set("outdoors", "qiuci");
         set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}

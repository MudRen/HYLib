// baling/ximen
// Room in ���� 
// laowuwu 99/04/11

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ���
�����Ϸ�����ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����
ʾ���������ﷸ������ȥ�ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס
�������ʡ�һ����ֱ����ʯ���������������졣�����ǽ��⣬����
�ġ����εġ���·�ģ����˴Ҵҡ������ǳ��
LONG
	);
        set("outdoors", "baling");

	
	set("exits", ([
		"east" : __DIR__"xidajie1",
                "west" : __DIR__"edao4",
	]));
        set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}


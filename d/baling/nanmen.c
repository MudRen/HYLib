// baling/nanmen
// Room in ���� 
// laowuwu 99/04/11
// Modify by yang

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ϳ��ţ���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�
�棬�ٸ��ĸ�ʾ��˾Ͳ�̫��Ŀ���ٱ��Ǳ������Ļ���Ц������������
�����Ǻ�������ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"south" : __DIR__"edao6",
		"northeast" : __DIR__"nandajie3",
	]));
     set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}


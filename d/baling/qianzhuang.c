// baling/qianzhuang
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ
�����е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG
	);

	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
        set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	setup();
	replace_program(ROOM);
}


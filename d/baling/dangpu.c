// baling/pomiao
// Room in ���� 
// laowuwu 99/04/11

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ��
��̨�ϰ���һ�����ӡ�paizi������̨�������ϰ壬һ˫�������۾�����
���´������㡣
LONG
	);
    set("no_beg",1);

	set("item_desc", ([
		"paizi" : "��ƽ����\n",
	]));
	
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
	set("objects",([
	   __DIR__"npc/meng":1,
	   ]));

	setup();
	replace_program(ROOM);
}


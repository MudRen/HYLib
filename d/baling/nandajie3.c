// baling/nandajie3
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ�ϱ���
���ǰ�����ϲ���������һ�������̣���ʱ�ش�������ײײ�������ϱ�
�����š�
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
                "southwest" : __DIR__"nanmen",
                "north" : __DIR__"bingqipu",
                "east" : __DIR__"nandajie2",
	]));

      

	setup();
}



// baling/dongmen
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š�����������֣���ǽ������
���Źٸ���ʾ���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ��
��ֱ����ʯ���������������졣�����ǽ��⣬��Լ�ɼ�һƬһ����
�ʵ����֣�����Ī�⡣�����ǳ��
LONG
	);
        set("outdoors", "qiuci");


	set("exits", ([
		"west" : __DIR__"dongdajie1",
                "east" : __DIR__"edao1",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}


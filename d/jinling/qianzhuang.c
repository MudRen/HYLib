// inn.c

inherit ROOM;


void create()
{
	set("short", "�¼�Ǯׯ");
	set("long", @LONG
����ȫ����ģ����һ��Ǯׯ����ȫ�����ض��зֵꡣ�����е���Ʊͨ
��ȫ��Ǯׯ���ſڹ���һ��ܴ�Ľ������ƣ�����"�¼�Ǯׯ"�������Ĵ���
�������Ĺ�̨������ɨ�ĸɸɾ�������̨�󼸸��˷�������С�������æ��
��ͷ�ö��̨�Ϸ���һ������(sign)�������Ŵ�ҡ�
LONG
	);
	set("exits", ([
		"west"    	: __DIR__"beijie1",
	]) );
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
TEXT
        ]) );


	set("objects", ([
		__DIR__"npc/banker" : 1,

			]) );


	setup();
}

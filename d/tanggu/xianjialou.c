inherit ROOM;
void create()
{
        set("short", "�ɼ�¥");
        set("long", @LONG
����һ�������ľ�¥��ƽ��������������������ʱ��ʼ����һ�ۡ�С��
��¥��¥��æ�Ĳ����ֺ�������̸���໥���ڣ�һ��ʤ������
LONG );
        set("exits", ([
                "east" : __DIR__"stbeijie2",
	]));
        set("objects", ([
                __DIR__"npc/huoji" : 1,
        ]));
	
	setup();
}

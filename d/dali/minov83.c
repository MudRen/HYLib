//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�����ڴ���ɽ���һ����·�ϡ��˼�����������ڣ��������ߣ�
��ɽ����Խ�ƽ��������ɼ���ѩ��������ظ�ԭȺɽ������һ·��
Խɽ��ֱͨ�����ϴ�������ɽ����Щ�����˵Ĵ��䡣
LONG
        );

	set("exits", ([
		"northup" : __DIR__"minov81",
		"south" : __DIR__"minov88",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}

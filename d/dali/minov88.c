//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ǲ�ɽ��´��һ�����ĳ��򡣴˵�����ɽ�ڣ����߳�ɽ����
������������·���У�Ψ�д���������ɽ������Ǵ������������
����Ҫ�壬������ڴ����е�¥����������פ�����йٱ������վ��
Ѳ�ߣ��̲�������ˡ�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov83",
		"south" : __DIR__"minov89",
		]));

	set("objects", ([
		__DIR__"npc/dalishibing" : 3,
		__DIR__"npc/wujiang" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}

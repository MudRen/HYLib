//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��Ū��");
	set("long", @LONG
�˴��ѵ�����ı����������ɵ�����θ������������ģ�����
����ڸ�ɽ�ϡ�����������ɽ֮�������ٲ�����ӿ�Ĵ�ɺӡ���İ��
��ɽʯ�ݳɣ������࣬����ȫ�ǡ��˳ǲ�������ɽ�Ϸֲ���Щ����
��ӣ������˸���ţ���������
LONG
        );

	set("exits", ([
		"northdown" : __DIR__"minov82",
		"southdown" : __DIR__"minov83",
		"east" : __DIR__"minov84",
		]));

	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}

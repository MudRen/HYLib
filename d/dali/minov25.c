//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ɣ��");
	set("long", @LONG
һ��Ƭɣ���������ڵ�ɽ�Ļ���ɽ���ϡ����ϡ���˿�ǰ������
��Ҫ��ҵ�����ĸ�Ů����֯˿����֯�Լ����ŵĶ�ȹ��Ҳ��������
"�����佻��Щ������Ʒ��һȺ���Ĺ��������ּ�æ�Ų�ժɣҶ��
LONG
        );

	set("exits", ([
		"northdown" : __DIR__"minov21",
		]));

	set("objects", ([
		__DIR__"npc/bycaisang.c" : 3,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}

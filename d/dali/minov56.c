//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ɽ����");
	set("long", @LONG
����ɽ�ϵ����ն�����������������������̡��ش���ɽ��
���Ժ����ܻ�������ʱ����û��ֻ���¸ҵ����˲Ÿ���������������
��ɽ������ˮ�ȵء�
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov53",
		]));

	set("objects", ([
		__DIR__"npc/laohu" : 1
		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}

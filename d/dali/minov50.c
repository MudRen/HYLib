//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ˮ�ӹ�");
	set("long", @LONG
������һ��Ƭ�ӹȴ��ڱ���ѩɽ�͸���ɽ֮�䣬�ɶ���ˮ��ˢ��
�ɣ����Ƶ��ݣ�����������ů���۾��˴����������ˡ�����������
�ӹȿ�����һЩ�������ɽ�����ܣ����Ӷ�������ԡ����Ž��µ�
����ֱ��һ�������ӡ�
LONG
        );

	set("exits", ([
		"westdown" : __DIR__"minov41",
		"eastup" : __DIR__"minov49",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}

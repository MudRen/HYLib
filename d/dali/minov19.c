//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�س�С·");
	set("long", @LONG
����һ�����ŵ���ϰ���С·������а������Ϯ�ˡ�Զ�����
���棬�̲�����������Ϸˮ��ңң�ɼ��δ����洬�ᷫ���ơ��˵���
�˼��ɾ�����·����ֱ�ϵ��������Ⱥɽ��
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov12",
		"westup" : __DIR__"minov20",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}

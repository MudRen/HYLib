//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ι�������ˮ֮�ϰٶ�ߵĿ��С�����һ����������
��֮���ţ������ִ��������һ������Ʒ�����Σ��Ų�����һ������
��������������Ԯ�����������գ�ʵ���ϵ�Ҳ��ʮ�����ѡ�һ��ɽ��
Ю�Ž��¼����ɽ���ˮ����������е�һ���⡣
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov93",
		"east" : __DIR__"minov91",
		]));

	set("outdoors","dali");
	set("cost", 50);
	setup();
}
